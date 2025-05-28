CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC = main.cpp
TARGET = file_manager

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
