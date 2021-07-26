#pragma once

#include <cstdint>
#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"

class EGTS_SUBRECORD_AUTH_INFO  : public EGTS_SUBRECORD_DATA_BASE
{
public:
	EGTS_SUBRECORD_AUTH_INFO(const char*& raw_data);

private:
	char	UNM[32];	// User Name, имя пользователя
	char	D0;		    // Delimiter, разделитель строковых параметров (всегда имеет значение 0)
	char    UPSW[32];	// User Password, пароль пользователя
	char	D1;			// Delimiter
	char    SS[255];	/* Server Sequence, специальная серверная последовательность байт, передаваемая в подзаписи
						   EGTS_SR_AUTH_PARAMS (необязательное поле, наличие зависит от используемого
						   алгоритма шифрования) */
	char	D2;			// Delimiter
};