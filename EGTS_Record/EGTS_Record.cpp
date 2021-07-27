#include "EGTS_Record.h"
#include "../utility.h"

EGTS_RECORD::EGTS_RECORD( const char*& raw_data )
    : header( raw_data )
    , body( header.getServiceSourceType(), header.record_header_raw.length, raw_data )
{
}
