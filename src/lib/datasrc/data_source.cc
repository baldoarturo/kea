// Copyright (C) 2010  Internet Systems Consortium, Inc. ("ISC")
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

// $Id$

#include "config.h"

#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include <dns/base32.h>
#include <dns/buffer.h>
#include <dns/message.h>
#include <dns/name.h>
#include <dns/rdataclass.h>
#include <dns/rrset.h>
#include <dns/rrsetlist.h>
#include <dns/sha1.h>

#include <cc/data.h>

#include "data_source.h"
#include "query.h"

#define RETERR(x) do { \
                      DataSrc::Result r = (x); \
                      if (r != DataSrc::SUCCESS) \
                          return (r); \
                      } while (0)

using namespace std;
using namespace isc::dns;
using namespace isc::dns::rdata;

namespace isc {
namespace datasrc {

typedef boost::shared_ptr<const Nsec3Param> ConstNsec3ParamPtr;

namespace {
// Add a task to the query task queue to look up additional data
// (i.e., address records for the names included in NS or MX records)
void
getAdditional(Query& q, ConstRRsetPtr rrset) {
    if (!q.wantAdditional()) {
        return;
    }

    RdataIteratorPtr it = rrset->getRdataIterator();
    for (it->first(); !it->isLast(); it->next()) {
        const Rdata& rd(it->getCurrent());
        if (rrset->getType() == RRType::NS()) {
            const generic::NS& ns = dynamic_cast<const generic::NS&>(rd);
            q.tasks().push(QueryTaskPtr(
                               new QueryTask(ns.getNSName(), q.qclass(),
                                             Section::ADDITIONAL(),
                                             QueryTask::GLUE_QUERY,
                                             QueryTask::GETADDITIONAL))); 
        } else if (rrset->getType() == RRType::MX()) {
            const generic::MX& mx = dynamic_cast<const generic::MX&>(rd);
            q.tasks().push(QueryTaskPtr(
                               new QueryTask(mx.getMXName(), q.qclass(),
                                             Section::ADDITIONAL(),
                                             QueryTask::NOGLUE_QUERY,
                                             QueryTask::GETADDITIONAL))); 
        }
    }
}

// Synthesize a CNAME answer, for the benefit of clients that don't
// understand DNAME
void
synthesizeCname(QueryTaskPtr task, RRsetPtr rrset, RRsetList& target) {
    RdataIteratorPtr it = rrset->getRdataIterator();

    // More than one DNAME RR in the RRset is illegal, so we only have
    // to process the first one.
    it->first();
    if (it->isLast()) {
        return;
    }

    const Rdata& rd(it->getCurrent());
    const generic::DNAME& dname = dynamic_cast<const generic::DNAME&>(rd);
    const Name& dname_target(dname.getDname());

    RRsetPtr cname(new RRset(task->qname, task->qclass, RRType::CNAME(),
                             rrset->getTTL()));

    const int qnlen = task->qname.getLabelCount();
    const int dnlen = rrset->getName().getLabelCount();
    assert(qnlen > dnlen);
    const Name& prefix(task->qname.split(0, qnlen - dnlen));
    cname->addRdata(generic::CNAME(prefix.concatenate(dname_target)));

    target.addRRset(cname);
}

// Add a task to the query task queue to look up the data pointed
// to by a CNAME record
void
chaseCname(Query& q, QueryTaskPtr task, RRsetPtr rrset) {
    RdataIteratorPtr it = rrset->getRdataIterator();

    // More than one CNAME RR in the RRset is illegal, so we only have
    // to process the first one.
    it->first();
    if (it->isLast()) {
        return;
    }

    if (q.tooMany()) {
        return;
    }

    q.tasks().push(QueryTaskPtr(
                       new QueryTask(dynamic_cast<const generic::CNAME&>
                                     (it->getCurrent()).getCname(),
                                     task->qclass,
                                     task->qtype,
                                     Section::ANSWER(),
                                     QueryTask::FOLLOWCNAME)));
}

// Perform the query specified in a QueryTask object
DataSrc::Result
doQueryTask(const DataSrc* ds, const Name* zonename, QueryTask& task,
            RRsetList& target)
{
    switch (task.op) {
    case QueryTask::AUTH_QUERY:
        return (ds->findRRset(task.qname, task.qclass, task.qtype,
                              target, task.flags, zonename));

    case QueryTask::SIMPLE_QUERY:
        return (ds->findExactRRset(task.qname, task.qclass, task.qtype,
                                   target, task.flags, zonename));

    case QueryTask::GLUE_QUERY:
    case QueryTask::NOGLUE_QUERY:
        return (ds->findAddrs(task.qname, task.qclass, target,
                              task.flags, zonename));

    case QueryTask::REF_QUERY:
        return (ds->findReferral(task.qname, task.qclass, target,
                                 task.flags, zonename));
    }

    // Not reached
    return (DataSrc::ERROR);
}

// Copy referral information into the authority section of a message
inline void
copyAuth(Query& q, RRsetList& auth) {
    BOOST_FOREACH(RRsetPtr rrset, auth) {
        if (rrset->getType() == RRType::DNAME()) {
            continue;
        }
        if (rrset->getType() == RRType::DS() && !q.wantDnssec()) {
            continue;
        }
        q.message().addRRset(Section::AUTHORITY(), rrset, q.wantDnssec());
        getAdditional(q, rrset);
    }
}

// Query for referrals (i.e., NS/DS or DNAME) at a given name
inline bool
refQuery(const Name& name, const RRClass& qclass, const DataSrc* ds,
         const Name* zonename, RRsetList& target)
{
    QueryTask newtask(name, qclass, QueryTask::REF_QUERY);

    if (doQueryTask(ds, zonename, newtask, target) != DataSrc::SUCCESS) {
        // Lookup failed
        return (false);
    }

    // Referral bit is expected, so clear it when checking flags
    if ((newtask.flags & ~DataSrc::REFERRAL) != 0) {
        return (false);
    }

    return (true);
}

// Match downward, from the zone apex to the query name, looking for
// referrals.  Note that we exclude the apex name and query name themselves;
// they'll be handled in a normal lookup in the zone.
inline bool
hasDelegation(const DataSrc* ds, const Name* zonename, Query& q,
              QueryTaskPtr task)
{
    const int diff = task->qname.getLabelCount() - zonename->getLabelCount();
    if (diff > 1) {
        bool found = false;
        RRsetList ref;
        for (int i = diff - 1; i > 0; --i) {
            const Name sub(task->qname.split(i));
            if (refQuery(sub, q.qclass(), ds, zonename, ref)) {
                found = true;
                break;
            }
        }

        // Found a referral while getting additional data
        // for something other than NS; we skip it.
        if (found && task->op == QueryTask::NOGLUE_QUERY) {
            return (true);
        }

        // Found a referral while getting answer data;
        // send a delegation.
        if (found) {
            RRsetPtr r = ref.findRRset(RRType::DNAME(), q.qclass());
            if (r != NULL) {
                RRsetList syn;
                q.message().addRRset(Section::ANSWER(), r, q.wantDnssec());
                q.message().setHeaderFlag(MessageFlag::AA());
                synthesizeCname(task, r, syn);
                if (syn.size() == 1) {
                    q.message().addRRset(Section::ANSWER(),
                                         syn.findRRset(RRType::CNAME(),
                                                       q.qclass()),
                                         q.wantDnssec());
                    chaseCname(q, task, syn.findRRset(RRType::CNAME(),
                                                      q.qclass()));
                    return (true);
                }
            }

            copyAuth(q, ref);
            return (true);
        }
    }

    // We appear to have authoritative data; set the header
    // flag.  (We may clear it later if we find a referral
    // at the actual qname node.)
    if (task->op == QueryTask::AUTH_QUERY &&
        task->state == QueryTask::GETANSWER) {
        q.message().setHeaderFlag(MessageFlag::AA());
    }

    return (false);
}

inline DataSrc::Result
addSOA(Query& q, const Name* zonename, const DataSrc* ds) {
    Message& m = q.message();
    RRsetList soa;

    QueryTask newtask(*zonename, q.qclass(), RRType::SOA(),
                      QueryTask::SIMPLE_QUERY);
    RETERR(doQueryTask(ds, zonename, newtask, soa));
    if (newtask.flags != 0) {
        return (DataSrc::ERROR);
    }

    m.addRRset(Section::AUTHORITY(), soa.findRRset(RRType::SOA(), q.qclass()),
               q.wantDnssec());
    return (DataSrc::SUCCESS);
}

inline DataSrc::Result
addNSEC(Query& q, const QueryTaskPtr task, const Name& name,
        const Name& zonename, const DataSrc* ds)
{
    RRsetList nsec;
    Message& m = q.message();

    QueryTask newtask(name, task->qclass, RRType::NSEC(),
                      QueryTask::SIMPLE_QUERY); 
    RETERR(doQueryTask(ds, &zonename, newtask, nsec));
    if (newtask.flags == 0) {
        m.addRRset(Section::AUTHORITY(), nsec.findRRset(RRType::NSEC(),
                                                        q.qclass()), true);
    }

    return (DataSrc::SUCCESS);
}

inline DataSrc::Result
getNsec3(const DataSrc* ds, const Name& zonename, const RRClass& qclass,
         string& hash, RRsetPtr& target)
{
    RRsetList rl;
    RETERR(ds->findCoveringNSEC3(zonename, hash, rl));
    target = rl.findRRset(RRType::NSEC3(), qclass);
    return (DataSrc::SUCCESS);
}

ConstNsec3ParamPtr
getNsec3Param(Query& q, const DataSrc* ds, const Name& zonename) {
    DataSrc::Result result;
    RRsetList nsec3param;

    QueryTask newtask(zonename, q.qclass(), RRType::NSEC3PARAM(),
                      QueryTask::SIMPLE_QUERY); 
    result = doQueryTask(ds, &zonename, newtask, nsec3param);
    newtask.flags &= ~DataSrc::REFERRAL;
    if (result != DataSrc::SUCCESS || newtask.flags != 0) {
        return (ConstNsec3ParamPtr());
    }

    RRsetPtr rrset = nsec3param.findRRset(RRType::NSEC3PARAM(), q.qclass());
    if (!rrset) {
        return (ConstNsec3ParamPtr());
    }

    // XXX: currently only one NSEC3 chain per zone is supported;
    // we will need to revisit this.
    RdataIteratorPtr it = rrset->getRdataIterator();
    it->first();
    if (it->isLast()) {
        return (ConstNsec3ParamPtr());
    }

    const generic::NSEC3PARAM& np =
            dynamic_cast<const generic::NSEC3PARAM&>(it->getCurrent());
    return (ConstNsec3ParamPtr(new Nsec3Param(np.getHashalg(), np.getFlags(),
                                              np.getIterations(),
                                              np.getSalt())));
}

inline DataSrc::Result
proveNX(Query& q, QueryTaskPtr task, const DataSrc* ds,
        const Name& zonename, const bool wildcard)
{
    Message& m = q.message();
    ConstNsec3ParamPtr nsec3 = getNsec3Param(q, ds, zonename);
    if (nsec3 != NULL) {
        // Attach the NSEC3 record covering the QNAME
        RRsetPtr rrset;
        string hash1(nsec3->getHash(task->qname));
        RETERR(getNsec3(ds, zonename, q.qclass(), hash1, rrset));
        m.addRRset(Section::AUTHORITY(), rrset, true);

        // If this is an NXRRSET or NOERROR/NODATA, we're done
        if ((task->flags & DataSrc::TYPE_NOT_FOUND) != 0) {
            return (DataSrc::SUCCESS);
        }

        // Find the closest provable enclosing name for QNAME
        Name enclosure(zonename);
        const int diff = task->qname.getLabelCount() -
            enclosure.getLabelCount();
        string hash2;
        for (int i = 1; i <= diff; ++i) {
            enclosure = task->qname.split(i);
            string nodehash(nsec3->getHash(enclosure));
            if (nodehash == hash1) {
                break;
            }
            hash2 = nodehash;
            RRsetList rl;

            // hash2 will be overwritten with the actual hash found;
            // we don't want to use one until we find an exact match
            RETERR(getNsec3(ds, zonename, q.qclass(), hash2, rrset));
            if (hash2 == nodehash) {
                m.addRRset(Section::AUTHORITY(), rrset, true);
                break;
            }
        }

        // If we are processing a wildcard answer, we're done.
        if (wildcard) {
            return (DataSrc::SUCCESS);
        }

        // Otherwise, there is no wildcard record, so we must add a
        // covering NSEC3 to prove that it doesn't exist.
        string hash3(nsec3->getHash(Name("*").concatenate(enclosure)));
        RETERR(getNsec3(ds, zonename, q.qclass(), hash3, rrset));
        if (hash3 != hash1 && hash3 != hash2) {
            m.addRRset(Section::AUTHORITY(), rrset, true);
        }
    } else {
        Name nsecname(task->qname);
        if ((task->flags & DataSrc::NAME_NOT_FOUND) != 0 || wildcard) {
            ds->findPreviousName(task->qname, nsecname, &zonename);
        }

        RETERR(addNSEC(q, task, nsecname, zonename, ds));
        if ((task->flags & DataSrc::TYPE_NOT_FOUND) != 0 ||
            nsecname == zonename)
        {
            return (DataSrc::SUCCESS);
        }

        // If we are processing a wildcard answer, we're done.
        if (wildcard) {
            return (DataSrc::SUCCESS);
        }

        // Otherwise, there is no wildcard record, so we must add an
        // NSEC for the zone to prove the wildcard doesn't exist.
        RETERR(addNSEC(q, task, zonename, zonename, ds));
    }

    return (DataSrc::SUCCESS);
}

// Attempt a wildcard lookup
inline DataSrc::Result
tryWildcard(Query& q, QueryTaskPtr task, const DataSrc* ds,
            const Name* zonename, bool& found)
{
    Message& m = q.message();
    DataSrc::Result result;
    found = false;

    if ((task->flags & DataSrc::NAME_NOT_FOUND) == 0 || 
        (task->state != QueryTask::GETANSWER &&
         task->state != QueryTask::FOLLOWCNAME)) {
        return (DataSrc::SUCCESS);
    }

    const int diff = task->qname.getLabelCount() - zonename->getLabelCount();
    if (diff < 1) {
        return (DataSrc::SUCCESS);
    }

    RRsetList wild;
    const Name star("*");
    bool cname = false;

    for (int i = 1; i <= diff; ++i) {
        const Name& wname(star.concatenate(task->qname.split(i)));
        QueryTask newtask(wname, task->qclass, task->qtype, Section::ANSWER(),
                          QueryTask::AUTH_QUERY); 
        result = doQueryTask(ds, zonename, newtask, wild);
        if (result == DataSrc::SUCCESS) {
            if (newtask.flags == 0) {
                task->flags &= ~DataSrc::NAME_NOT_FOUND;
                task->flags &= ~DataSrc::TYPE_NOT_FOUND;
                found = true;
                break;
            } else if ((newtask.flags & DataSrc::CNAME_FOUND) != 0) {
                task->flags &= ~DataSrc::NAME_NOT_FOUND;
                task->flags &= ~DataSrc::TYPE_NOT_FOUND;
                task->flags |= DataSrc::CNAME_FOUND;
                found = true;
                cname = true;
                break;
            } else if ((newtask.flags & DataSrc::TYPE_NOT_FOUND) != 0) {
                task->flags &= ~DataSrc::NAME_NOT_FOUND;
                task->flags |= DataSrc::TYPE_NOT_FOUND;
                break;
            }
        }
    }

    // A wildcard was found.
    if (found) {
        // Prove the nonexistence of the name we were looking for
        if (q.wantDnssec()) {
            result = proveNX(q, task, ds, *zonename, true);
            if (result != DataSrc::SUCCESS) {
                m.setRcode(Rcode::SERVFAIL());
                return (DataSrc::ERROR);
            }
        }

        // Add the data to the answer section (but with the name changed to
        // match the qname), and then continue as if this were a normal
        // answer: if a CNAME, chase the target, otherwise add authority.
        if (cname) {
            RRsetPtr rrset = wild.findRRset(RRType::CNAME(), q.qclass());
            if (rrset != NULL) {
                rrset->setName(task->qname);
                m.addRRset(Section::ANSWER(), rrset, q.wantDnssec());
                chaseCname(q, task, rrset);
            }
        } else {
            BOOST_FOREACH (RRsetPtr rrset, wild) {
                rrset->setName(task->qname);
                m.addRRset(Section::ANSWER(), rrset, q.wantDnssec());
            }

            RRsetList auth;
            if (!refQuery(*zonename, q.qclass(), ds, zonename, auth)) {
                return (DataSrc::ERROR);
            }

            copyAuth(q, auth);
        }
    }

    return (DataSrc::SUCCESS);
}
} // end of anonymous namespace

//
// doQuery: Processes a query.
// 
void
DataSrc::doQuery(Query& q) {
    Message& m = q.message();
    vector<RRsetPtr> additional;

    m.clearHeaderFlag(MessageFlag::AA());
    while (!q.tasks().empty()) {
        QueryTaskPtr task = q.tasks().front();
        q.tasks().pop();

        // Can't query directly for RRSIG.
        if (task->qtype == RRType::RRSIG()) {
            m.setRcode(Rcode::REFUSED());
            return;
        }

        // These task types should never be on the task queue.
        if (task->op == QueryTask::SIMPLE_QUERY ||
            task->op == QueryTask::REF_QUERY) {
            m.setRcode(Rcode::SERVFAIL());
            return;
        }

        // Find the closest enclosing zone for which we are authoritative,
        // and the concrete data source which is authoritative for it.
        // (Note that RRtype DS queries need to go to the parent.)
        const int nlabels = task->qname.getLabelCount() - 1;
        NameMatch match(nlabels != 0 && task->qtype == RRType::DS() ?
                        task->qname.split(1) : task->qname);
        findClosestEnclosure(match, task->qclass);
        const DataSrc* datasource = match.bestDataSrc();
        const Name* zonename = match.closestName();

        assert((datasource == NULL && zonename == NULL) ||
               (datasource != NULL && zonename != NULL));

        RRsetList data;
        Result result = SUCCESS;

        if (datasource) {
            // For these query task types, if there is more than
            // one level between the zone name and qname, we need to
            // check the intermediate nodes for referrals.
            if ((task->op == QueryTask::AUTH_QUERY ||
                 task->op == QueryTask::NOGLUE_QUERY) &&
                hasDelegation(datasource, zonename, q, task)) {
                continue;
            }

            result = doQueryTask(datasource, zonename, *task, data);
            if (result != SUCCESS) {
                m.setRcode(Rcode::SERVFAIL());
                return;
            }

            // Query found a referral; let's find out if that was expected--
            // i.e., if an NS was at the zone apex, or if we were querying
            // specifically for, and found, a DS, NSEC, or DNAME record.
            if ((task->flags & REFERRAL) != 0 &&
                (zonename->getLabelCount() == task->qname.getLabelCount() ||
                 ((task->qtype == RRType::NSEC() ||
                   task->qtype == RRType::DS() ||
                   task->qtype == RRType::DNAME()) &&
                  data.findRRset(task->qtype, task->qclass)))) {
                task->flags &= ~REFERRAL;
            }
        } else {
            task->flags = NO_SUCH_ZONE;

            // No such zone.  If we're chasing cnames or adding additional
            // data, that's okay, but if doing an original query, return
            // REFUSED.
            if (task->state == QueryTask::GETANSWER) {
                m.setRcode(Rcode::REFUSED());
                return;
            }
            continue;
        }

        if (result == SUCCESS && task->flags == 0) {
            bool have_ns = false, need_auth = false;
            switch (task->state) {
            case QueryTask::GETANSWER:
            case QueryTask::FOLLOWCNAME:
                BOOST_FOREACH(RRsetPtr rrset, data) {
                    m.addRRset(task->section, rrset, q.wantDnssec());
                    if (q.tasks().empty()) {
                        need_auth = true;
                    }
                    getAdditional(q, rrset);
                    if (rrset->getType() == RRType::NS()) {
                        have_ns = true;
                    }
                }
                q.setStatus(Query::ANSWERED);
                if (need_auth && !have_ns) {
                    // Data found, no additional processing needed.
                    // Add the NS records for the enclosing zone to
                    // the authority section.
                    RRsetList auth;
                    if (!refQuery(*zonename, q.qclass(), datasource, zonename,
                                  auth) ||
                        !auth.findRRset(RRType::NS(),
                                        datasource->getClass())) {
                        isc_throw(DataSourceError,
                                  "NS RR not found in " << *zonename << "/" <<
                                  datasource->getClass());
                    }

                    copyAuth(q, auth);
                }
                continue;

            case QueryTask::GETADDITIONAL:
                // Got additional data.  Do not add it to the message
                // yet; instead store it and copy it in at the end
                // (this allow RRSIGs to be omitted if necessary).
                BOOST_FOREACH(RRsetPtr rrset, data) {
                    if (q.status() == Query::ANSWERED &&
                        rrset->getName() == q.qname() &&
                        rrset->getType() == q.qtype()) {
                        continue;
                    }
                    additional.push_back(rrset);
                }
                continue;

            default:
                isc_throw (Unexpected, "unexpected query state");
            }
        } else if (result == ERROR || result == NOT_IMPLEMENTED) {
            m.setRcode(Rcode::SERVFAIL());
            return;
        } else if ((task->flags & CNAME_FOUND) != 0) {
            // The qname node contains a CNAME.  Add a new task to the
            // queue to look up its target.
            RRsetPtr rrset = data.findRRset(RRType::CNAME(), q.qclass());
            if (rrset != NULL) {
                m.addRRset(task->section, rrset, q.wantDnssec());
                chaseCname(q, task, rrset);
            }
            continue;
        } else if ((task->flags & REFERRAL) != 0) {
            // The qname node contains an out-of-zone referral.
            if (task->state == QueryTask::GETANSWER) {
                RRsetList auth;
                m.clearHeaderFlag(MessageFlag::AA());
                if (!refQuery(task->qname, q.qclass(), datasource, zonename,
                              auth)) {
                    m.setRcode(Rcode::SERVFAIL());
                    return;
                }
                BOOST_FOREACH (RRsetPtr rrset, auth) {
                    if (rrset->getType() == RRType::NS()) {
                        m.addRRset(Section::AUTHORITY(), rrset, q.wantDnssec());
                    } else if (rrset->getType() == task->qtype) {
                        m.addRRset(Section::ANSWER(), rrset, q.wantDnssec());
                    } else if (rrset->getType() == RRType::DS() &&
                               q.wantDnssec()) {
                        m.addRRset(Section::AUTHORITY(), rrset, true);
                    }
                    getAdditional(q, rrset);
                }
            } 
            continue;
        } else if ((task->flags & (NAME_NOT_FOUND|TYPE_NOT_FOUND)) != 0) {
            // No data found at this qname/qtype.
            // If we were looking for answer data, not additional,
            // and the name was not found, we need to find out whether
            // there are any relevant wildcards.
            bool wildcard_found = false;
            result = tryWildcard(q, task, datasource, zonename, wildcard_found);
            if (result != SUCCESS) {
                m.setRcode(Rcode::SERVFAIL());
                return;
            }

            if (wildcard_found) {
                continue;
            }

            // If we've reached this point, there is definitely no answer.
            // If we were chasing cnames or adding additional data, that's
            // okay, but if we were doing an original query, reply with the
            // SOA in the authority section.  For NAME_NOT_FOUND, set
            // NXDOMAIN, and also add the previous NSEC to the authority
            // section.  For TYPE_NOT_FOUND, do not set an error rcode,
            // and send the current NSEC in the authority section.
            if (task->state == QueryTask::GETANSWER) {
                if ((task->flags & NAME_NOT_FOUND) != 0) {
                    m.setRcode(Rcode::NXDOMAIN());
                }

                result = addSOA(q, zonename, datasource);
                if (result != SUCCESS) {
                    isc_throw(DataSourceError,
                              "SOA RR not found in" << *zonename <<
                              "/" << datasource->getClass());
                }
            }

            Name nsecname(task->qname);
            if ((task->flags & NAME_NOT_FOUND) != 0) {
                datasource->findPreviousName(task->qname, nsecname, zonename);
            }

            if (q.wantDnssec()) {
                result = proveNX(q, task, datasource, *zonename, false);
                if (result != DataSrc::SUCCESS) {
                    m.setRcode(Rcode::SERVFAIL());
                    return;
                }
            }

            return;
        } else {
            // Should never be reached!
            m.setRcode(Rcode::SERVFAIL());
            return;
        }
    }

    // We're done, so now copy in the additional data:
    // data first, then signatures.  (If we run out of
    // space, signatures in additional section are
    // optional.)
    BOOST_FOREACH(RRsetPtr rrset, additional) {
        m.addRRset(Section::ADDITIONAL(), rrset, false);
    }

    if (q.wantDnssec()) {
        BOOST_FOREACH(RRsetPtr rrset, additional) {
            if (rrset->getRRsig()) {
                m.addRRset(Section::ADDITIONAL(), rrset->getRRsig(), false);
            }
        }
    }
}

DataSrc::Result
DataSrc::findAddrs(const Name& qname, const RRClass& qclass,
                   RRsetList& target, uint32_t& flags,
                   const Name* zonename) const
{
    Result r;
    bool a = false, aaaa = false;

    flags = 0;
    r = findExactRRset(qname, qclass, RRType::A(), target, flags, zonename);
    if (r == SUCCESS && flags == 0) {
        a = true;
    }

    flags = 0;
    r = findExactRRset(qname, qclass, RRType::AAAA(), target, flags,
                       zonename);
    if (r == SUCCESS && flags == 0) {
        aaaa = true;
    }

    if (!a && !aaaa) {
        flags = TYPE_NOT_FOUND;
    } else {
        flags = 0;
    }

    return (SUCCESS);
}

DataSrc::Result
DataSrc::findReferral(const Name& qname, const RRClass& qclass,
                      RRsetList& target, uint32_t& flags,
                      const Name* zonename) const
{
    Result r;
    bool ns = false, ds = false, dname = false;

    flags = 0;
    r = findExactRRset(qname, qclass, RRType::NS(), target, flags, zonename);
    if (r == SUCCESS && flags == 0) {
        ns = true;
    } else if ((flags & (NO_SUCH_ZONE|NAME_NOT_FOUND))) {
        return (SUCCESS);
    }

    flags = 0;
    r = findExactRRset(qname, qclass, RRType::DS(), target, flags, zonename);
    if (r == SUCCESS && flags == 0) {
        ds = true;
    } else if ((flags & (NO_SUCH_ZONE|NAME_NOT_FOUND))) {
        return (SUCCESS);
    }

    flags = 0;
    r = findExactRRset(qname, qclass, RRType::DNAME(), target, flags, zonename);
    if (r == SUCCESS && flags == 0) {
        dname = true;
    } else if ((flags & (NO_SUCH_ZONE|NAME_NOT_FOUND))) {
        return (SUCCESS);
    }

    if (!ns && !dname && !ds) {
        flags = TYPE_NOT_FOUND;
    } else {
        flags = 0;
    }

    return (SUCCESS);
}

void
MetaDataSrc::addDataSrc(ConstDataSrcPtr data_src) {
    if (getClass() != RRClass::ANY() && data_src->getClass() != getClass()) {
        isc_throw(Unexpected, "class mismatch");
    }

    data_sources.push_back(data_src);
}

void
MetaDataSrc::removeDataSrc(ConstDataSrcPtr data_src) {
    std::vector<ConstDataSrcPtr>::iterator it, itr;
    for (it = data_sources.begin(); it != data_sources.end(); it++) {
        if (*it == data_src) {
            itr = it;
        }
    }

    data_sources.erase(itr);
}

void
MetaDataSrc::findClosestEnclosure(NameMatch& match, const RRClass& qclass) const
{
    if (getClass() != qclass &&
        getClass() != RRClass::ANY() && qclass != RRClass::ANY()) {
        return;
    }

    BOOST_FOREACH (ConstDataSrcPtr data_src, data_sources) {
        data_src->findClosestEnclosure(match, qclass);
    }
}

NameMatch::~NameMatch() {
    delete closest_name_;
}

void
NameMatch::update(const DataSrc& new_source, const Name& container) {
    if (closest_name_ == NULL) {
        closest_name_ = new Name(container);
        best_source_ = &new_source;
        return;
    }

    if (container.compare(*closest_name_).getRelation() ==
        NameComparisonResult::SUBDOMAIN) {
        const Name* newname = new Name(container);
        delete closest_name_;
        closest_name_ = newname;
        best_source_ = &new_source;
    }
}

Nsec3Param::Nsec3Param(const uint8_t a, const uint8_t f, const uint16_t i,
                       const std::vector<uint8_t>& s) :
    algorithm_(a), flags_(f), iterations_(i), salt_(s)
{}

string
Nsec3Param::getHash(const Name& name) const {
    OutputBuffer buf(0);
    name.toWire(buf);

    uint8_t digest[SHA1_HASHSIZE];
    const uint8_t* input = static_cast<const uint8_t*>(buf.getData());
    size_t inlength = buf.getLength();
    const uint8_t saltlen = salt_.size();

    int n = 0;
    SHA1Context sha;
    do {
        SHA1Reset(&sha);
        SHA1Input(&sha, input, inlength);
        SHA1Input(&sha, &salt_[0], saltlen);
        SHA1Result(&sha, digest);
        input = digest;
        inlength = SHA1_HASHSIZE;
    } while (n++ < iterations_);

    return (encodeBase32(vector<uint8_t>(digest, digest + SHA1_HASHSIZE)));
}

//
// The following methods are effectively empty, and their parameters are
// unused.  To silence compilers that warn unused function parameters,
// we specify a (compiler dependent) special keyword when available.
// It's defined in config.h, and to avoid including this header file from
// installed files we define the methods here.
//
DataSrc::Result
DataSrc::init(const isc::data::ElementPtr config UNUSED_PARAM) {
    return NOT_IMPLEMENTED;
}

DataSrc::Result
MetaDataSrc::findRRset(const isc::dns::Name& qname UNUSED_PARAM,
                       const isc::dns::RRClass& qclass UNUSED_PARAM,
                       const isc::dns::RRType& qtype UNUSED_PARAM,
                       isc::dns::RRsetList& target UNUSED_PARAM,
                       uint32_t& flags UNUSED_PARAM,
                       const isc::dns::Name* zonename UNUSED_PARAM) const
{
    return (NOT_IMPLEMENTED);
}

DataSrc::Result
MetaDataSrc::findExactRRset(const isc::dns::Name& qname UNUSED_PARAM,
                            const isc::dns::RRClass& qclass UNUSED_PARAM,
                            const isc::dns::RRType& qtype UNUSED_PARAM,
                            isc::dns::RRsetList& target UNUSED_PARAM,
                            uint32_t& flags UNUSED_PARAM,
                            const isc::dns::Name* zonename UNUSED_PARAM) const
{
    return (NOT_IMPLEMENTED);
}

DataSrc::Result
MetaDataSrc::findAddrs(const isc::dns::Name& qname UNUSED_PARAM,
                       const isc::dns::RRClass& qclass UNUSED_PARAM,
                       isc::dns::RRsetList& target UNUSED_PARAM,
                       uint32_t& flags UNUSED_PARAM,
                       const isc::dns::Name* zonename UNUSED_PARAM) const
{
    return (NOT_IMPLEMENTED);
}

DataSrc::Result
MetaDataSrc::findReferral(const isc::dns::Name& qname UNUSED_PARAM,
                          const isc::dns::RRClass& qclass UNUSED_PARAM,
                          isc::dns::RRsetList& target UNUSED_PARAM,
                          uint32_t& flags UNUSED_PARAM,
                          const isc::dns::Name* zonename UNUSED_PARAM) const
{
    return (NOT_IMPLEMENTED);
}

DataSrc::Result
MetaDataSrc::findPreviousName(const isc::dns::Name& qname UNUSED_PARAM,
                              isc::dns::Name& target UNUSED_PARAM,
                              const isc::dns::Name* zonename UNUSED_PARAM) const
{
    return (NOT_IMPLEMENTED);
}

DataSrc::Result
MetaDataSrc::findCoveringNSEC3(const isc::dns::Name& zonename UNUSED_PARAM,
                               std::string& hash UNUSED_PARAM,
                               isc::dns::RRsetList& target UNUSED_PARAM) const
{
    return (NOT_IMPLEMENTED);
}

}
}
