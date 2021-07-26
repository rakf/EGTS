#include "utility.h"


unsigned char CRC8EGTS( const unsigned char *lpBlock, unsigned char len)
{
        unsigned char crc = 0xFF;
        while (len--)
                crc = CRC8Table[crc ^ *lpBlock++];
        return crc;
}

unsigned short CRC16EGTS( const unsigned char * pcBlock, unsigned short len)
{
	unsigned short crc = 0xFFFF;
	while (len--)
		crc = (crc << 8) ^ Crc16Table[(crc >> 8) ^ *pcBlock++];
	return crc;
}