#include "EGTS_Teledata_Service.h"
#include "Subrecords/Pos_Data.h"
#include "Subrecords/Record_Responce.h"
#include "Subrecords/Ext_Pos_Data.h"


std::shared_ptr< EGTS_SUBRECORD_DATA_BASE > EGTS_TELEDATA_SERVICE::ParseSubrecord(size_t type, const char*& raw_data)
{
        switch ( static_cast< EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE >( type ) )
   {
                case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_RECORD_RESPONSE :
                        return std::make_shared< EGTS_SUBRECORD_RECORD_RESPONCE >( raw_data );

                case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_POS_DATA :
                        return std::make_shared< EGTS_SUBRECORD_POS_DATA >( raw_data );

                 case EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE::EGTS_SR_EXT_POS_DATA :
                         return std::make_shared< EGTS_SR_EXT_POS_DATA >( raw_data );

	}

}
