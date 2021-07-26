// EGTS_parser.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string_view>
#include <optional>

// Тип пакета Транспортного Уровня
const unsigned int EGTS_PT_RESPONSE = 0;
const unsigned int EGTS_PT_APPDATA = 1;
const unsigned int EGTS_PT_SIGNED_APPDATA = 2;
 


class EGTS_PACKET_HEADER
{
public:

	EGTS_PACKET_HEADER(std::string_view raw_data, size_t& pointer);
	EGTS_PACKET_HEADER(const uint8_t* raw_data);

	bool IsCRCCorrect();

private:
	uint8_t						PRV;	// (Protocol Version) Параметр определяет версию используемой структуры заголовка и должен содержать значение 0x01
	uint8_t						SKID;	// (Security Key ID) идентификатор ключа, используемый при шифровании
	uint8_t						PRF;	// Flags: см. ниже
	uint8_t						HL;		// Длина заголовка Транспортного Уровня в байтах с учётом байта контрольной суммы (поля HCS)
	uint8_t						HE;		// метод кодирования следующей за данным параметром части заголовка Транспортного Уровня = 0
	uint16_t					FDL;	// размер в байтах поля данных SFRD, если 0: отправка EGTS_PT_RESPONSE с RPID=PID и PR=EGTS_PC_OK
	uint16_t					PID;	// номер пакета Транспортного Уровня от 0 до 65535
	uint8_t						PT;		// Тип пакета Транспортного Уровня
	std::optional< uint16_t >   PRA;    // Адрес аппаратно-программного комплекса, на котором данный пакет сгенерирован.
	std::optional< uint16_t >   RSA;	// Адрес аппаратно-программного комплекса, для которого данный пакет предназначен.
	std::optional< uint8_t >	TTL;	// Время жизни пакета при его маршрутизации между аппаратно-программными комплексами.
	uint8_t						HCS;	// Контрольная сумма заголовка CRC-8
};

/* PRF:
Name	Bit Value
PRF		7-6	префикс заголовка Транспортного Уровня и для данной версии должен содержать значение 00
RTE		5   определяет необходимость дальнейшей маршрутизации = 1, то необходима и поля PRA, RCA, TTL присутствуют в пакете
ENA		4-3	шифрование данных из поля SFRD, значение 0 0 , то данные в поле SFRD не шифруются
CMP		2	сжатие данных из поля SFRD, = 1, то данные в поле SFRD считаются сжатыми
PR		1-0	приоритет маршрутизации, 00-высший 10–средний 11-низкий
*/


EGTS_PACKET_HEADER::EGTS_PACKET_HEADER(std::string_view raw_data, size_t& pointer)
{
	//raw_data.copy(PRV, 1);
}

EGTS_PACKET_HEADER::EGTS_PACKET_HEADER(const uint8_t* raw_data) 
{
	fillField(PRV, raw_data);
	fillField(SKID, raw_data);
	fillField(PRF, raw_data);
	fillField(HL, raw_data);
	fillField(HE, raw_data);
	fillField(FDL, raw_data);
	fillField(PID, raw_data);
	fillField(PRV, raw_data);
	fillField(PT, raw_data);
	
	if (PRF |= 4) // Флаг RTE в поле PRF = 1, то нужна дальнейшая маршрутизация и присутствуют дополнительные поля. 
	{
		fillField(PRA, raw_data);
		fillField(RSA, raw_data);
		fillField(TTL, raw_data);
	}
	fillField(HCS, raw_data);
}

/* PRF:
Name	Bit Value
PRF		7-6	префикс заголовка Транспортного Уровня и для данной версии должен содержать значение 00
RTE		5   определяет необходимость дальнейшей маршрутизации = 1, то необходима и поля PRA, RCA, TTL присутствуют в пакете
ENA		4-3	шифрование данных из поля SFRD, значение 0 0 , то данные в поле SFRD не шифруются
CMP		2	сжатие данных из поля SFRD, = 1, то данные в поле SFRD считаются сжатыми
PR		1-0	приоритет маршрутизации, 00-высший 10–средний 11-низкий
*/
/* PT
0 – EGTS_PT_RESPONSE (подтверждение на пакет Транспортного Уровня);
1 – EGTS_PT_APPDATA (пакет, содержащий данные Протокола Уровня Поддержки Услуг);
2 – EGTS_PT_SIGNED_APPDATA (пакет, содержащий данные Протокола Уровня Поддержки Услуг с цифровой подписью);
*/

