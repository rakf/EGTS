#pragma once

#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"
#include <cstdint>
#include <optional>


class EGTS_SUBRECORD_AD_SENSORS_DATA : public EGTS_SUBRECORD_DATA_BASE
{
public:
    EGTS_SUBRECORD_AD_SENSORS_DATA() = default;
    EGTS_SUBRECORD_AD_SENSORS_DATA(const char*& raw_data);

    #pragma pack( push, 1 )
    struct EGTS_SUBRECORD_AD_SENSORS_DATA_RAW
    {
        uint8_t  DI_FLG;	  // битовые флаги, определяющие наличие соответствующих полей дополнительных дискретных входов
        uint8_t  DOUT;       // битовые флаги дискретных выходов (если бит установлен в 1, то соответствующий этому биту выход активен)
        uint8_t  ASFE;       // Analog Sensor Field Exists) битовые флаги, определяющие наличие показаний от соответствующих аналоговых датчиков
                             //(если бит установлен в 1, то данные от соответствующего датчика присутствуют, если 0, данные отсутствуют
    } raw;
    #pragma pack( pop )


    // optional fields
    std::optional< uint8_t > ADIO1;
    std::optional< uint8_t > ADIO2;
    std::optional< uint8_t > ADIO3;
    std::optional< uint8_t > ADIO4;
    std::optional< uint8_t > ADIO5;
    std::optional< uint8_t > ADIO6;
    std::optional< uint8_t > ADIO7;
    std::optional< uint8_t > ADIO8;

    char ANS1[3];
    char ANS2[3];
    char ANS3[3];
    char ANS4[3];
    char ANS5[3];
    char ANS6[3];
    char ANS7[3];
    char ANS8[3];

};







