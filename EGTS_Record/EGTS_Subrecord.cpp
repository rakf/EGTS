#include "EGTS_Subrecord.h"

EGTS_SUBRECORD::EGTS_SUBRECORD( EGTS_SERVICE_TYPE service_type_, const char*& raw_data )
   : service_type( service_type_ )
   , header( raw_data )
   , data( service_type_, header.getType(), header.getLength(), raw_data )
{
}
