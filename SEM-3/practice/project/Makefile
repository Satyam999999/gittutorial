CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = file_organizer
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
