#pragma once

#include <vector>
#include "EGTS_Subrecord.h"
#include "../EGTS_Services/EGTS_Services_Type.h"

class EGTS_RECORD_BODY
{
public:
	EGTS_RECORD_BODY() = default;
   EGTS_RECORD_BODY( EGTS_SERVICE_TYPE service_type, const char*& raw_data );

   EGTS_SERVICE_TYPE service_type;
   std::vector< EGTS_SUBRECORD > data;
};
