// Copyright (C) 2012  Internet Systems Consortium, Inc. ("ISC")
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

#ifndef DATASRC_MEMORY_ZONE_TABLE_SEGMENT_TEST_H
#define DATASRC_MEMORY_ZONE_TABLE_SEGMENT_TEST_H 1

#include <datasrc/memory/zone_table_segment.h>
#include <datasrc/memory/zone_table.h>
#include <datasrc/memory/zone_data.h>
#include <datasrc/memory/zone_writer.h>

namespace isc {
namespace datasrc {
namespace memory {
namespace test {

// A special ZoneTableSegment that can be used for tests.  It can be
// passed a MemorySegment that can be used later to test if all memory
// was de-allocated on it.
class ZoneTableSegmentTest : public ZoneTableSegment {
public:
    ZoneTableSegmentTest(const isc::dns::RRClass& rrclass,
                         isc::util::MemorySegment& mem_sgmt) :
        ZoneTableSegment(rrclass),
        mem_sgmt_(mem_sgmt),
        header_(ZoneTable::create(mem_sgmt_, rrclass))
    {}

    virtual ~ZoneTableSegmentTest() {
        ZoneTable::destroy(mem_sgmt_, header_.getTable());
    }

    virtual void reset(MemorySegmentOpenMode, isc::data::ConstElementPtr) {
        // This method doesn't do anything.
    }

    virtual ZoneTableHeader& getHeader() {
        return (header_);
    }

    virtual const ZoneTableHeader& getHeader() const {
        return (header_);
    }

    virtual isc::util::MemorySegment& getMemorySegment() {
        return (mem_sgmt_);
    }

    virtual bool isWritable() const {
        return (true);
    }

private:
    isc::util::MemorySegment& mem_sgmt_;
    ZoneTableHeader header_;
};

} // namespace test
} // namespace memory
} // namespace datasrc
} // namespace isc

#endif // DATASRC_MEMORY_ZONE_TABLE_SEGMENT_TEST_H

// Local Variables:
// mode: c++
// End:
