#pragma once
#include <cstdint>

class EGTS_SUBRECORD_HEADER
{
public:
	EGTS_SUBRECORD_HEADER() = default;
   EGTS_SUBRECORD_HEADER( const char *& raw_data);
   uint8_t getType() const;
   uint16_t getLength() const;

   #pragma pack(push,1)
   struct EGTS_SUBRECORD_HEADER_RAW
   {
   uint8_t type;							// тип подзаписи
   uint16_t length;						// длина данных в байтах в поле data
   } raw_subrecord_header ;
   #pragma pack(pop)
};

