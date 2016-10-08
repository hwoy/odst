include ../clang.mk

bin=stack_dll


.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp ../include/Clinklist_interface.h ../include/Clinklist.h \
 ../include/Cdynamicarray.h ../include/Carray.h ../include/Cvector.h \
 ../include/Cstack.h

clean:
	rm -f *.o $(bin)
