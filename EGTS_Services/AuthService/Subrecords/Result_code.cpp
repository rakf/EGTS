#include "Result_code.h"
#include "../../../utility.h"

EGTS_SUBRECORD_RESULT_CODE::EGTS_SUBRECORD_RESULT_CODE( const char*& raw_data )
{
	fillField(ResultCode, raw_data);
}
