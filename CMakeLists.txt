cmake_minimum_required (VERSION 3.8)
 
project(EGTS_PARSER)

set(CMAKE_CXX_STANDARD 17)
 
set(SOURCE_FILES 
${CMAKE_CURRENT_SOURCE_DIR}/utility.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Packet/EGTS_Packet.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Packet/EGTS_Packet_Header.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Packet/EGTS_Packet_Body.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Record.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Record_Header.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Record_Body.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Subrecord.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Subrecord_Header.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Subrecord_Data.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Subrecord_Record_Responce.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Term_Identity.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Module_Data.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/EGTS_Auth_Service.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Auth_Info.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Auth_Params.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Result_code.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Service_Info.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Vehicle_Data.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/Pos_Data.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/EGTS_Teledata_Service.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/Ext_Pos_Data.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/State_Data.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/Ad_Sensors_Data.cpp
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/Counters_Data.cpp
)

set(HEADER_FILES 
${CMAKE_CURRENT_SOURCE_DIR}/utility.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Packet/EGTS_Packet.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Packet/EGTS_Packet_Header.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Packet/EGTS_Packet_Body.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Record.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Record_Header.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Record_Body.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Subrecord.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Subrecord_Header.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Subrecord_Data.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Record/EGTS_Subrecord_Record_Responce.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Term_Identity.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Module_Data.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/EGTS_Auth_Service.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Auth_Info.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Auth_Params.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Result_code.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Service_Info.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/AuthService/Subrecords/Vehicle_Data.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/Pos_Data.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/EGTS_Teledata_Service.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/Ext_Pos_Data.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/State_Data.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/Ad_Sensors_Data.h
${CMAKE_CURRENT_SOURCE_DIR}/EGTS_Services/TeledataService/Subrecords/Counters_Data.h
)
 
# объявляем проект как статическую библиотеку и добавляем в него все файлы исходных кодов
add_library(EGTS_PARSER STATIC ${HEADER_FILES} ${SOURCE_FILES})
