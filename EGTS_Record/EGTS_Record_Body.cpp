#include "EGTS_Record_Body.h"

EGTS_RECORD_BODY::EGTS_RECORD_BODY( EGTS_SERVICE_TYPE service_type, uint32_t length_, const char*& raw_data)
   : service_type( service_type )
   , length( length_ )
{
   const char* begin = raw_data;

   size_t i =  begin + length - raw_data;
   while( raw_data < begin + length  )
   {
       i =  begin + length - raw_data;
      data.emplace_back( service_type, raw_data );
   }
}
