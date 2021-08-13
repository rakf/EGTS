#include "State_Data.h"
#include "../../../utility.h"

EGTS_SUBRECORD_STATE_DATA::EGTS_SUBRECORD_STATE_DATA( const char*& raw_data )
{
    fillField( raw.ST, raw_data );
    fillField( raw.MPSV, raw_data );
    fillField( raw.BBV, raw_data );
    fillField( raw.IBV, raw_data );
    fillField( raw.FLG, raw_data );

    detailed_flag.navigation_is_on = raw.FLG & 4;
    detailed_flag.IBU = raw.FLG & 2;
    detailed_flag.BBU = raw.FLG & 1;
}
