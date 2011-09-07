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

#ifndef __ZONE_H
#define __ZONE_H 1

#include <dns/rrset.h>
#include <dns/rrsetlist.h>

#include <datasrc/result.h>

namespace isc {
namespace datasrc {

/// \brief The base class for a single authoritative zone
///
/// The \c Zone class is an abstract base class for representing
/// a DNS zone as part of data source.
///
/// At the moment this is provided mainly for making the \c ZoneTable class
/// and the authoritative query logic testable, and only provides a minimal
/// set of features.
/// This is why this class is defined in the same header file, but it may
/// have to move to a separate header file when we understand what is
/// necessary for this class for actual operation.
///
/// The idea is to provide a specific derived zone class for each data
/// source, beginning with in memory one.  At that point the derived classes
/// will have more specific features.  For example, they will maintain
/// information about the location of a zone file, whether it's loaded in
/// memory, etc.
///
/// It's not yet clear how the derived zone classes work with various other
/// data sources when we integrate these components, but one possibility is
/// something like this:
/// - If the underlying database such as some variant of SQL doesn't have an
///   explicit representation of zones (as part of public interface), we can
///   probably use a "default" zone class that simply encapsulates the
///   corresponding data source and calls a common "find" like method.
/// - Some data source may want to specialize it by inheritance as an
///   optimization.  For example, in the current schema design of the sqlite3
///   data source, its (derived) zone class would contain the information of
///   the "zone ID".
///
/// <b>Note:</b> Unlike some other abstract base classes we don't name the
/// class beginning with "Abstract".  This is because we want to have
/// commonly used definitions such as \c Result and \c ZoneFinderPtr, and we
/// want to make them look more intuitive.
class ZoneFinder {
public:
    /// Result codes of the \c find() method.
    ///
    /// Note: the codes are tentative.  We may need more, or we may find
    /// some of them unnecessary as we implement more details.
    enum Result {
        SUCCESS,                ///< An exact match is found.
        DELEGATION,             ///< The search encounters a zone cut.
        NXDOMAIN, ///< There is no domain name that matches the search name
        NXRRSET,  ///< There is a matching name but no RRset of the search type
        CNAME,    ///< The search encounters and returns a CNAME RR
        DNAME     ///< The search encounters and returns a DNAME RR
    };

    /// A helper structure to represent the search result of \c find().
    ///
    /// This is a straightforward tuple of the result code and a pointer
    /// to the found RRset to represent the result of \c find()
    /// (there will be more members in the future - see the class
    /// description).
    /// We use this in order to avoid overloading the return value for both
    /// the result code ("success" or "not found") and the found object,
    /// i.e., avoid using \c NULL to mean "not found", etc.
    ///
    /// This is a simple value class whose internal state never changes,
    /// so for convenience we allow the applications to refer to the members
    /// directly.
    ///
    /// Note: we should eventually include a notion of "zone node", which
    /// corresponds to a particular domain name of the zone, so that we can
    /// find RRsets of a different RR type for that name (e.g. for type ANY
    /// query or to include DS RRs with delegation).
    ///
    /// Note: we may also want to include the closest enclosure "node" to
    /// optimize including the NSEC for no-wildcard proof (FWIW NSD does that).
    struct FindResult {
        FindResult(Result param_code,
                   const isc::dns::ConstRRsetPtr param_rrset) :
            code(param_code), rrset(param_rrset)
        {}
        const Result code;
        const isc::dns::ConstRRsetPtr rrset;
    };

    /// Find options.
    ///
    /// The option values are used as a parameter for \c find().
    /// These are values of a bitmask type.  Bitwise operations can be
    /// performed on these values to express compound options.
    enum FindOptions {
        FIND_DEFAULT = 0,       ///< The default options
        FIND_GLUE_OK = 1        ///< Allow search under a zone cut
    };

    ///
    /// \name Constructors and Destructor.
    ///
    //@{
protected:
    /// The default constructor.
    ///
    /// This is intentionally defined as \c protected as this base class should
    /// never be instantiated (except as part of a derived class).
    ZoneFinder() {}
public:
    /// The destructor.
    virtual ~ZoneFinder() {}
    //@}

    ///
    /// \name Getter Methods
    ///
    /// These methods should never throw an exception.
    //@{
    /// Return the origin name of the zone.
    virtual isc::dns::Name getOrigin() const = 0;

