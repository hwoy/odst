#include <iostream>
#include "../include/Cdynamicarray.h"
#include "../include/Cstack.h"


using namespace std;

typedef Cstack_interface<Cdynamicarray<int>,int> stack_t;


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

