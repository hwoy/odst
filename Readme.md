# ODS<**T**>++


ODS<**T**>++ (A.K.A Open Data Structure Template for C++) is a set of C++ template of data structure, provides

  - Array
  - Linklist
  - Vector, Stack, Queue, Deque and Set
  - Iterator
  - Util (simple and basic algorithm for data structure) unlike <algorithm>, It uses index instead of iterator

## Structure
#### Low-level structure
##### Array type
- Carray
- Cdynamicarray (interface compatibility for dynamic array)
- Cstaticarray 	(interface compatibility for static array)

##### Linked list type

- Cdoublylinklist
- Csinglylinklist
- Ccirdoublylinklist 	(not yet supported iterator)
- Ccirsinglylinklist 	(not yet supported iterator)
- Clist
- Clist_forward
- Clinklist_interface 	(High-level structure compatibility interface for linkedlist)

#### High-level structure
A.K.A Adaptor class/struct
- Cvector
- Cstack
- Cqueue
- Cdeque
- Cset

#### Iterator support
- Citerator
- Citerator_linklist
- Citerator_doublylinklist

#### Predefined structure
- vector
- stack
- queue
- deque
- set
- svector
- sstack
- squeue
- sdeque
- sset
- list
- list_forward
- cirlist
- cirlist_forward

## Requirement
- compiler: CPP11 Compiler

## Installation

```sh
$ git clone https://github.com/hwoy/odst.git
```

## About me
- Facebook: https://web.facebook.com/watt.duean
- E-mail: mailto:bosskillerz@gmail.com
