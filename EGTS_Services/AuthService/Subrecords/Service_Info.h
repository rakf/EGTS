#pragma once

#include <optional>
#include <cstdint>
#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"

class EGTS_SUBRECORD_SERVICE_INFO : public EGTS_SUBRECORD_DATA_BASE
{
public:
        EGTS_SUBRECORD_SERVICE_INFO(const char*& raw_data);

private:
	uint8_t	Service_type;	
	uint8_t	SST;		  
	uint8_t SRVP;
};