#include "Auth_Info.h"
#include "../../../utility.h"

EGTS_SUBRECORD_AUTH_INFO::EGTS_SUBRECORD_AUTH_INFO( const char*& raw_data )
{
	fillField(UNM, raw_data);
	fillField(D0, raw_data);
	fillField(UPSW, raw_data);
	fillField(D1, raw_data);
	fillField(SS, raw_data);
	fillField(D2, raw_data);
}
