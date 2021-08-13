#pragma once

#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"
#include <cstdint>
#include <optional>


class EGTS_SUBRECORD_COUNTERS_DATA : public EGTS_SUBRECORD_DATA_BASE
{
public:
    EGTS_SUBRECORD_COUNTERS_DATA() = default;
    EGTS_SUBRECORD_COUNTERS_DATA(const char*& raw_data);

    #pragma pack( push, 1 )
    struct EGTS_SUBRECORD_COUNTERS_DATA_RAW
    {
        uint8_t  FieldExist;	  // State - текущий режим работы
    } raw;
    #pragma pack( pop )

    // optional

    char CN1[3];
    char CN2[3];
    char CN3[3];
    char CN4[3];
    char CN5[3];
    char CN6[3];
    char CN7[3];
    char CN8[3];

};