    /// Return the RR class of the zone.
    virtual isc::dns::RRClass getClass() const = 0;
    //@}

    ///
    /// \name Search Method
    ///
    //@{
    /// Search the zone for a given pair of domain name and RR type.
    ///
    /// Each derived version of this method searches the underlying backend
    /// for the data that best matches the given name and type.
    /// This method is expected to be "intelligent", and identifies the
    /// best possible answer for the search key.  Specifically,
    /// - If the search name belongs under a zone cut, it returns the code
    ///   of \c DELEGATION and the NS RRset at the zone cut.
    /// - If there is no matching name, it returns the code of \c NXDOMAIN,
    ///   and, if DNSSEC is requested, the NSEC RRset that proves the
    ///   non-existence.
    /// - If there is a matching name but no RRset of the search type, it
    ///   returns the code of \c NXRRSET, and, if DNSSEC is required,
    ///   the NSEC RRset for that name.
    /// - If there is a CNAME RR of the searched name but there is no
    ///   RR of the searched type of the name (so this type is different from
    ///   CNAME), it returns the code of \c CNAME and that CNAME RR.
    ///   Note that if the searched RR type is CNAME, it is considered
    ///   a successful match, and the code of \c SUCCESS will be returned.
    /// - If the search name matches a delegation point of DNAME, it returns
    ///   the code of \c DNAME and that DNAME RR.
    /// - If the target isn't NULL, all RRsets under the domain are inserted
    ///   there and SUCCESS (or NXDOMAIN, in case of empty domain) is returned
    ///   instead of normall processing. This is intended to handle ANY query.
    ///   \note: this behavior is controversial as we discussed in
    ///   https://lists.isc.org/pipermail/bind10-dev/2011-January/001918.html
    ///   We should revisit the interface before we heavily rely on it.
    ///
    /// The \c options parameter specifies customized behavior of the search.
    /// Their semantics is as follows:
    /// - \c GLUE_OK Allow search under a zone cut.  By default the search
    ///   will stop once it encounters a zone cut.  If this option is specified
    ///   it remembers information about the highest zone cut and continues
    ///   the search until it finds an exact match for the given name or it
    ///   detects there is no exact match.  If an exact match is found,
    ///   RRsets for that name are searched just like the normal case;
    ///   otherwise, if the search has encountered a zone cut, \c DELEGATION
    ///   with the information of the highest zone cut will be returned.
    ///
    /// A derived version of this method may involve internal resource
    /// allocation, especially for constructing the resulting RRset, and may
    /// throw an exception if it fails.
    /// It throws DuplicateRRset exception if there are duplicate rrsets under
    /// the same domain.
    /// It should not throw other types of exceptions.
    ///
    /// \param name The domain name to be searched for.
    /// \param type The RR type to be searched for.
    /// \param target If target is not NULL, insert all RRs under the domain
    /// into it.
    /// \param options The search options.
    /// \return A \c FindResult object enclosing the search result (see above).
    virtual FindResult find(const isc::dns::Name& name,
                            const isc::dns::RRType& type,
                            isc::dns::RRsetList* target = NULL,
                            const FindOptions options
                            = FIND_DEFAULT) = 0;
    //@}
};

/// \brief A pointer-like type pointing to a \c ZoneFinder object.
typedef boost::shared_ptr<ZoneFinder> ZoneFinderPtr;

/// \brief A pointer-like type pointing to a \c ZoneFinder object.
typedef boost::shared_ptr<const ZoneFinder> ConstZoneFinderPtr;

/// The base class to make updates to a single zone.
///
/// On construction, each derived class object will start a "transaction"
/// for making updates to a specific zone (this means a constructor of
/// a derived class would normally take parameters to identify the zone
/// to be updated).  The underlying realization of a "transaction" will differ
/// for different derived classes; if it uses a general purpose database
/// as a backend, it will involve performing some form of "begin transaction"
/// statement for the database.
///
/// Updates (adding or deleting RRs) are made via \c addRRset() and
/// \c deleteRRset() methods.  Until the \c commit() method is called the
/// changes are local to the updater object.  For example, they won't be
/// visible via a \c ZoneFinder object except the one returned by the
/// updater's own \c getFinder() method.  The \c commit() completes the
/// transaction and makes the changes visible to others.
///
/// This class does not provide an explicit "rollback" interface.  If
/// something wrong or unexpected happens during the updates and the
/// caller wants to cancel the intermediate updates, the caller should
/// simply destruct the updater object without calling \c commit().
/// The destructor is supposed to perform the "rollback" operation,
/// depending on the internal details of the derived class.
///
/// \note This initial implementation provides a quite simple interface of
/// adding and deleting RRs (see the description of the related methods).
/// It may be revisited as we gain more experiences.
class ZoneUpdater {
protected:
    /// The default constructor.
    ///
    /// This is intentionally defined as protected to ensure that this base
    /// class is never instantiated directly.
    ZoneUpdater() {}

public:
    /// The destructor
    ///
    /// Each derived class implementation must ensure that if \c commit()
    /// has not been performed by the time of the call to it, then it
    /// "rollbacks" the updates made via the updater so far.
    virtual ~ZoneUpdater() {}

