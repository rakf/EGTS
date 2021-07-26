#pragma once

#include "../../EGTS_Record/EGTS_Subrecord_Data.h"
#include <cstdint>
#include <optional>

struct EGTS_SUBRECORD_POS_DATA_FLAGS_DETAIL
{
    bool ALT_exist; // определяет наличие поля ALT в подзаписи
    bool is_west_longitude; // 0 - восточная долгота, 1 - западная долгота;
    bool is_south_latitude; // 0 - северная широта; 1 - южная широта;
    bool is_moving; // 1 - движение; 0 - транспортное средство находится в режиме стоянки;
    bool is_black_box_data; // 0 - актуальные данные; 1 - данные из памяти ("черного ящика");
    bool is_3d_fix; // 0 - 2D fix; 1 - 3D fix;
    bool coordinat_system; // 0 - система координат WGS-84; 1 - государственная геоцентрическая система координат (ПЗ-90.02);
    bool valid; // 1 - данные "валидны"; 0 - "невалидные" данные;
};

class EGTS_SUBRECORD_POS_DATA : public EGTS_SUBRECORD_DATA_BASE
{
public:
    EGTS_SUBRECORD_POS_DATA() = default;
    EGTS_SUBRECORD_POS_DATA(const char*& raw_data);

    #pragma pack( push, 1 )
    struct EGTS_SUBRECORD_POS_DATA_RAW
    {
        uint32_t NTM; 	// 4 байта Navigation Time , seconds since 00:00:00 01.01.2010 UTC
        uint32_t LAT;	// 4 байта Latitude, degree,  (WGS - 84) / 90 * 0xFFFFFFFF
        uint32_t LONG;	// 4 байта Longitude, degree,  (WGS - 84) / 180 * 0xFFFFFFFF
        uint8_t  FLG;	// 1 байт Flags
        uint16_t SPD;	// 2 байта, см. ниже
        uint8_t  DIR;     // направление движения
        uint8_t  ODM[3];  // пройденное расстояние (пробег) в км, с дискретностью 0,1 км;
        uint8_t  DIN;     // битовые флаги, определяют состояние основных дискретных входов 1 ... 8
        uint8_t  SRC;     // источник (событие), инициировавший посылку данной навигационной информации (http://www.zakonprost.ru/content/base/part/1038460 Таблица N 3)
    } raw;
    #pragma pack( pop )


    EGTS_SUBRECORD_POS_DATA_FLAGS_DETAIL detailed_flag;
    // optional fields
    uint8_t		ALT[3];	// высота над уровнем моря, м (опциональный параметр, наличие которого определяется битовым флагом ALTE);
    std::optional< uint16_t >	SRCD;		// (см. ниже) данные, характеризующие источник (событие) из поля src. Наличие и интерпретация значения данного поля определяется полем src
};







