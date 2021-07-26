#include "Vehicle_Data.h"
#include "../../../utility.h"

EGTS_SUBRECORD_VEHICLE_DATA::EGTS_SUBRECORD_VEHICLE_DATA( const char*& raw_data )
{
	fillField(VIN, raw_data);
	fillField(vehicle_type, raw_data);
	fillField(VPST, raw_data);
}
