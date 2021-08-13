#include "Ad_Sensors_Data.h"
#include "../../../utility.h"

EGTS_SUBRECORD_AD_SENSORS_DATA::EGTS_SUBRECORD_AD_SENSORS_DATA( const char*& raw_data )
{
    fillField( raw.DI_FLG, raw_data );
    fillField( raw.DOUT, raw_data );
    fillField( raw.ASFE, raw_data );

    if( raw.DI_FLG & 1 ) fillField( ADIO1, raw_data );
    if( raw.DI_FLG & 2 ) fillField( ADIO2, raw_data );
    if( raw.DI_FLG & 4 ) fillField( ADIO3, raw_data );
    if( raw.DI_FLG & 8 ) fillField( ADIO4, raw_data );
    if( raw.DI_FLG & 16 ) fillField( ADIO5, raw_data );
    if( raw.DI_FLG & 32 ) fillField( ADIO6, raw_data );
    if( raw.DI_FLG & 64 ) fillField( ADIO7, raw_data );
    if( raw.DI_FLG & 128 ) fillField( ADIO8, raw_data );


    if( raw.ASFE & 1 ) fillField( ANS1, raw_data );
    if( raw.ASFE & 2 ) fillField( ANS2, raw_data );
    if( raw.ASFE & 4 ) fillField( ANS3, raw_data );
    if( raw.ASFE & 8 ) fillField( ANS4, raw_data );
    if( raw.ASFE & 16 ) fillField( ANS5, raw_data );
    if( raw.ASFE & 32 ) fillField( ANS6, raw_data );
    if( raw.ASFE & 64 ) fillField( ANS7, raw_data );
    if( raw.ASFE & 128 ) fillField( ANS8, raw_data );

}
