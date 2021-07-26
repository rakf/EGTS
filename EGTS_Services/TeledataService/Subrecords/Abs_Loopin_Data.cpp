#include "EGTS_Auth_Service.h"
#include "Subrecords/Auth_Info.h"
#include "Subrecords/Auth_Params.h"
#include "Subrecords/Module_Data.h"
#include "Subrecords/Record_Responce.h"
#include "Subrecords/Result_code.h"
#include "Subrecords/Service_Info.h"
#include "Subrecords/Term_Identity.h"
#include "Subrecords/Vehicle_Data.h"

std::shared_ptr< EGTS_SUBRECORD_DATA_BASE > EGTS_AUTH_SERVICE::ParseSubrecord(size_t type, const char*& raw_data)
{
	switch ( static_cast< EGTS_AUTH_SERVICE_SUBRECORDS_TYPE >( type ) )
   {
		case EGTS_AUTH_SERVICE_SUBRECORDS_TYPE::EGTS_SR_AUTH_INFO :
			return std::make_shared< EGTS_SUBRECORD_AUTH_INFO >( raw_data ); 

		case EGTS_AUTH_SERVICE_SUBRECORDS_TYPE::EGTS_SR_AUTH_PARAMS :
			return std::make_shared< EGTS_SUBRECORD_AUTH_PARAMS >( raw_data );

		case EGTS_AUTH_SERVICE_SUBRECORDS_TYPE::EGTS_SR_MODULE_DATA:
			return std::make_shared< EGTS_SUBRECORD_MODULE_DATA >( raw_data );

		case EGTS_AUTH_SERVICE_SUBRECORDS_TYPE::EGTS_SR_RECORD_RESPONSE:
			return std::make_shared< EGTS_SUBRECORD_RECORD_RESPONCE >( raw_data );

		case EGTS_AUTH_SERVICE_SUBRECORDS_TYPE::EGTS_SR_RESULT_CODE:
			return std::make_shared< EGTS_SUBRECORD_RESULT_CODE >( raw_data );

		case EGTS_AUTH_SERVICE_SUBRECORDS_TYPE::EGTS_SR_SERVICE_INFO:
			return std::make_shared< EGTS_SUBRECORD_SERVICE_INFO >( raw_data );

		case EGTS_AUTH_SERVICE_SUBRECORDS_TYPE::EGTS_SR_TERM_IDENTITY:
			return std::make_shared< EGTS_SUBRECORD_TERM_IDENTITY >( raw_data );

		case EGTS_AUTH_SERVICE_SUBRECORDS_TYPE::EGTS_SR_VEHICLE_DATA:
			return std::make_shared< EGTS_SUBRECORD_VEHICLE_DATA >( raw_data );
	}

}
