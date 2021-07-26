#include "EGTS_Packet_Header.h"
#include "../utility.h"

EGTS_PACKET_HEADER::EGTS_PACKET_HEADER(const char*& raw_data)
{
        const unsigned char* begin_unsigned_char_data = reinterpret_cast< const unsigned char* >( raw_data );

        fillField(raw_header.protocolVersion, raw_data);
        fillField(raw_header.securityKeyID, raw_data);
        fillField(raw_header.flags, raw_data);

        detailedFlags.prefix = raw_header.flags & 192;
        detailedFlags.needRouting = raw_header.flags & 32;
        detailedFlags.encrypt = raw_header.flags & 24;
        detailedFlags.compression = raw_header.flags & 4;
        detailedFlags.priorityRouting = raw_header.flags & 3;

        fillField(raw_header.headerLength, raw_data);
        fillField(raw_header.headerEncrypt, raw_data);
        fillField(raw_header.dataLength, raw_data);
        fillField(raw_header.packedID, raw_data);
        fillField(raw_header.packetType, raw_data);

        if (detailedFlags.needRouting) // пїЅпїЅпїЅпїЅ RTE пїЅ пїЅпїЅпїЅпїЅ flags = 1, пїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ.
        {
                fillField(routingSource, raw_data);
                fillField(routingDestination, raw_data);
                fillField(routingLifeTime, raw_data);
        }

        fillField(raw_header.headerCheckSum, raw_data);
        isCorrectCheckSum = CRC8EGTS(begin_unsigned_char_data, raw_header.headerLength - 1) == raw_header.headerCheckSum;
}

EGTS_PACKET_TYPE EGTS_PACKET_HEADER::getType() const
{
        return static_cast<EGTS_PACKET_TYPE> (raw_header.packetType);
}

bool EGTS_PACKET_HEADER::IsCorrect() const
{
        return raw_header.protocolVersion == 0x01 &&
                detailedFlags.prefix == 0 &&
                isCorrectCheckSum;
}

uint16_t EGTS_PACKET_HEADER::getDataLength() const
{
	return raw_header.dataLength;
}
