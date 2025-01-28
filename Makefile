CXX = g++ #compiler
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic #compiler flags

all: test

clean:
	rm -f *.o test

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test
