#include "Pos_Data.h"
#include "../../../utility.h"
#include <iomanip>
#include <sstream>


EGTS_SUBRECORD_POS_DATA::EGTS_SUBRECORD_POS_DATA(const char*& raw_data,  uint16_t length)
{
    auto begin = raw_data;

    fillField( raw.NTM, raw_data); // c 2010
    time_string = getDateString( raw.NTM );

    fillField( raw.LAT, raw_data);
    fillField( raw.LONG, raw_data);
    lat = 90.0 * raw.LAT / 0xFFFFFFFF;
    lon = 180.0 * raw.LONG / 0xFFFFFFFF;

    fillField( raw.FLG, raw_data);

    detailed_flag.ALT_exist = raw.FLG & 128;
    detailed_flag.is_west_longitude = raw.FLG & 64;
    detailed_flag.is_south_latitude = raw.FLG & 32;
    detailed_flag.is_moving = raw.FLG & 16;
    detailed_flag.is_black_box_data = raw.FLG & 8;
    detailed_flag.is_3d_fix = raw.FLG & 4;
    detailed_flag.coordinat_system = raw.FLG & 2;
    detailed_flag.valid = raw.FLG & 1;

    if( detailed_flag.coordinat_system )
    {
       // перевод из ПЗ 90.02 в WSG-84
    }

    fillField( raw.SPD, raw_data);
    fillField( raw.DIR, raw_data);
    fillField( raw.ODM, raw_data, 3);
    fillField( raw.DIN, raw_data);
    fillField( raw.SRC, raw_data);

    if( detailed_flag.ALT_exist ) fillField( ALT, raw_data, 3);
    if( raw.SRC >= 0 &&
        raw.SRC < 36 &&
        raw_data - begin < length) fillField( SRCD, raw_data );

    speed = (raw.SPD & 16383) / 10;
}

time_t toUTC(std::tm& timeinfo)
{
#ifdef _WIN32
    std::time_t tt = _mkgmtime(&timeinfo);
#else
    time_t tt = timegm(&timeinfo);
#endif
    return tt;
}

std::chrono::system_clock::time_point
createDateTime(int year,
               int month,
               int day,
               int hour,
               int minute,
               int second) // these are UTC values
{
    tm timeinfo1 = tm();
    timeinfo1.tm_year = year - 1900;
    timeinfo1.tm_mon = month - 1;
    timeinfo1.tm_mday = day;
    timeinfo1.tm_hour = hour;
    timeinfo1.tm_min = minute;
    timeinfo1.tm_sec = second;
    tm timeinfo = timeinfo1;
    time_t tt = toUTC(timeinfo);
    return std::chrono::system_clock::from_time_t(tt);
}


std::string getDateString( uint32_t NTM )
{
   auto date_start = createDateTime( 2010, 1, 1, 0, 0, 0 );
   auto seconds = std::chrono::duration_cast<std::chrono::seconds>(
            date_start.time_since_epoch()).count() + NTM;
   auto date_time = *gmtime(&seconds);
   std::stringstream stream;
   stream << std::put_time(&date_time, "%c %Z");
   return stream.str();
}
