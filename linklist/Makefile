bin=linklist
CXX=clang++
CXXFLAGS=-std=c++11 -g -Wall -pedantic -stdlib=libc++
LDFLAGS=-stdlib=libc++


all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp ../include/Carray.h

clean:
	rm -f *.o $(bin)
