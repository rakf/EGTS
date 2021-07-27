TEMPLATE = app
CONFIG += console c++1x
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17
SOURCES += \
        main.cpp \
        utility.cpp \
        #
        EGTS_Packet/EGTS_Packet.cpp \
        EGTS_Packet/EGTS_Packet_Header.cpp \
        EGTS_Packet/EGTS_Packet_Body.cpp \
        #
        EGTS_Record/EGTS_Record.cpp \
        EGTS_Record/EGTS_Record_Header.cpp \
        EGTS_Record/EGTS_Record_Body.cpp \
        #
        EGTS_Record/EGTS_Subrecord.cpp \
        EGTS_Record/EGTS_Subrecord_Header.cpp \
        EGTS_Record/EGTS_Subrecord_Data.cpp \
        #
        EGTS_Services/AuthService/Subrecords/Term_Identity.cpp \
        EGTS_Services/AuthService/Subrecords/Module_Data.cpp \
        EGTS_Services/AuthService/EGTS_Auth_Service.cpp \
        EGTS_Services/AuthService/Subrecords/Auth_Info.cpp \
        EGTS_Services/AuthService/Subrecords/Auth_Params.cpp \
        EGTS_Services/AuthService/Subrecords/Record_Responce.cpp \
        EGTS_Services/AuthService/Subrecords/Result_code.cpp \
        EGTS_Services/AuthService/Subrecords/Service_Info.cpp \
        EGTS_Services/AuthService/Subrecords/Vehicle_Data.cpp \
        #
        EGTS_Services/TeledataService/Subrecords/Pos_Data.cpp \
        EGTS_Services/TeledataService/EGTS_Teledata_Service.cpp \

HEADERS += \
        utility.h \
        #
        EGTS_Packet/EGTS_Packet.h \
        EGTS_Packet/EGTS_Packet_Header.h \
        EGTS_Packet/EGTS_Packet_Body.h \
        #
        EGTS_Record/EGTS_Record.h \
        EGTS_Record/EGTS_Record_Header.h \
        EGTS_Record/EGTS_Record_Body.h \
        #
        EGTS_Record/EGTS_Subrecord.h \
        EGTS_Record/EGTS_Subrecord_Header.h \
        EGTS_Record/EGTS_Subrecord_Data.h \
        #
        EGTS_Services/EGTS_Services_Type.h \
        EGTS_Services/AuthService/Subrecords/Term_Identity.h \
        EGTS_Services/AuthService/Subrecords/Module_Data.h \
        EGTS_Services/AuthService/EGTS_Auth_Service.h \
        EGTS_Services/AuthService/Subrecords/Auth_Info.h \
        EGTS_Services/AuthService/Subrecords/Auth_Params.h \
        EGTS_Services/AuthService/Subrecords/Record_Responce.h \
        EGTS_Services/AuthService/Subrecords/Result_code.h \
        EGTS_Services/AuthService/Subrecords/Service_Info.h \
        EGTS_Services/AuthService/Subrecords/Vehicle_Data.h \
        #
        EGTS_Services/TeledataService/Subrecords/Pos_Data.h \
        EGTS_Services/TeledataService/EGTS_Teledata_Service.h
