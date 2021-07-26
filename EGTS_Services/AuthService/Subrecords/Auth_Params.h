#pragma once

#include <optional>
#include <cstdint>
#include "../../../EGTS_Record/EGTS_Subrecord_Data.h"

struct EGTS_SUBRECORD_AUTH_PARAMS_FLAGS_DETAILED
{
	bool exist_field_EXP;
	bool exist_field_SS;
	bool exist_field_MSZ;
	bool exist_field_ISL;
	bool exist_fields_PKL_PBK;
	uint8_t encrypt_algo_params;
};

class EGTS_SUBRECORD_AUTH_PARAMS : public EGTS_SUBRECORD_DATA_BASE
{
public:
        EGTS_SUBRECORD_AUTH_PARAMS(const char*& raw_data);

private:
	uint8_t	              flags;
	EGTS_SUBRECORD_AUTH_PARAMS_FLAGS_DETAILED detailed_flags;

	// Optional
	std::optional< uint16_t > public_key_length;
	uint8_t  public_key[ 512 ];	
	std::optional < uint16_t > ISL;
	std::optional < uint16_t > MSZ;
	char SS[255];
	std::optional<uint8_t> delim_1;
	char EXP[255];
	std::optional<uint8_t> delim_2;
};