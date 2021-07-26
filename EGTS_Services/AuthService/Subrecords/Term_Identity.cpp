#include "Term_Identity.h"
#include "../../../utility.h"

EGTS_SUBRECORD_TERM_IDENTITY::EGTS_SUBRECORD_TERM_IDENTITY( const char*& raw_data )
{
   fillField( TID, raw_data );
   fillField( FLG, raw_data );

   flags_detail.exist_field_MSISDN = FLG & 128;
   flags_detail.exist_field_BS = FLG & 64;
   flags_detail.exist_field_NID = FLG & 32;
   flags_detail.algorithm_type = FLG & 16;
   flags_detail.exist_field_LNGC = FLG & 8;
   flags_detail.exist_field_IMSI = FLG & 4;
   flags_detail.exist_field_IMEI = FLG & 2;
   flags_detail.exist_field_HDID = FLG & 1;

   if( flags_detail.exist_field_HDID ) fillField( HDID, raw_data );
   if( flags_detail.exist_field_IMEI ) fillField( IMEI, raw_data, EGTS_IMEI_LEN );
   if( flags_detail.exist_field_IMSI ) fillField( IMSI, raw_data, EGTS_IMEI_LEN );
   if( flags_detail.exist_field_LNGC ) fillField( LNGC, raw_data, EGTS_LNGC_LEN );
   if( flags_detail.exist_field_NID ) fillField( NID, raw_data, EGTS_NID_LEN );
   if( flags_detail.exist_field_BS ) fillField( BS, raw_data);
   if( flags_detail.exist_field_MSISDN ) fillField( MSISDN, raw_data, EGTS_MSISDN_LEN );

}
