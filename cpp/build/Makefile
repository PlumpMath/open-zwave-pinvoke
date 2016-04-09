#
# Makefile for OpenZWave Pinvoke Wrapper Linux build
#
INC_DIR1 = -I ../../../open-zwave/cpp/src/value_classes 
INC_DIR2 = -I ../../../open-zwave/cpp/src

all:
	g++ -Wall $(INC_DIR1) $(INC_DIR2) ../src/ManagerWrapper.cpp -shared -fPIC -o libopenzwavewrapper.so  -lopenzwave
	cp libopenzwavewrapper.so /usr/lib/libopenzwavewrapper.so