/* SFRD
В зависимости от типа пакета EGTS_PACKET_HEADER.PT структура поля SFRD имеет различный
формат.
EGTS_PACKET_HEADER.PT = EGTS_PT_APPDATA
	SFRD {
		SDR 1	(Service Data Record)
		[
		SDR 2
		SDR n
		]
	}
где SDR = {
	EGTS_SDR
	[	SRD 1 (Subrecord Data) 	]
	[	SRD 2	]
	...
}
где SDR = EGTS_SR_POS_DATA_RECORD, например
EGTS_PACKET_HEADER.PT = EGTS_PT_RESPONSE
	SFRD {
	EGTS_PT_RESPONSE_HEADER
		[
		SDR 1	(Service Data Record)
		SDR 2
		SDR n
		]
	}
где SDR = ?
EGTS_PACKET_HEADER.PT = EGTS_PT_SIGNED_APPDATA
обрабатывать не будем.
*/





typedef struct {
	uint8_t		SRT;	// тип подзаписи EGTS_SR_TERM_IDENTITY/EGTS_SR_POS_DATA/... (see RD_HEADER.SRT: below)
	uint16_t	SRL;	// длина данных в байтах подзаписи SRD (Subrecord Data)
} EGTS_SUBRECORD_HEADER;

typedef struct {
	std::vector< uint8_t > DATA;	// тип подзаписи EGTS_SR_TERM_IDENTITY/EGTS_SR_POS_DATA/... (see RD_HEADER.SRT: below)
} EGTS_SUBRECORD_DATA;

typedef struct {
	EGTS_SUBRECORD_HEADER mHeader;
	EGTS_SUBRECORD_DATA mData;
} EGTS_SUBRECORD;

typedef struct {
	uint16_t	RL;		// размер данных из поля RD
	uint16_t	RN;		// номер записи от 0 до 65535
	uint8_t		RFL;	// битовые флаги
	// необязательные поля
	uint32_t	OID;	// идентификатор объекта, сгенерировавшего данную запись, или для которого данная запись предназначена
	uint32_t	EVID;	// уникальный идентификатор события
	uint32_t  TM;		// время формирования записи на стороне Отправителя (секунды с 00:00:00 01.01.2010 UTC)
	// обязательные поля
	uint8_t		SST;	// идентификатор тип Сервиса-отправителя, сгенерировавшего данную запись (=EGTS_TELEDATA_SERVICE)
	uint8_t		RST;	// идентификатор тип Сервиса-получателя данной записи (=EGTS_TELEDATA_SERVICE)
} EGTS_RECORD_HEADER; // SDR HEADER

typedef struct {
	std::vector< EGTS_SUBRECORD > mData;
} EGTS_RECORD_DATA;

typedef struct {
	EGTS_RECORD_HEADER mHeader;
	EGTS_RECORD_DATA mData;
} EGTS_RECORD;
/*
EGTS_PACKET
{
	EGTS_PACKET_HEADER   Заголовки пакета.
	EGTS_PACKET_SFRD	 Структура данных, хранящая основные данные. Зависит от типа Пакета EGTS_PACKET_HEADER.PT
	EGTS_PACKET_SFRCS	 Контрольная сумма SFRD CRC - 16
}

EGTS_PACKET_SFRD
{
	EGTS_RECORD_HEADER
	EGTS_RECORD_DATA
}

EGTS_RECORD_DATA
{
	EGTS_SUBRECORD_HEADER
	EGTS_SUBRECORD_DATA
}
*/

// Класс, описывающий пакет данных протокола EGTS
class EGTS_PACKET
{
public:

	EGTS_PACKET( const char* raw_data );

private:

	void ParsePacket( std::string_view raw_data );

	EGTS_RECORD_HEADER mHeader;
	EGTS_RECORD mSFRD;
	unsigned short mSFRCS;

	std::string_view mRawData;
	const uint8_t* mRawDataUnsigned;
};

EGTS_PACKET::EGTS_PACKET(const char* raw_data)
	: mRawData(raw_data)
	, mRawDataUnsigned( reinterpret_cast<const uint8_t*>(raw_data) ) {}

void EGTS_PACKET::ParsePacket(std::string_view raw_data)
{
	size_t pointer = 0;
	//mHeader = EGTS_RECORD_HEADER(raw_data, pointer);

}

namespace 
{

typedef unsigned char BYTE;

static inline bool is_base64(BYTE c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
}

static const std::string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";



std::string base64_decode(std::string const& encoded_string) {
	int in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	std::string ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i < 4; i++)
				char_array_4[i] = base64_chars.find(char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret += char_array_3[i];
			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; j++)
			char_array_4[j] = 0;

		for (j = 0; j < 4; j++)
			char_array_4[j] = base64_chars.find(char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
	}

	return ret;
}
}


int main()
{
	std::string base64 = "AQBCAzg2MjUzMTA0MzQ5OTg4OQUCAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB2";
	auto raw_data_string = base64_decode(base64);
	auto raw_data_unsigned = reinterpret_cast<const uint8_t*>(raw_data_string.c_str());
	EGTS_PACKET_HEADER header(raw_data_unsigned);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
