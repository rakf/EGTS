#pragma once

#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"
#include <cstdint>
#include <optional>

struct EGTS_SUBRECORD_EXT_POS_DATA_FLAGS_DETAIL
{
    bool NS_field_exists; // определяет наличие поля NS в подзаписи
    bool SAT_field_exists; // определяет наличие полей NS и SAT в подзаписи
    bool PDOP_field_exists; // определяет наличие поля PDOP в подзаписи
    bool HDOP_field_exists; // определяет наличие поля HDOP в подзаписи
    bool VDOP_field_exists; // определяет наличие поля VDOP в подзаписи
};

struct EGTS_SUBRECORD_EXT_POS_DATA_NS_FLAGS_DETAIL // Флаги используемых навигационных систем
{
    bool GLONASS;
    bool GPS;
    bool Galileo;
    bool Compass;
    bool Beidou;
    bool DORIS;
    bool IRNSS;
    bool QZSS;
};

class EGTS_SUBRECORD_EXT_POS_DATA : public EGTS_SUBRECORD_DATA_BASE
{
public:
    EGTS_SUBRECORD_EXT_POS_DATA() = default;
    EGTS_SUBRECORD_EXT_POS_DATA(const char*& raw_data);

    #pragma pack( push, 1 )
    struct EGTS_SUBRECORD_EXT_POS_DATA_RAW
    {
        uint8_t  FLG;	  // 1 байт Flags
    } raw;
    #pragma pack( pop )

    EGTS_SUBRECORD_EXT_POS_DATA_FLAGS_DETAIL detailed_flag;

    // optional fields
    std::optional< uint16_t > VDOP; // снижение точности в вертикальной плоскости (значение, умноженное на 100);
    std::optional< uint16_t > HDOP; // снижение точности в горизонтальной плоскости (значение, умноженное на 100);
    std::optional< uint16_t > PDOP; // - снижение точности по местоположению (значение, умноженное на 100);
    std::optional< uint8_t > SAT; // количество видимых спутников;
    std::optional< uint16_t > NS; // битовые флаги, характеризующие используемые навигационные спутниковые системы. Определены следующие значения

    EGTS_SUBRECORD_EXT_POS_DATA_NS_FLAGS_DETAIL navigation_systems;
};







