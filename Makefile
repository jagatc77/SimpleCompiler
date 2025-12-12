CXX = g++
CXXFLAGS = -std=c++17 -O2

all: simple_compiler

simple_compiler: src/main.cpp src/Lexer.cpp src/Parser.cpp
	$(CXX) $(CXXFLAGS) -Iinclude src/main.cpp src/Lexer.cpp src/Parser.cpp -o build/simple_compiler

clean:
	rm -f build/simple_compiler
