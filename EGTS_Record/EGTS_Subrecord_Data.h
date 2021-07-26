#pragma once
#include <cstdint>
#include <vector>
#include <memory>
#include "../EGTS_Services/EGTS_Services_Type.h"

class EGTS_SUBRECORD_DATA_BASE 
{
public:
	EGTS_SUBRECORD_DATA_BASE() = default;
	virtual ~EGTS_SUBRECORD_DATA_BASE() = default;
};

class EGTS_SUBRECORD_DATA
{
public:
   EGTS_SUBRECORD_DATA() = default;
   EGTS_SUBRECORD_DATA( EGTS_SERVICE_TYPE service_type, uint8_t subrecord_type, const char*& raw_data );

	EGTS_SERVICE_TYPE service_type;
	uint8_t subrecord_type;
    std::vector< std::shared_ptr< EGTS_SUBRECORD_DATA_BASE > > data;	// данные подзаписи
};


