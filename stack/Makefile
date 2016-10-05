include ../clang.mk

bin=stack


.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp ../include/Cstack.h ../include/Cdynamicarray.h \
 ../include/Carray.h

clean:
	rm -f *.o $(bin)
