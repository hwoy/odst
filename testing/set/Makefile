include ../clang.mk

bin=set


.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp
clean:
	rm -f *.o $(bin)
