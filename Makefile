# Project: OpenALRF

OBJ_SYSTEM = System/System.o System/SystemLinux.o
OBJ_SENSOR1D = Sensor1D/Sensor1D.o
OBJ_PILOT = Pilot/RemotePilot.o
OBJ_COMM = Communication/Communication.o
OBJ_COMMON = Common/Timing.o
OBJ_COMMAND = Command/CommandQueue.o
OBJ_CAMERA = Camera/MainCamera.o

OBJ = $(OBJ_OS) $(OBJ_COMMON) $(OBJ_DEVICES)
LINKOBJ = $(OBJ)
LIBS = 
BIN  = libOpenALRF.a
CXXINCS = 
CXXFLAGS = $(CXXINCS) -std=c++11 -fexceptions -O2
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean:
	${RM} $(LINKOBJ) $(BIN)

$(BIN): $(LINKOBJ)
	ar r $(BIN) $(LINKOBJ)
	ranlib $(BIN)

System/System.o: System/System.cpp
	$(CXX) -c System/System.cpp -o OS/System.o $(CXXFLAGS)

System/SystemLinux.o: System/SystemLinux.cpp
	$(CXX) -c System/SystemLinux.cpp -o OS/SystemLinux.o $(CXXFLAGS)

Sensor1D/Sensor1D.o: Sensor1D/Sensor1D.cpp
	$(CXX) -c Sensor1D/Sensor1D.cpp -o Sensor1D/Sensor1D.o $(CXXFLAGS)

Pilot/RemotePilot.o: Pilot/RemotePilot.cpp
	$(CXX) -c Pilot/RemotePilot.cpp -o Pilot/RemotePilot.o $(CXXFLAGS)

Communication/Communication.o: Communication/Communication.cpp
	$(CXX) -c Communication/Communication.cpp -o Communication/Communication.o $(CXXFLAGS)

Common/Timing.o: Common/Timing.cpp
	$(CXX) -c Common/Timing.cpp -o Common/Timing.o $(CXXFLAGS)

Command/CommandQueue.o: Command/CommandQueue.cpp
	$(CXX) -c Command/CommandQueue.cpp -o Command/CommandQueue.o $(CXXFLAGS)

Camera/MainCamera.o: Camera/MainCamera.cpp
	$(CXX) -c Camera/MainCamera.cpp -o Camera/MainCamera.o $(CXXFLAGS)