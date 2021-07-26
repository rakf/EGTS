#include "Pos_Data.h"
#include "../../../utility.h"

EGTS_SUBRECORD_POS_DATA::EGTS_SUBRECORD_POS_DATA(const char*& raw_data)
{
    fillField( raw.NTM, raw_data);
    fillField( raw.LAT, raw_data);
    fillField( raw.LONG, raw_data);
    fillField( raw.FLG, raw_data);

    detailed_flag.ALT_exist = raw.FLG & 128;
    detailed_flag.is_west_longitude = raw.FLG & 64;
    detailed_flag.is_south_latitude = raw.FLG & 32;
    detailed_flag.is_moving = raw.FLG & 16;
    detailed_flag.is_black_box_data = raw.FLG & 8;
    detailed_flag.is_3d_fix = raw.FLG & 4;
    detailed_flag.coordinat_system = raw.FLG & 2;
    detailed_flag.valid = raw.FLG & 1;

    fillField( raw.SPD, raw_data);
    fillField( raw.DIR, raw_data);
    fillField( raw.ODM, raw_data);
    fillField( raw.DIN, raw_data);
    fillField( raw.SRC, raw_data);


}
