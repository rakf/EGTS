#pragma once

#include "../../EGTS_Record/EGTS_Subrecord_Data.h"
#include <memory>

enum class EGTS_TELEDATA_SERVICE_SUBRECORDS_TYPE
{
	EGTS_SR_RECORD_RESPONSE = 0,
	EGTS_SR_POS_DATA = 16,
	EGTS_SR_EXT_POS_DATA = 17,
	EGTS_SR_AD_SENSORS_DATA = 18,
	EGTS_SR_COUNTERS_DATA = 19,
	EGTS_SR_STATE_DATA = 20,
	EGTS_SR_LOOPIN_DATA = 22,
	EGTS_SR_ABS_DIG_SENS_DATA = 23,
	EGTS_SR_ABS_AN_SENS_DATA = 24,
	EGTS_SR_ABS_CNtr_DATA = 25,
	EGTS_SR_ABS_LOOPIN_DATA = 26,
	EGTS_SR_LIQUID_LEVEL_SENSOR = 27,
	EGTS_SR_PASSENGERS_COUNTERS = 28
};

class EGTS_TELEDATA_SERVICE
{
public:
    static std::shared_ptr< EGTS_SUBRECORD_DATA_BASE > ParseSubrecord( size_t type, uint16_t length, const char*& raw_data );
};








