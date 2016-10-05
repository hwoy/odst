.PHONY: all clean \
cirlinklist cirslinklist linklist list \
list_static queue queue_static slinklist stack stack_static example

all: cirlinklist cirslinklist linklist list \
list_static queue queue_static slinklist stack stack_static example

cirlinklist:
	make -C cirlinklist
cirslinklist:
	make -C cirslinklist
linklist:
	make -C linklist
list:
	make -C list
list_static:
	make -C list_static
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

clean:
	make -C cirlinklist clean ; \
	make -C cirslinklist clean ; \
	make -C linklist clean ; \
	make -C list clean ; \
	make -C list_static clean ; \
	make -C queue clean ; \
	make -C queue_static clean ; \
	make -C slinklist clean ; \
	make -C stack clean ; \
	make -C stack_static clean ; \
	make -C example clean
	