    /// Return a finder for the zone being updated.
    ///
    /// The returned finder provides the functionalities of \c ZoneFinder
    /// for the zone as updates are made via the updater.  That is, before
    /// making any update, the finder will be able to find all RRsets that
    /// exist in the zone at the time the updater is created.  If RRsets
    /// are added or deleted via \c addRRset() or \c deleteRRset(),
    /// this finder will find the added ones or miss the deleted ones
    /// respectively.
    ///
    /// The finder returned by this method is effective only while the updates
    /// are performed, i.e., from the construction of the corresponding
    /// updater until \c commit() is performed or the updater is destructed
    /// without commit.  The result of a subsequent call to this method (or
    /// the use of the result) after that is undefined.
    ///
    /// \return A reference to a \c ZoneFinder for the updated zone
    virtual ZoneFinder& getFinder() = 0;

    /// Add an RRset to a zone via the updater
    ///
    /// This may be revisited in a future version, but right now the intended
    /// behavior of this method is simple: It "naively" adds the specified
    /// RRset to the zone specified on creation of the updater.
    /// It performs minimum level of validation on the specified RRset:
    /// - Whether the RR class is identical to that for the zone to be updated
    /// - Whether the RRset is not empty, i.e., it has at least one RDATA
    /// - Whether the RRset is not associated with an RRSIG, i.e.,
    ///   whether \c getRRsig() on the RRset returns a NULL pointer.
    ///
    /// and otherwise does not check any oddity.  For example, it doesn't
    /// check whether the owner name of the specified RRset is a subdomain
    /// of the zone's origin; it doesn't care whether or not there is already
    /// an RRset of the same name and RR type in the zone, and if there is,
    /// whether any of the existing RRs have duplicate RDATA with the added
    /// ones.  If these conditions matter the calling application must examine
    /// the existing data beforehand using the \c ZoneFinder returned by
    /// \c getFinder().
    ///
    /// The validation requirement on the associated RRSIG is temporary.
    /// If we find it more reasonable and useful to allow adding a pair of
    /// RRset and its RRSIG RRset as we gain experiences with the interface,
    /// we may remove this restriction.  Until then we explicitly check it
    /// to prevent accidental misuse.
    ///
    /// Conceptually, on successful call to this method, the zone will have
    /// the specified RRset, and if there is already an RRset of the same
    /// name and RR type, these two sets will be "merged".  "Merged" means
    /// that a subsequent call to \c ZoneFinder::find() for the name and type
    /// will result in success and the returned RRset will contain all
    /// previously existing and newly added RDATAs with the TTL being the
    /// minimum of the two RRsets.  The underlying representation of the
    /// "merged" RRsets may vary depending on the characteristic of the
    /// underlying data source.  For example, if it uses a general purpose
    /// database that stores each RR of the same RRset separately, it may
    /// simply be a larger sets of RRs based on both the existing and added
    /// RRsets; the TTLs of the RRs may be different within the database, and
    /// there may even be duplicate RRs in different database rows.  As long
    /// as the RRset returned via \c ZoneFinder::find() conforms to the
    /// concept of "merge", the actual internal representation is up to the
    /// implementation.
    ///
    /// This method must not be called once commit() is performed.  If it
    /// calls after \c commit() the implementation must throw a
    /// \c DataSourceError exception.
    ///
    /// \todo As noted above we may have to revisit the design details as we
    /// gain experiences:
    ///
    /// - we may want to check (and maybe reject) if there is already a
    /// duplicate RR (that has the same RDATA).
    /// - we may want to check (and maybe reject) if there is already an
    /// RRset of the same name and RR type with different TTL
    /// - we may even want to check if there is already any RRset of the
    /// same name and RR type.
    /// - we may want to add an "options" parameter that can control the
    /// above points
    /// - we may want to have this method return a value containing the
    /// information on whether there's a duplicate, etc.
    ///
    /// \exception DataSourceError Called after \c commit(), RRset is invalid
    /// (see above), internal data source error
    /// \exception std::bad_alloc Resource allocation failure
    ///
    /// \param rrset The RRset to be added
    virtual void addRRset(const isc::dns::RRset& rrset) = 0;

