CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

TARGET = main
SOURCE = src/main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)