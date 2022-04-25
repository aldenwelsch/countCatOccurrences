# Makefile for countCatOccurrences
# *********************************

# Program name
TARGET = CountCatOccurrences

# Source 
INCLUDE_DIR = publicHeaders
SOURCE_DIR = source
INCLUDES = $(INCLUDE_DIR)/*.hpp
SOURCES = $(SOURCE_DIR)/substringFinder.cpp $(SOURCE_DIR)/substringCounter.cpp $(SOURCE_DIR)/fileHandler.cpp $(SOURCE_DIR)/optionsHandler.cpp
MAIN = $(SOURCE_DIR)/main.cpp
OBJECTS = $(SOURCES:.cpp=.o) $(MAIN:.cpp=.o) 

# If using Linux, use GCC as compiler
CC = g++
CFLAGS = -Wall -g -I$(INCLUDE_DIR) -std=c++2a # or -std=c++20 if using later than GCC v9. Could use an older std of c++ if developing on legacy/less-supported platforms

# Build and clean the object files
all: $(TARGET) clean
	@echo Compiled $(TARGET)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Only want to clean up object files, not Target, also
clean: 
	$(RM) count $(OBJECTS)
