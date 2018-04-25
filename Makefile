CXX=g++
RM=rm -f

DEBUGFLAG=-g
CPPFLAGS=-std=c++17

SRCS=./src/AhtoAs.cpp ./src/CodeGeneration.cpp ./src/GenOptions.cpp ./src/IRCode.cpp ./src/Parser.cpp
HEADERS=./src/AhtoAs.hpp ./src/CodeGeneration.hpp ./src/GenOptions.hpp ./src/includes.hpp ./src/IRCode.hpp ./src/Parser.hpp

OBJS=$(subst ./src/,./obj/,$(subst .cpp,.o,$(SRCS)))

OUTPUT=./ahtoas


all: compile

compile:
	$(CXX) $(CPPFLAGS) -o $(OUTPUT) $(SRCS) $(HEADERS)

debug:
	$(CXX) $(CPPFLAGS) $(DEBUGFLAG) -o $(OUTPUT) $(SRCS) $(HEADERS)

clean:
	$(RM) $(OBJS)