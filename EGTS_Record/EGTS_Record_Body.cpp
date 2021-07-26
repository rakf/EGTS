#include "EGTS_Record_Body.h"

EGTS_RECORD_BODY::EGTS_RECORD_BODY( EGTS_SERVICE_TYPE service_type, const char*& raw_data)
   : service_type( service_type )
{
   data.emplace_back( service_type, raw_data );
}
