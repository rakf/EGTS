#pragma once

#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"
#include <cstdint>

struct EGTS_SUBRECORD_STATE_DATA_FLAGS_DETAIL
{
    bool navigation_is_on; // Навигационный модуль включен
    bool IBU;              // определяет, что в качестве источника питания абонентского терминала используется внешний резервный источник.
    bool BBU;              // Определяет, что в качестве источника питания абонентского терминала используется внутренняя батарея
};

enum class STATE_ENUM
{
    PASSIVE = 0,
    ERA = 1,
    ACTIVE = 2,
    EMERGENCY_CALL = 3,
    EMERGENCY_TRACKING = 4,
    TESTING = 5,
    CAR_SERVICE = 6,
    DOWNLOADING_SOFTWARE = 7
};


class EGTS_SUBRECORD_STATE_DATA : public EGTS_SUBRECORD_DATA_BASE
{
public:
    EGTS_SUBRECORD_STATE_DATA() = default;
    EGTS_SUBRECORD_STATE_DATA(const char*& raw_data);

    #pragma pack( push, 1 )
    struct EGTS_SUBRECORD_STATE_DATA_RAW
    {
        uint8_t  ST;	  // State - текущий режим работы
        uint8_t MPSV;     // Main Power Source Voltage - значение напряжения основного источника питания, В, с дискретностью 0,1 В;
        uint8_t BBV;      // Back Up Battery Voltage - значение напряжения резервной батареи, В, с дискретностью 0,1 В;
        uint8_t IBV;      // Internal Battery Voltage -  значение напряжения внутренней батареи, В, с дискретностью 0,1 В;
        uint8_t FLG;      // Флаги
    } raw;
    #pragma pack( pop )

    EGTS_SUBRECORD_STATE_DATA_FLAGS_DETAIL detailed_flag;
};







