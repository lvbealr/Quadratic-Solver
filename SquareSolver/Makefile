CC = g++ # COMPILER
CFLAGS = -lgtest -lgtest_main -pthread # CONSOLE FLAGS TO COMPILE
LDFLAGS = # LINKER FLAGS
SOURCES = main.cpp coefficientInput.cpp coefficientListStruct.cpp consoleParser.cpp customPrint.cpp googleTests.cpp menu.cpp rootListStruct.cpp solver.cpp solverTest.cpp stdinClean.cpp zeroComparison.cpp customAssert.cpp # ALL .CPP FILES
OBJECTS = $(SOURCES:.cpp = .o) # ALL .O FILES
GTEST = C:\TDM-GCC-64\lib\libgtest.a # PATH TO GOOGLE TEST LIBRARY
EXECUTABLE = main # NAME OF .EXE

all: $(SOURCES) $(EXECUTABLE) # DEFAULT DESTINATION

$(EXECUTABLE): $(OBJECTS) # DESTINATION AND ADDICTIONS
# COMPILER, LINKER FLAGS, OBJECTS + PATH TO GOOGLE TEST LIBRARY, -O, EXECUTABLE FILE
	$(CC) $(LDFLAGS) $(OBJECTS) $(GTEST) -o $(EXECUTABLE)
