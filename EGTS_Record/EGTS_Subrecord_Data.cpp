#include "EGTS_Subrecord_Data.h"
#include "../EGTS_Services/AuthService/EGTS_Auth_Service.h"
#include "../EGTS_Services/TeledataService/EGTS_Teledata_Service.h"
#include "../EGTS_Services/EGTS_Services_Type.h"

EGTS_SUBRECORD_DATA::EGTS_SUBRECORD_DATA( EGTS_SERVICE_TYPE service_type_, uint8_t subrecord_type_,  uint8_t length_,  const char*& raw_data )
	: service_type( service_type_ )
	, subrecord_type( subrecord_type_ )
    , length ( length_ )
{
    auto begin = raw_data;

    while( raw_data - begin < length )
    {
        switch ( static_cast< EGTS_SERVICE_TYPE >( service_type ) )
        {
        case EGTS_SERVICE_TYPE::EGTS_AUTH_SERVICE :
          data.push_back( EGTS_AUTH_SERVICE::ParseSubrecord( subrecord_type, raw_data ) );
          break;
       case EGTS_SERVICE_TYPE::EGTS_TELEDATA_SERVICE :
          data.push_back( EGTS_TELEDATA_SERVICE::ParseSubrecord( subrecord_type, length, raw_data ) );
          break;
        default:
            break;
        }
    }
}
