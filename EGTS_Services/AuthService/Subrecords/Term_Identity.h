#pragma once

#include <optional>
#include <cstdint>
#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"

const static uint16_t EGTS_IMEI_LEN = 15;
const static uint16_t EGTS_IMSI_LEN = 16;
const static uint16_t EGTS_LNGC_LEN = 3;
const static uint16_t EGTS_NID_LEN = 3;
const static uint16_t EGTS_MSISDN_LEN = 15;

struct EGTS_SUBRECORD_TERM_IDENTITY_FLAGS_DETAIL
{
   bool exist_field_MSISDN; // :7	- битовый флаг, определяющий наличие поля MSISDN в подзаписи (1=передаётся, 0=не передаётся)
   bool exist_field_BS;     // :6	– битовый флаг, определяющий наличие поля BS в подзаписи (1=передаётся, 0=не передаётся)
   bool exist_field_NID;    // :5	– битовый флаг определяет наличие поля NID в подзаписи (1=передаётся, 0=не передаётся)
   bool algorithm_type;     // :4	– битовый флаг предназначен для определения алгоритма использования Сервисов (1=«простой» алгоритм, 0=«запросов» на использование сервисов)
   bool exist_field_LNGC;   // :3	– битовый флаг, который определяет наличие поля LNGC в подзаписи (1=передаётся, 0=не передаётся)
   bool exist_field_IMSI;   // :2	– битовый флаг, который определяет наличие поля IMSI в подзаписи (1=передаётся, 0=не передаётся)
   bool exist_field_IMEI;   // :1	– битовый флаг, который определяет наличие поля IMEI в подзаписи (1=передаётся, 0=не передаётся)
   bool exist_field_HDID;   // :0	– битовый флаг, который определяет наличие поля HDID в подзаписи (1=передаётся, 0=не передаётся)
};


class EGTS_SUBRECORD_TERM_IDENTITY : public EGTS_SUBRECORD_DATA_BASE
{
public:
   EGTS_SUBRECORD_TERM_IDENTITY( const char*& raw_data );

private:
   uint32_t TID;  // уникальный идентификатор, назначаемый при программировании АТ
   uint8_t	FLG;  // Flags. см выше
   EGTS_SUBRECORD_TERM_IDENTITY_FLAGS_DETAIL flags_detail;

   // Optional parameters
   std::optional< uint16_t > HDID; // идентификатор «домашней» ТП
   char IMEI[ EGTS_IMEI_LEN ];	  // идентификатор мобильного устройства
   char IMSI[ EGTS_IMSI_LEN ];	  // идентификатор мобильного абонента
   char LNGC[ EGTS_LNGC_LEN ];	  // код языка, предпочтительного к использованию на стороне АТ, по ISO 639-2, например, rus – русский
   uint8_t NID[ EGTS_NID_LEN ];	  // идентификатор сети оператора, в которой зарегистрирован АТ на данный момент
   std::optional< uint16_t > BS;	  // максимальный размер буфера приёма АТ в байтах.
   char MSISDN[ EGTS_MSISDN_LEN ]; // телефонный номер мобильного абонента. При невозможности определения данного параметра, устройство должно заполнять данное поле значением 0 во всех 15-ти символах
};


