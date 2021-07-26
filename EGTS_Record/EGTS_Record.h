#pragma once

#include "EGTS_Record_Header.h"
#include "EGTS_Record_Body.h"

struct EGTS_RECORD
{
   EGTS_RECORD() = default;
   EGTS_RECORD(const char*& raw_data);

   EGTS_RECORD_HEADER header;
   EGTS_RECORD_BODY body;
};


