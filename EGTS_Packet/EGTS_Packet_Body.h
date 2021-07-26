#pragma once

#include <vector>
#include <optional>
#include "../EGTS_Record/EGTS_Record.h"


class EGTS_PACKET_BODY
{
public:
   EGTS_PACKET_BODY() = default;
   virtual ~EGTS_PACKET_BODY() = default;
   
   std::vector< EGTS_RECORD > records;
   uint16_t check_sum;
   bool is_correct;
   uint16_t data_length;
};

class EGTS_PT_APPDATA_BODY : public EGTS_PACKET_BODY
{
public:
   EGTS_PT_APPDATA_BODY( uint16_t data_length, const char*& raw_data );
      
};

#pragma pack(push,1)
struct EGTS_PT_RESPONCE_BODY_HEADER
{
   uint16_t responcePacketID;
	uint8_t processingResult;
};
#pragma pack(pop)

class EGTS_PT_RESPONSE_BODY : public EGTS_PACKET_BODY
{
public:
	EGTS_PT_RESPONSE_BODY() = default;
   EGTS_PT_RESPONSE_BODY( uint16_t data_length, const char*& raw_data );
   EGTS_PT_RESPONCE_BODY_HEADER raw_header;
};

class EGTS_PT_SIGNED_APPDATA_BODY : public EGTS_PACKET_BODY
{
public:

private:
   int16_t signatureLength;
   std::optional<std::vector< uint16_t >> signatureData;
};




