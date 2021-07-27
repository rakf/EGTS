TEMPLATE = app
CONFIG += console c++1x
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17
SOURCES += \
        $$PWD/main.cpp \
        $$PWD/utility.cpp \
        #
        $$PWD/EGTS_Packet/EGTS_Packet.cpp \
        $$PWD/EGTS_Packet/EGTS_Packet_Header.cpp \
        $$PWD/EGTS_Packet/EGTS_Packet_Body.cpp \
        #
        $$PWD/EGTS_Record/EGTS_Record.cpp \
        $$PWD/EGTS_Record/EGTS_Record_Header.cpp \
        $$PWD/EGTS_Record/EGTS_Record_Body.cpp \
        #
        $$PWD/EGTS_Record/EGTS_Subrecord.cpp \
        $$PWD/EGTS_Record/EGTS_Subrecord_Header.cpp \
        $$PWD/EGTS_Record/EGTS_Subrecord_Data.cpp \
        #
        $$PWD/EGTS_Services/AuthService/Subrecords/Term_Identity.cpp \
        $$PWD/EGTS_Services/AuthService/Subrecords/Module_Data.cpp \
        $$PWD/EGTS_Services/AuthService/EGTS_Auth_Service.cpp \
        $$PWD/EGTS_Services/AuthService/Subrecords/Auth_Info.cpp \
        $$PWD/EGTS_Services/AuthService/Subrecords/Auth_Params.cpp \
        $$PWD/EGTS_Services/AuthService/Subrecords/Record_Responce.cpp \
        $$PWD/EGTS_Services/AuthService/Subrecords/Result_code.cpp \
        $$PWD/EGTS_Services/AuthService/Subrecords/Service_Info.cpp \
        $$PWD/EGTS_Services/AuthService/Subrecords/Vehicle_Data.cpp \
        #
        $$PWD/EGTS_Services/TeledataService/Subrecords/Pos_Data.cpp \
        $$PWD/EGTS_Services/TeledataService/EGTS_Teledata_Service.cpp \
        $$PWD/EGTS_Services/TeledataService/Subrecords/Ext_Pos_Data.cpp \

HEADERS += \
        $$PWD/utility.h \
        #
        $$PWD/EGTS_Packet/EGTS_Packet.h \
        $$PWD/EGTS_Packet/EGTS_Packet_Header.h \
        $$PWD/EGTS_Packet/EGTS_Packet_Body.h \
        #
        $$PWD/EGTS_Record/EGTS_Record.h \
        $$PWD/EGTS_Record/EGTS_Record_Header.h \
        $$PWD/EGTS_Record/EGTS_Record_Body.h \
        #
        $$PWD/EGTS_Record/EGTS_Subrecord.h \
        $$PWD/EGTS_Record/EGTS_Subrecord_Header.h \
        $$PWD/EGTS_Record/EGTS_Subrecord_Data.h \
        #
        $$PWD/EGTS_Services/EGTS_Services_Type.h \
        $$PWD/EGTS_Services/AuthService/Subrecords/Term_Identity.h \
        $$PWD/EGTS_Services/AuthService/Subrecords/Module_Data.h \
        $$PWD/EGTS_Services/AuthService/EGTS_Auth_Service.h \
        $$PWD/EGTS_Services/AuthService/Subrecords/Auth_Info.h \
        $$PWD/EGTS_Services/AuthService/Subrecords/Auth_Params.h \
        $$PWD/EGTS_Services/AuthService/Subrecords/Record_Responce.h \
        $$PWD/EGTS_Services/AuthService/Subrecords/Result_code.h \
        $$PWD/EGTS_Services/AuthService/Subrecords/Service_Info.h \
        $$PWD/EGTS_Services/AuthService/Subrecords/Vehicle_Data.h \
        #
        $$PWD/EGTS_Services/TeledataService/Subrecords/Pos_Data.h \
        $$PWD/EGTS_Services/TeledataService/EGTS_Teledata_Service.h \
        $$PWD/EGTS_Services/TeledataService/Subrecords/Ext_Pos_Data.h \
