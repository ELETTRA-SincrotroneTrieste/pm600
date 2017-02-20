NAME_SRV = pm600-srv

SRC_FILES = ../rfc2217/src/Rfc2217.cpp ../rfc2217/src/Rfc2217Class.cpp \
	    ../rfc2217/src/Rfc2217StateMachine.cpp

CXXFLAGS = -I ../rfc2217/src -DRELEASE='"N$Name:  $ "' 
LDFLAGS = 

include ./.makefiles/Make-9.2.2.in
