.PHONY: all clean \
cirlinklist cirslinklist linklist vector \
vector_static queue queue_static slinklist stack stack_static example \
vector_dlinklist vector_slinklist stack_dlinklist stack_slinklist \
queue_dlinklist queue_slinklist vector_cirdlinklist vector_cirslinklist \
deque deque_static

all: cirlinklist cirslinklist linklist vector \
vector_static queue queue_static slinklist stack stack_static example \
vector_dlinklist vector_slinklist stack_dlinklist stack_slinklist \
queue_dlinklist queue_slinklist vector_cirdlinklist vector_cirslinklist \
deque deque_static


cirlinklist:
	make -C cirlinklist
cirslinklist:
	make -C cirslinklist
linklist:
	make -C linklist
vector:
	make -C vector
vector_static:
	make -C vector_static
queue:
	make -C queue
queue_static:
	make -C queue_static
slinklist:
	make -C slinklist
stack:
	make -C stack
stack_static:
	make -C stack_static
example:
	make -C example
vector_dlinklist:
	make -C vector_dlinklist
vector_slinklist:
	make -C vector_slinklist
stack_dlinklist:
	make -C stack_dlinklist
stack_slinklist:
	make -C stack_slinklist
queue_dlinklist:
	make -C queue_dlinklist
queue_slinklist:
	make -C queue_slinklist
vector_cirdlinklist:
	make -C vector_cirdlinklist
vector_cirslinklist:
	make -C vector_cirslinklist
deque:
	make -C deque -f Makefile.gcc
deque_static:
	make -C deque_static -f Makefile.gcc



clean:
	make -C cirlinklist clean ; \
	make -C cirslinklist clean ; \
	make -C linklist clean ; \
	make -C vector clean ; \
	make -C vector_static clean ; \
	make -C queue clean ; \
	make -C queue_static clean ; \
	make -C slinklist clean ; \
	make -C stack clean ; \
	make -C stack_static clean ; \
	make -C example clean; \
	make -C vector_dlinklist clean; \
	make -C vector_slinklist clean; \
	make -C stack_dlinklist clean; \
	make -C stack_slinklist clean; \
	make -C queue_dlinklist clean; \
	make -C queue_slinklist clean; \
	make -C vector_cirdlinklist clean; \
	make -C vector_cirslinklist clean
	make -C deque -f Makefile.gcc clean; \
	make -C deque_static -f Makefile.gcc clean	

