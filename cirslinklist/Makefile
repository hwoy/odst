include ../clang.mk

bin=cirslinklist


.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp ../include/Ccirlinklist.h ../include/Clinklist.h \
 ../include/Cvector.h ../include/Cdynamicarray.h ../include/Carray.h

clean:
	rm -f *.o $(bin)
