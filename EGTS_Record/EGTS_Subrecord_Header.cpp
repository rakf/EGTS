#include "EGTS_Subrecord_Header.h"
#include "../utility.h"

EGTS_SUBRECORD_HEADER::EGTS_SUBRECORD_HEADER( const char *& raw_data)
{
   fillField( raw_subrecord_header.type, raw_data );
   fillField( raw_subrecord_header.length, raw_data );
}

uint8_t EGTS_SUBRECORD_HEADER::getType() const
{
   return raw_subrecord_header.type;
}

uint16_t EGTS_SUBRECORD_HEADER::getLength() const
{
   return raw_subrecord_header.length;
}
