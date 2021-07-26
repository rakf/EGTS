#pragma once

#include <optional>
#include <cstdint>
#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"

enum class MODULE_TYPE
{
   MAIN = 1,                // основной модуль
   INPUT_OUTPUT = 2,        // модуль ввода вывода
   NAVIGATION_RECEIVER = 3, // модуль навигационного приемника
   WIRELESS_CONNECTION = 4  // модуль беспроводной связи
};


class EGTS_SUBRECORD_MODULE_DATA : public EGTS_SUBRECORD_DATA_BASE
{
public:
   EGTS_SUBRECORD_MODULE_DATA(const char*& raw_data);

private:
   uint8_t module_type;	// тип модуля, определяет функциональную принадлежность модуля
   uint32_t	VID; // код производителя
   uint16_t FWV; // версия аппаратной части модуля  старший байт — число до точки — major version,
                 // младший — после точки — minor version, например версия 2.34 будет представлена числом 0x0222
   uint16_t SWV; // версия программной части модуля (старший байт — число до точки, младший — после точки
   uint8_t MD;	  // код модификации программной части модуля
   uint8_t ST;	  // состояние (1 — включен, 0 — выключен, больше 127 — неисправность (см. приложение В));
   char SRN[32]; // серийный номер модуля;
   uint8_t D_1;  // разделитель строковых параметров (всегда имеет значение 0);
   char DSCR[32]; // краткое описание модуля.
   uint8_t D_2;  // разделитель строковых параметров (всегда имеет значение 0);
};
