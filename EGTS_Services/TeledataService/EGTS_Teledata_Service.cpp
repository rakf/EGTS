#include "EGTS_Teledata_Service.h"
#include "Subrecords/Pos_Data.h"
#include "../../EGTS_Record/EGTS_Subrecord_Record_Responce.h"
#include "Subrecords/Ext_Pos_Data.h"
#include "Subrecords/State_Data.h"
#include "Subrecords/Ad_Sensors_Data.h"
#include "Subrecords/Counters_Data.h"


std::shared_ptr< EGTS_SUBRECORD_DATA_BASE > EGTS_TELEDATA_SERVICE::ParseSubrecord(size_t type, uint16_t length, const char*& raw_data)
{
      switch ( static_cast< EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE >( type ) )
   {
                case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_RECORD_RESPONSE :
                        return std::make_shared< EGTS_SUBRECORD_RECORD_RESPONCE >( raw_data );

                case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_POS_DATA :
                        return std::make_shared< EGTS_SUBRECORD_POS_DATA >( raw_data, length );

                 case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_EXT_POS_DATA :
                         return std::make_shared< EGTS_SUBRECORD_EXT_POS_DATA >( raw_data );

                 case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_STATE_DATA :
                         return std::make_shared< EGTS_SUBRECORD_STATE_DATA >( raw_data );

                 case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_AD_SENSORS_DATA :
                         return std::make_shared< EGTS_SUBRECORD_AD_SENSORS_DATA >( raw_data );

                 case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_COUNTERS_DATA :
                         return std::make_shared< EGTS_SUBRECORD_COUNTERS_DATA >( raw_data );
      default: std::shared_ptr< EGTS_SUBRECORD_DATA_BASE >();
	}
        return std::shared_ptr< EGTS_SUBRECORD_DATA_BASE >();

}
