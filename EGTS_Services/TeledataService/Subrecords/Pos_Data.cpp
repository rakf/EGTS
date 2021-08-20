#include "Pos_Data.h"
#include "../../../utility.h"
#include <iomanip>
#include <sstream>


EGTS_SUBRECORD_POS_DATA::EGTS_SUBRECORD_POS_DATA(const char*& raw_data,  uint16_t length)
{
    auto begin = raw_data;

    fillField( raw.NTM, raw_data); // c 2010
    time_string = getDateString( raw.NTM );

    fillField( raw.LAT, raw_data);
    fillField( raw.LONG, raw_data);
    lat = 90.0 * raw.LAT / 0xFFFFFFFF;
    lon = 180.0 * raw.LONG / 0xFFFFFFFF;

    fillField( raw.FLG, raw_data);

    detailed_flag.ALT_exist = raw.FLG & 128;
    detailed_flag.is_west_longitude = raw.FLG & 64;
    detailed_flag.is_south_latitude = raw.FLG & 32;
    detailed_flag.is_moving = raw.FLG & 16;
    detailed_flag.is_black_box_data = raw.FLG & 8;
    detailed_flag.is_3d_fix = raw.FLG & 4;
    detailed_flag.coordinat_system = raw.FLG & 2;
    detailed_flag.valid = raw.FLG & 1;

    if( detailed_flag.coordinat_system )
    {
       // перевод из ПЗ 90.02 в WSG-84
    }

    fillField( raw.SPD, raw_data);
    fillField( raw.DIR, raw_data);
    fillField( raw.ODM, raw_data, 3);
    fillField( raw.DIN, raw_data);
    fillField( raw.SRC, raw_data);

    if( detailed_flag.ALT_exist ) fillField( ALT, raw_data, 3);
    if( raw.SRC >= 0 &&
        raw.SRC < 36 &&
        raw_data - begin < length) fillField( SRCD, raw_data );

    speed = (raw.SPD & 16383) / 10;
}
