#include "Counters_Data.h"
#include "../../../utility.h"

EGTS_SUBRECORD_COUNTERS_DATA::EGTS_SUBRECORD_COUNTERS_DATA( const char*& raw_data )
{
    fillField( raw.FieldExist, raw_data );

    if( raw.FieldExist & 1 ) fillField( CN1, raw_data );
    if( raw.FieldExist & 2 ) fillField( CN2, raw_data );
    if( raw.FieldExist & 4 ) fillField( CN3, raw_data );
    if( raw.FieldExist & 8 ) fillField( CN4, raw_data );
    if( raw.FieldExist & 16 ) fillField( CN5, raw_data );
    if( raw.FieldExist & 32 ) fillField( CN6, raw_data );
    if( raw.FieldExist & 64 ) fillField( CN7, raw_data );
    if( raw.FieldExist & 128 ) fillField( CN8, raw_data );

}
