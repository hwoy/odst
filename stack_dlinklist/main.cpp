#include <iostream>
#include "../include/Clinklist_interface.h"
#include "../include/Clinklist.h"
#include "../include/Cstack.h"


using namespace std;

typedef Cnode<int,2> node_t;
typedef Cdoublylinklist<node_t> linklist_t;
typedef Clinklist_interface<linklist_t,node_t,int> linklist_if_t;
typedef Cstack_interface<linklist_if_t, int> stack_t;


int main()
{
	stack_t stack;

	for(int i=0;i<5;i++)
	stack.push(i);
	

	while(stack.getn())
	{
	  int *s;
	  s=stack.pop();
	  cout << *s << endl;
	  delete s;
	}
	
	
	return 0;
}

