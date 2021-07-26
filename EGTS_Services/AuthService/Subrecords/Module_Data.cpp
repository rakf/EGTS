#include "Module_Data.h"
#include "../../../utility.h"

EGTS_SUBRECORD_MODULE_DATA::EGTS_SUBRECORD_MODULE_DATA( const char*& raw_data )
{
   fillField( module_type, raw_data );
   fillField( VID, raw_data );
   fillField( FWV, raw_data );
   fillField( SWV, raw_data );
   fillField( MD, raw_data );
   fillField( ST, raw_data );
   fillField(SRN, raw_data);
   fillField(D_1, raw_data);
   fillField(DSCR, raw_data);
   fillField(D_2, raw_data);
}
