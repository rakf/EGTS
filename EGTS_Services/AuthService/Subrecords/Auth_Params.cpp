#include "Auth_Params.h"
#include "../../../utility.h"

EGTS_SUBRECORD_AUTH_PARAMS::EGTS_SUBRECORD_AUTH_PARAMS( const char*& raw_data )
{
	fillField(flags, raw_data);

	detailed_flags.exist_field_EXP = flags & 64;
	detailed_flags.exist_field_SS = flags & 32;
	detailed_flags.exist_field_MSZ = flags & 16;
	detailed_flags.exist_field_ISL = flags & 8;
	detailed_flags.exist_fields_PKL_PBK = flags & 4;
	detailed_flags.encrypt_algo_params = flags & 3;

	if (detailed_flags.encrypt_algo_params) return;


	if(detailed_flags.exist_fields_PKL_PBK)
	{
		fillField(public_key_length, raw_data);
		fillField(public_key, raw_data, *public_key_length);
	}

	if (detailed_flags.exist_field_ISL) fillField(ISL, raw_data);

	if (detailed_flags.exist_field_MSZ) fillField(MSZ, raw_data);

	if (detailed_flags.exist_field_MSZ)
	{
		fillField(SS, raw_data);
		fillField(delim_1, raw_data);
	}

	if (detailed_flags.exist_field_EXP)
	{
		fillField(EXP, raw_data);
		fillField(delim_2, raw_data);
	}
}
