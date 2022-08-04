all: proj3.x test_stack.x

proj3.cpp.x: proj3.cpp Stack.hpp Stack.x
	g++ proj3.cpp -o proj3.x -std=c++11

Stack.x: Stack.h test_stack.cpp
	g++ -o Stack.x Stack.h test_stack.cpp -std=gnu++11

clean:
	rm -f *.x stack
