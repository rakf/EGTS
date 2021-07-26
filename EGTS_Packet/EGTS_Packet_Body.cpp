#include "EGTS_Packet_Body.h"
#include "../utility.h"

EGTS_PT_APPDATA_BODY::EGTS_PT_APPDATA_BODY(uint16_t data_length_, const char*& raw_data )
{
	data_length = data_length_;
	const unsigned char* begin_unsigned_char_data = reinterpret_cast<const unsigned char*>(raw_data);

	// должен быть цикл
	{
      //EGTS_RECORD record(raw_data);
      records.emplace_back(raw_data);
	}

	fillField(check_sum, raw_data);

	is_correct = CRC16EGTS(begin_unsigned_char_data, data_length) == check_sum;
}

EGTS_PT_RESPONSE_BODY::EGTS_PT_RESPONSE_BODY( uint16_t data_length, const char*& raw_data )
{
   const unsigned char* begin_unsigned_char_data = reinterpret_cast<const unsigned char*>(raw_data);
   fillField( raw_header.responcePacketID, raw_data );
   fillField( raw_header.processingResult, raw_data );
   // должен быть цикл
   {
      //EGTS_RECORD record(raw_data);
      records.emplace_back(raw_data);
   }

   fillField(check_sum, raw_data);

   is_correct = CRC16EGTS(begin_unsigned_char_data, data_length) == check_sum;
}


