include ../clang.mk

bin=vector_static


.PHONY: all clean

all: $(bin)

$(bin): main.o
	$(CXX) $(LDFLAGS) -o $(bin) main.o

main.o: main.cpp ../include/Cstaticarray.h ../include/Carray.h \
 ../include/Cvector.h

clean:
	rm -f *.o $(bin)
