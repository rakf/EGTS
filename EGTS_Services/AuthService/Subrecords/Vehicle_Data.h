#pragma once

#include <cstdint>
#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"

class EGTS_SUBRECORD_VEHICLE_DATA : public EGTS_SUBRECORD_DATA_BASE
{
public:
	EGTS_SUBRECORD_VEHICLE_DATA(const char*& raw_data);

private:
	char	    VIN[ 17 ];	    // Идентификационный номер транспортного средства
	uint32_t	vehicle_type;	// Flags. см ниже
	uint32_t	VPST;	        // тип энергоносителя транспортного средства.
								// TODO Сделать enum
};