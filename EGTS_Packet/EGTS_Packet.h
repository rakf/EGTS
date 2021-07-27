#pragma once
#include "EGTS_Packet_Header.h"
#include "EGTS_Packet_Body.h"
#include <memory>

class EGTS_Packet
{
public:
	EGTS_Packet() = default;
    EGTS_Packet( const char* raw_data );
	EGTS_Packet(EGTS_PACKET_HEADER& header, std::unique_ptr< EGTS_PACKET_BODY >& body);

    EGTS_PACKET_HEADER header;
    std::unique_ptr< EGTS_PACKET_BODY > body;
};







// пока не реализовано
class EGTS_PT_RESPONSE_HEADER 
{
public:
    EGTS_PT_RESPONSE_HEADER(const char*& raw_data);

private:
	EGTS_PACKET_HEADER header;
        uint16_t	RPID;	// Идентификатор пакета Транспортного Уровня, подтверждение на который сформировано EGTS_PACKET_HEADER.PID
        uint8_t		PR;		// Код результата обработки части Пакета, относящейся к Транспортному Уровню
};

class EGTS_SR_RECORD_RESPONSE_RECORD
{
public:
        EGTS_SR_RECORD_RESPONSE_RECORD(const char* raw_data);

private:
        uint16_t	CRN;	// номер подтверждаемой записи (значение поля RN из обрабатываемой записи)
        uint8_t	RST;	// статус обработки записи
};
