#pragma once

#include <optional>
#include <cstdint>
#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"


class EGTS_SUBRECORD_RESULT_CODE : public EGTS_SUBRECORD_DATA_BASE
{
public:
        EGTS_SUBRECORD_RESULT_CODE(const char*& raw_data);

private:
	uint8_t	ResultCode;
};