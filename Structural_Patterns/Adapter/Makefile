# File name		: Makefile
# 

Project = Adapter

CC = gcc
CFLAGS = -Wall -g -std=c17
CXX = g++
CXXFLAGS = -Wall -g -std=c++17
INCLUDES = 
LIBS = 

SRC_EXTENSIONS = .cpp .cc .c++ .cxx .CC .c .C
HDR_EXTENSIONS = .h .hpp .h++ .H .hh .HPP .HH .hxx

CUR_DIR = .
DIRS = $(shell find $(CUR_DIR) -maxdepth 5 -type d)
SOURCES = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(SRC_EXTENSIONS))))
HEADERS = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(HDR_EXTENSIONS))))
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

.PHONY : all clean rebuild show

all : $(Project)

$(Project) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(INCLUDES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.c++
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.CC
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.C
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	-rm -frv $(Project)
	-rm -frv $(OBJECTS)
	-rm -frv *.out

rebuild : clean all

show :
	@echo "Project = " $(Project)
	@echo "DIRS = " $(DIRS)
	@echo "SOURCES = " $(SOURCES)
	@echo "HEADERS = " $(HEADERS)
	@echo "OBJECTS = " $(OBJECTS)