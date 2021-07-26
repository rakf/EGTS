#pragma once

#include <cstdint>
#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"

class EGTS_SUBRECORD_RECORD_RESPONCE : public EGTS_SUBRECORD_DATA_BASE
{
public:
    EGTS_SUBRECORD_RECORD_RESPONCE() = default;
    EGTS_SUBRECORD_RECORD_RESPONCE(const char*& raw_data);

    #pragma pack(push,1)
    struct EGTS_SUBRECORD_RECORD_RESPONCE_RAW
    {
	uint16_t  CRN;
	uint8_t   RST;
    } raw;
    #pragma pack(pop)
};
