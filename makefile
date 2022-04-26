# Makefile for countCatOccurrences
# *********************************

# Program name
TARGET = CountCatOccurrences
TEST_TARGET = TestCountCatOccurrences

# Source 
INCLUDE_DIR = publicHeaders
SOURCE_DIR = source
INCLUDES = $(INCLUDE_DIR)/*.hpp
SOURCES = $(SOURCE_DIR)/substringFinder.cpp $(SOURCE_DIR)/substringCounter.cpp $(SOURCE_DIR)/fileHandler.cpp $(SOURCE_DIR)/optionsHandler.cpp $(SOURCE_DIR)/stringHelpers.cpp 
MAIN = $(SOURCE_DIR)/main.cpp
OBJECTS = $(SOURCES:.cpp=.o) #$(MAIN:.cpp=.o)

# Test Source
TEST_DIR = test
TEST_INCLUDES = $(TEST_DIR)/*.hpp
TEST_SOURCES = $(TEST_DIR)/testCountCatOccurrences.cpp
TEST_MAIN = $(TEST_DIR)/main.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o) $(TEST_MAIN:.cpp=.o)
GTEST_DIR = /usr/src/gtest/
GTEST = $(GTEST_DIR)/lib/libgtest.a
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h

LFLAGS = -lgtest -lgtest_main -lpthread

# Using Linux, use GCC as compiler
CC = g++
CFLAGS = -Wall -g -I$(INCLUDE_DIR) -std=c++2a # or -std=c++20 if using later than GCC v9. Could use an older std of c++ if developing on legacy/less-supported platforms
TEST_CFLAGS = -Wall -g -I$(GTEST_HEADERS) -pthread -std=c++2a #$(TEST_INCLUDES)

# Build the target and test application, test, and clean
all: $(TARGET) $(TEST_TARGET) test clean
	@echo $(TARGET) build complete.

# build all target objects
$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(INCLUDES) #$(TEST_INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< 

# build the target application
$(TARGET): $(OBJECTS) $(MAIN)
	$(CC) $(CFLAGS) -o $@ $^

# build all target objects
$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp $(GTEST_HEADERS)#$(TEST_INCLUDES)
	$(CC) $(CFLAGS) -pthread -c -o $@ $< 

# build the unit tests
$(TEST_TARGET): $(TEST_OBJECTS) $(OBJECTS) $(GTEST)
	$(CC) $(CFLAGS) -pthread -o $@ $^ 
#$(LFLAGS) 

# Console arguments to run with unit test application
# ARGS = 

test: ${TEST_TARGET}
	@echo Start unit test runner
	./${TEST_TARGET} ${ARGS}

# Only want to clean up object files and unit test application, not Target
clean: 
	@echo Cleaning up.
	$(RM) count $(OBJECTS) $(TEST_OBJECTS) 
#${TEST_TARGET}