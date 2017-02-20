NAME_SRV = pm600-srv

SRC_FILES = ../serial2/src/Serial2.cpp ../serial2/src/Serial2Class.cpp \
	    ../serial2/src/Serial2StateMachine.cpp \
	    ../rfc2217/src/Rfc2217.cpp ../rfc2217/src/Rfc2217Class.cpp \
	    ../rfc2217/src/Rfc2217StateMachine.cpp

CXXFLAGS = -I ../serial2/src -I ../rfc2217/src -DRELEASE='"N$Name:  $ "' 
LDFLAGS = 

include ./.makefiles/Make-9.2.2.in
