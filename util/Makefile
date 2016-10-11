include ../clang.mk

bin=util


.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp ../include/Cdynamicarray.h ../include/Carray.h \
 ../include/Cstaticarray.h ../include/Cvector.h ../include/Cset.h \
 ../include/Cutil.h ../include/Cutil.h

clean:
	rm -f *.o $(bin)
