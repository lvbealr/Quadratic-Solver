CC = g++ # COMPILER
CFLAGS = -lgtest -lgtest_main -pthread # CONSOLE FLAGS TO COMPILE
LDFLAGS = # LINKER FLAGS
DEDFLAGS = -I/usr/include -I/usr/local/include -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
SOURCES = main.cpp coefficientInput.cpp coefficientListStruct.cpp consoleParser.cpp googleTests.cpp menu.cpp rootListStruct.cpp\
		  solver.cpp solverTest.cpp inOutStream.cpp zeroComparison.cpp # ALL .CPP FILES
OBJECTS = $(SOURCES:.cpp = .o) # ALL .O FILES
GTEST =  /usr/lib/libgtest.so.1.15.2 # PATH TO GOOGLE TEST LIBRARY1
EXECUTABLE = main # NAME OF .EXE

.PHONY: all buildDocs

all: $(SOURCES) $(EXECUTABLE) # DEFAULT DESTINATION

$(EXECUTABLE): $(OBJECTS) # DESTINATION AND ADDICTIONS
# COMPILER, LINKER FLAGS, OBJECTS + PATH TO GOOGLE TEST LIBRARY, -O, EXECUTABLE FILE
	$(CC) $(LDFLAGS) $(DEDFLAGS) $(OBJECTS) $(GTEST) -o $(EXECUTABLE)

buildDocs: 
	@doxygen Doxyfile