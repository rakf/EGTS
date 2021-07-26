#include "EGTS_Subrecord_Data.h"
#include "../EGTS_Services/AuthService/EGTS_Auth_Service.h"
#include "../EGTS_Services/EGTS_Services_Type.h"

EGTS_SUBRECORD_DATA::EGTS_SUBRECORD_DATA( EGTS_SERVICE_TYPE service_type_, uint8_t subrecord_type_, const char*& raw_data )
	: service_type( service_type_ )
	, subrecord_type( subrecord_type_ )
{
	switch ( static_cast< EGTS_SERVICE_TYPE >( service_type ) )
	{
	case EGTS_SERVICE_TYPE::EGTS_AUTH_SERVICE :
		data.push_back( std::move( EGTS_AUTH_SERVICE::ParseSubrecord(subrecord_type, raw_data ) ) );
		break;
	default:
		break;
	}
}
