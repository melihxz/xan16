CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
LDFLAGS = 

SRC = $(wildcard src/**/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = emulator

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
