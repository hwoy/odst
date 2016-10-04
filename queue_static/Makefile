bin=queue_static
CXX=clang++
CXXFLAGS=-std=c++11 -pedantic -g -Wall -stdlib=libc++
LDFLAGS=-stdlib=libc++

.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp ../include/Cqueue_static.h ../include/Cstaticarray.h \
 ../include/Carray.h

clean:
	rm -f *.o $(bin)
