include ../clang.mk

bin=linklist


.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp ../include/Clinklist.h ../include/Clist.h \
 ../include/Cdynamicarray.h ../include/Carray.h

clean:
	rm -f *.o $(bin)
