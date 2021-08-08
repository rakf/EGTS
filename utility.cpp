#include "utility.h"

#include "EGTS_Record/EGTS_Subrecord.h"
#include "EGTS_Record/EGTS_Subrecord_Record_Responce.h"


unsigned char CRC8EGTS( const unsigned char *lpBlock, unsigned char len)
{
        unsigned char crc = 0xFF;
        while (len--)
                crc = CRC8Table[crc ^ *lpBlock++];
        return crc;
}

unsigned short CRC16EGTS( const unsigned char * pcBlock, unsigned short len)
{
	unsigned short crc = 0xFFFF;
	while (len--)
		crc = (crc << 8) ^ Crc16Table[(crc >> 8) ^ *pcBlock++];
	return crc;
}

std::vector<char> MakeAnswer(const EGTS_Packet& packet)
{
   char answer[4096];
   size_t size_answer = 0;
   size_answer += EGTS_Packet_Create(answer, EGTS_PACKET_TYPE::EGTS_PT_RESPONSE);
   answer[7] = packet.header.raw_header.packedID;
   size_answer += responce_add_responce(answer, size_answer, packet.header.raw_header.packedID, 0 /*EGTS_PC_OK*/); //Пакет приняли

   if(packet.body)
   {
      for( const auto& rec :  packet.body->records )
      {
         size_answer += EGTS_responce_add_record( answer, size_answer, rec, rec.header.record_header_raw.recordNumber, 0 );
      }
   }


   size_answer += packet_finalize( answer, size_answer );
   return std::vector<char> (answer, answer + size_answer);

}

int EGTS_Packet_Create(char *buffer, EGTS_PACKET_TYPE pt){
   static unsigned short int PacketNumber = 0;	// packet number, joint for encode & decode
   EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW *pak_head = (EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW *)buffer;
   pak_head->protocolVersion = 1;
   pak_head->securityKeyID = 0;
   pak_head->flags = 0;
   pak_head->headerLength = sizeof(EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW);	// 11
   pak_head->headerEncrypt = 0;
   pak_head->dataLength = 0;
   pak_head->packedID = PacketNumber++;
   pak_head->packetType = static_cast<uint8_t>(pt);	// Тип пакета Транспортного Уровня
   pak_head->headerCheckSum = CRC8EGTS((unsigned char *)pak_head, pak_head->headerLength-1);

   return pak_head->headerLength;
}

int responce_add_responce(char *buffer, int pointer, uint16_t pid, uint8_t pr){
   EGTS_PT_RESPONCE_BODY_HEADER *res_head = (EGTS_PT_RESPONCE_BODY_HEADER *)&buffer[pointer];
  res_head->responcePacketID = pid;
  res_head->processingResult = pr;

   EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW *pak_head = (EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW *)buffer;
   pak_head->dataLength = sizeof(EGTS_PT_RESPONCE_BODY_HEADER);

   return sizeof(EGTS_PT_RESPONCE_BODY_HEADER);
}


int EGTS_responce_add_record(char *buffer, int pointer, const EGTS_RECORD& record_source,  uint16_t crn, uint8_t rst)
{
   EGTS_RECORD_HEADER::EGTS_RECORD_HEADER_RAW * record = (EGTS_RECORD_HEADER::EGTS_RECORD_HEADER_RAW *)&buffer[pointer];
   record->SST = record_source.header.record_header_raw.SST;
   record->RST = record_source.header.record_header_raw.RST;
   record->flags = 0;
   record->recordNumber = record_source.header.record_header_raw.recordNumber;



   EGTS_SUBRECORD_HEADER::EGTS_SUBRECORD_HEADER_RAW * subrecord = (EGTS_SUBRECORD_HEADER::EGTS_SUBRECORD_HEADER_RAW*)&buffer[pointer + 7];
   subrecord->type = 0;
   subrecord->length = 3; // !! заполнить ниже в общем случае

   EGTS_SUBRECORD_RECORD_RESPONCE::EGTS_SUBRECORD_RECORD_RESPONCE_RAW * responce_sdr = (EGTS_SUBRECORD_RECORD_RESPONCE::EGTS_SUBRECORD_RECORD_RESPONCE_RAW*)&buffer[pointer + 10];
   responce_sdr->CRN = crn;
   responce_sdr->RST = rst;

   EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW *pak_head = (EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW *)buffer;
   size_t size = sizeof(EGTS_RECORD_HEADER::EGTS_RECORD_HEADER_RAW) + sizeof(EGTS_SUBRECORD_HEADER::EGTS_SUBRECORD_HEADER_RAW) +
         sizeof(EGTS_SUBRECORD_RECORD_RESPONCE::EGTS_SUBRECORD_RECORD_RESPONCE_RAW);

   pak_head->dataLength += size;
   record->length = size - sizeof(EGTS_RECORD_HEADER::EGTS_RECORD_HEADER_RAW);

   return size;
}

// расчет CRC16 & CRC8 для данных егтс пакета
int packet_finalize(char *buffer, int pointer){
   EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW *pak_head = (EGTS_PACKET_HEADER::EGTS_PACKET_HEADER_RAW *)buffer;

   if( pointer - pak_head->headerLength > pak_head->dataLength )
   {
      pak_head->dataLength = pointer - pak_head->headerLength;
   }

   // добавляем CRC16 в конец пакета
   unsigned short *SFRCS = (unsigned short *)&buffer[pointer];
   // рассчитываем CRC16
   *SFRCS = CRC16EGTS( (unsigned char *)&buffer[pak_head->headerLength], pak_head->dataLength );

  // рассчитываем CRC8
   pak_head->headerCheckSum
         = CRC8EGTS((unsigned char *)pak_head, pak_head->headerLength - 1);	// последний байт это CRC

   return sizeof(unsigned short);
}