    /// Delete an RRset from a zone via the updater
    ///
    /// Like \c addRRset(), the detailed semantics and behavior of this method
    /// may have to be revisited in a future version.  The following are
    /// based on the initial implementation decisions.
    ///
    /// On successful completion of this method, it will remove from the zone
    /// the RRs of the specified owner name and RR type that match one of
    /// the RDATAs of the specified RRset.  There are several points to be
    /// noted:
    /// - Existing RRs that don't match any of the specified RDATAs will
    ///   remain in the zone.
    /// - Any RRs of the specified RRset that doesn't exist in the zone will
    ///   simply be ignored; the implementation of this method is not supposed
    ///   to check that condition.
    /// - The TTL of the RRset is ignored; matching is only performed by
    ///   the owner name, RR type and RDATA
    ///
    /// Ignoring the TTL may not look sensible, but it's based on the
    /// observation that it will result in more intuitive result, especially
    /// when the underlying data source is a general purpose database.
    /// See also \c DatabaseAccessor::deleteRecordInZone() on this point.
    /// It also matches the dynamic update protocol (RFC2136), where TTLs
    /// are ignored when deleting RRs.
    ///
    /// \note Since the TTL is ignored, this method could take the RRset
    /// to be deleted as a tuple of name, RR type, and a list of RDATAs.
    /// But in practice, it's quite likely that the caller has the RRset
    /// in the form of the \c RRset object (e.g., extracted from a dynamic
    /// update request message), so this interface would rather be more
    /// convenient.  If it turns out not to be true we can change or extend
    /// the method signature.
    ///
    /// This method performs minimum level of validation on the specified
    /// RRset:
    /// - Whether the RR class is identical to that for the zone to be updated
    /// - Whether the RRset is not empty, i.e., it has at least one RDATA
    /// - Whether the RRset is not associated with an RRSIG, i.e.,
    ///   whether \c getRRsig() on the RRset returns a NULL pointer.
    ///
    /// This method must not be called once commit() is performed.  If it
    /// calls after \c commit() the implementation must throw a
    /// \c DataSourceError exception.
    ///
    /// \todo As noted above we may have to revisit the design details as we
    /// gain experiences:
    ///
    /// - we may want to check (and maybe reject) if some or all of the RRs
    ///   for the specified RRset don't exist in the zone
    /// - we may want to allow an option to "delete everything" for specified
    ///   name and/or specified name + RR type.
    /// - as mentioned above, we may want to include the TTL in matching the
    ///   deleted RRs
    /// - we may want to add an "options" parameter that can control the
    ///   above points
    /// - we may want to have this method return a value containing the
    ///   information on whether there's any RRs that are specified but don't
    ///   exit, the number of actually deleted RRs, etc.
    ///
    /// \exception DataSourceError Called after \c commit(), RRset is invalid
    /// (see above), internal data source error
    /// \exception std::bad_alloc Resource allocation failure
    ///
    /// \param rrset The RRset to be deleted
    virtual void deleteRRset(const isc::dns::RRset& rrset) = 0;

    /// Commit the updates made in the updater to the zone
    ///
    /// This method completes the "transaction" started at the creation
    /// of the updater.  After successful completion of this method, the
    /// updates will be visible outside the scope of the updater.
    /// The actual internal behavior will defer for different derived classes.
    /// For a derived class with a general purpose database as a backend,
    /// for example, this method would perform a "commit" statement for the
    /// database.
    ///
    /// This operation can only be performed at most once.  A duplicate call
    /// must result in a DatasourceError exception.
    ///
    /// \exception DataSourceError Duplicate call of the method,
    /// internal data source error
    virtual void commit() = 0;
};

/// \brief A pointer-like type pointing to a \c ZoneUpdater object.
typedef boost::shared_ptr<ZoneUpdater> ZoneUpdaterPtr;

} // end of datasrc
} // end of isc

#endif  // __ZONE_H

// Local Variables:
// mode: c++
// End:
