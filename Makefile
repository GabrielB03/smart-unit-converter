all: converter

converter: src/main.cpp src/converter.cpp
	g++ -Iinclude -o converter src/main.cpp src/converter.cpp -std=c++17

clean:
	rm -f converter