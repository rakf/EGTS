#include "Record_Responce.h"
#include "../../../utility.h"

EGTS_SUBRECORD_RECORD_RESPONCE::EGTS_SUBRECORD_RECORD_RESPONCE( const char*& raw_data )
{
   fillField(raw.CRN, raw_data);
   fillField(raw.RST, raw_data);
}
