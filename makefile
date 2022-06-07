CFLAGS = -O2 -g -Wall -Wno-unused-variable

LIB = $(wildcard ppm/*.cpp)
all: ${target}.out

%.out: %.cpp $(LIB:%.cpp=%.o)
	g++ -o $@ $(CFLAGS) $^

clean:
	rm -rf *.o *.a *.out main
