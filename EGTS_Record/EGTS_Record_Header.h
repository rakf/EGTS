#pragma once

#include <cstdint>
#include <optional>
#include "../EGTS_Services/EGTS_Services_Type.h"


struct EGTS_Record_HEADER_FLAGS_DETAIL
{
        uint8_t source_sevice_on_device;     // 1 = Сервис-отправитель расположен на стороне АТ, 0 = Сервис- отправитель расположен на ТП
        uint8_t recipient_service_on_device; // 1 = Сервис-получатель расположен на стороне АТ, 0 = Сервис-получатель расположен на ТП
        bool group;                       // принадлежность передаваемых данных определённой группе идентификатор которой указан в поле OID
        uint8_t priority;                 // приоритет обработки данной записи 00 – наивысший 01 – высокий 10 – средний 11 – низкий
        bool time_field_exists;           // наличие в данном пакете поля TM 1 = присутствует 0 = отсутствует
        bool event_field_exists;          // наличие в данном пакете поля EVID 1 = присутствует 0 = отсутствует
        bool object_id_field_exists;      // наличие в данном пакете поля OID 1 = присутствует 0 = отсутствует
};


/* flags:
Name	Bit Value
SSOD	7		1 = Сервис-отправитель расположен на стороне АТ, 0 = Сервис- отправитель расположен на ТП
RSOD	6		1 = Сервис-получатель расположен на стороне АТ, 0 = Сервис-получатель расположен на ТП
GRP		5		принадлежность передаваемых данных определённой группе идентификатор которой указан в поле OID
RPP		4-3	приоритет обработки данной записи 00 – наивысший 01 – высокий 10 – средний 11 – низкий
TMFE	2		наличие в данном пакете поля TM 1 = присутствует 0 = отсутствует
EVFE	1		наличие в данном пакете поля EVID 1 = присутствует 0 = отсутствует
OBFE	0		наличие в данном пакете поля OID 1 = присутствует 0 = отсутствует
*/


class EGTS_RECORD_HEADER
{
public:
   EGTS_RECORD_HEADER() = default;
   EGTS_RECORD_HEADER(const char*& raw_data);
   EGTS_SERVICE_TYPE getServiceSourceType() const;
   EGTS_SERVICE_TYPE getRecipientSourceType() const;

   #pragma pack(push,1)
   struct EGTS_RECORD_HEADER_RAW
   {
       uint16_t length;				   // размер данных
       uint16_t recordNumber;			   // номер записи от 0 до 65535
       uint8_t flags;					   // см.ниже
       uint8_t SST;                     // идентификатор тип Сервиса-отправителя, сгенерировавшего данную запись (=EGTS_TELEDATA_SERVICE)
       uint8_t RST;                     // идентификатор тип Сервиса-получателя данной записи (=EGTS_TELEDATA_SERVICE)
   }  record_header_raw;
    #pragma pack(pop)

   EGTS_Record_HEADER_FLAGS_DETAIL detailed_flags;
   std::optional<uint32_t> objectID;  // идентификатор объекта, сгенерировавшего данную запись, или для которого данная запись предназначена
   std::optional<uint32_t>	eventID;   // уникальный идентификатор события
   std::optional<uint32_t> time;	   // время формирования записи на стороне Отправителя (секунды с 00:00:00 01.01.2010 UTC)
};


