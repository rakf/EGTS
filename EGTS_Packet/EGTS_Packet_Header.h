#pragma once
#include <cstdint>
#include <optional>


enum class EGTS_PACKET_TYPE
{
        EGTS_PT_RESPONSE,        // 0
        EGTS_PT_APPDATA,         // 1
        EGTS_PT_SIGNED_APPDATA	// 2
};

/* PRF:
Name	Bit Value
PRF		7-6	префикс заголовка Транспортного Уровня и для данной версии должен содержать значение 00
RTE		5   определяет необходимость дальнейшей маршрутизации = 1, то необходима и поля PRA, RCA, TTL присутствуют в пакете
ENA		4-3	шифрование данных из поля SFRD, значение 0 0 , то данные в поле SFRD не шифруются
CMP		2	сжатие данных из поля SFRD, = 1, то данные в поле SFRD считаются сжатыми
PR		1-0	приоритет маршрутизации, 00-высший 10–средний 11-низкий
*/
struct EGTS_PACKET_HEADER_FLAGS_DETAIL
{
        uint8_t prefix;
        bool needRouting;
        uint8_t encrypt;
        bool	compression;
        uint8_t priorityRouting;
};

class EGTS_PACKET_HEADER
{
public:
	    EGTS_PACKET_HEADER() = default; 
        EGTS_PACKET_HEADER(const char*& raw_data);
        EGTS_PACKET_TYPE getType() const;
		uint16_t getDataLength() const;
        bool IsCorrect() const;

      #pragma pack(push,1)
		struct EGTS_PACKET_HEADER_RAW
		{
         uint8_t            protocolVersion;	// Параметр определяет версию используемой структуры заголовка и должен содержать значение 0x01
			uint8_t			    securityKeyID;	// (Security Key ID) идентификатор ключа, используемый при шифровании
			uint8_t			    flags;		// Flags: см. выше
			uint8_t			    headerLength;	// Длина заголовка Транспортного Уровня в байтах с учётом байта контрольной суммы (поля HCS)
			uint8_t			    headerEncrypt;	// метод кодирования следующей за данным параметром части заголовка Транспортного Уровня = 0
         uint16_t           dataLength;		// размер в байтах поля данных SFRD, если 0: отправка EGTS_PT_RESPONSE с RPID=PID и PR=EGTS_PC_OK
         uint16_t           packedID;		// номер пакета Транспортного Уровня от 0 до 65535
         uint8_t            packetType;		// Тип пакета Транспортного Уровня
			uint8_t			    headerCheckSum;	// Контрольная сумма заголовка CRC-8
		} raw_header;
      #pragma pack(pop)

        EGTS_PACKET_HEADER_FLAGS_DETAIL	    detailedFlags;      // Подробная роспись флагов

        std::optional< uint16_t >   routingSource;	// Адрес аппаратно-программного комплекса, на котором данный пакет сгенерирован.
        std::optional< uint16_t >   routingDestination;	// Адрес аппаратно-программного комплекса, для которого данный пакет предназначен.
        std::optional< uint8_t >    routingLifeTime;	// Время жизни пакета при его маршрутизации между аппаратно-программными комплексами.
        bool			    isCorrectCheckSum;	// Совпадает ли контрольная сумма с вычисленной.

};



