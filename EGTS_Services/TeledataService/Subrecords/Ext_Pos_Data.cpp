#include "Ext_Pos_Data.h"
#include "../../../utility.h"

EGTS_SUBRECORD_EXT_POS_DATA::EGTS_SUBRECORD_EXT_POS_DATA( const char*& raw_data )
{
    fillField( raw.FLG, raw_data );

    detailed_flag.NS_field_exist = raw.FLG & 16;
    detailed_flag.SAT_and_NS_fields_exists = raw.FLG & 8;
    detailed_flag.PDOP_field_exist = raw.FLG & 4;
    detailed_flag.HDOP_field_exist = raw.FLG & 2;
    detailed_flag.VDOP_field_exist = raw.FLG & 1;

    if( detailed_flag.VDOP_field_exist ) fillField( VDOP, raw_data );
    if( detailed_flag.HDOP_field_exist ) fillField( HDOP, raw_data );
    if( detailed_flag.PDOP_field_exist ) fillField( PDOP, raw_data );
    if( detailed_flag.SAT_and_NS_fields_exists ) { fillField( SAT, raw_data ); fillField( NS, raw_data ); }
    if( detailed_flag.NS_field_exist ) fillField( NS, raw_data );

    if( NS )
    {
        navigation_systems.QZSS = *NS & 128;
        navigation_systems.IRNSS = *NS & 64;
        navigation_systems.DORIS = *NS & 32;
        navigation_systems.Beidou = *NS & 16;
        navigation_systems.Compass = *NS & 8;
        navigation_systems.Galileo = *NS & 4;
        navigation_systems.GPS = *NS & 2;
        navigation_systems.GLONASS = *NS & 1;
    }
}
