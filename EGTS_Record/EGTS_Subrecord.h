#pragma once
#include <cstdint>
#include "EGTS_Subrecord_Header.h"
#include "EGTS_Subrecord_Data.h"
#include "../EGTS_Services/EGTS_Services_Type.h"
#include <vector>
#include <memory>

class EGTS_SUBRECORD
{
public:
   EGTS_SUBRECORD() = default;
   EGTS_SUBRECORD( EGTS_SERVICE_TYPE service_type, const char*& raw_data );

   EGTS_SERVICE_TYPE service_type;
   EGTS_SUBRECORD_HEADER header;
   EGTS_SUBRECORD_DATA data;	// данные подзаписи
};

