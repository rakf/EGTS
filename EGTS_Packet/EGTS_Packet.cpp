#include "EGTS_Packet.h"
#include "../utility.h"


//#include <netinet/in.h>
#include "../EGTS_Services/AuthService/Subrecords/Record_Responce.h"
#include "../EGTS_Record/EGTS_Record_Header.h"
#include "../EGTS_Record/EGTS_Subrecord.h"

EGTS_Packet::EGTS_Packet( const char* raw_data )
    : header( raw_data )
{
   switch ( header.getType() ) {
      case EGTS_PACKET_TYPE::EGTS_PT_APPDATA :
         body = std::make_unique< EGTS_PT_APPDATA_BODY >( header.getDataLength(), raw_data );
      break;
      case EGTS_PACKET_TYPE::EGTS_PT_RESPONSE :
         body = std::make_unique< EGTS_PT_RESPONSE_BODY >( header.getDataLength(), raw_data );
      break;
      case EGTS_PACKET_TYPE::EGTS_PT_SIGNED_APPDATA :

      break;

   }
}

EGTS_Packet::EGTS_Packet(EGTS_PACKET_HEADER& header_, std::unique_ptr< EGTS_PACKET_BODY >& body_)
{
	header = std::move(header_);
    body = std::move(body_);
}


