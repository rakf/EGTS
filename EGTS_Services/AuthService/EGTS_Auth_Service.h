#pragma once

#include "../../EGTS_Record/EGTS_Subrecord_Data.h"
#include <memory>

enum class EGTS_AUTH_SERVICE_SUBRECORDS_TYPE
{
	EGTS_SR_RECORD_RESPONSE = 0,
	EGTS_SR_TERM_IDENTITY = 1,
	EGTS_SR_MODULE_DATA = 2,
	EGTS_SR_VEHICLE_DATA = 3,
	EGTS_SR_AUTH_PARAMS = 6,
	EGTS_SR_AUTH_INFO = 7,
	EGTS_SR_SERVICE_INFO = 8,
	EGTS_SR_RESULT_CODE = 9
};

class EGTS_AUTH_SERVICE
{
public:
    static std::shared_ptr< EGTS_SUBRECORD_DATA_BASE > ParseSubrecord( size_t type, const char*& raw_data );
};








