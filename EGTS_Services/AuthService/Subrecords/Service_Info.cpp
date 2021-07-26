#include "Service_Info.h"
#include "../../../utility.h"

EGTS_SUBRECORD_SERVICE_INFO::EGTS_SUBRECORD_SERVICE_INFO( const char*& raw_data )
{
	fillField(Service_type, raw_data);
	fillField(SST, raw_data);
	fillField(SRVP, raw_data);
}
