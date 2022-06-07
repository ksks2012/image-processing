CFLAGS = -std=c++11 -O2 -g -Wall

LIB = $(wildcard ppm/*.cpp)
all: ${target}.out

%.out: %.cpp $(LIB:%.cpp=%.o)
	g++ -o $@ $(CFLAGS) $^

clean:
	rm -rf *.o *.a *.out main
