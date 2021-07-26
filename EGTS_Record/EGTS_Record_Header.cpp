#include "EGTS_Record_Header.h"
#include "../utility.h"

EGTS_RECORD_HEADER::EGTS_RECORD_HEADER(const char*& raw_data)
{
    fillField( record_header_raw.length, raw_data );
    fillField( record_header_raw.recordNumber, raw_data );
    fillField( record_header_raw.flags, raw_data );

    detailed_flags.source_sevice_on_device = (record_header_raw.flags & 128) >> 7;
    detailed_flags.recipient_service_on_device = (record_header_raw.flags & 64) >> 6;
    detailed_flags.group = record_header_raw.flags & 32;
    detailed_flags.priority = (record_header_raw.flags & 24) >> 3;
    detailed_flags.time_field_exists = record_header_raw.flags & 4;
    detailed_flags.event_field_exists = record_header_raw.flags & 2;
    detailed_flags.object_id_field_exists = record_header_raw.flags & 1;

    if( detailed_flags.object_id_field_exists ) fillField( objectID, raw_data );
    if( detailed_flags.event_field_exists ) fillField( eventID, raw_data );
    if( detailed_flags.time_field_exists ) fillField( time, raw_data );

    fillField( record_header_raw.SST, raw_data );
    fillField( record_header_raw.RST, raw_data );
}

EGTS_SERVICE_TYPE EGTS_RECORD_HEADER::getServiceSourceType() const
{
   return static_cast< EGTS_SERVICE_TYPE >( record_header_raw.SST );
}

EGTS_SERVICE_TYPE EGTS_RECORD_HEADER::getRecipientSourceType() const
{
   return static_cast< EGTS_SERVICE_TYPE >( record_header_raw.RST );
}
