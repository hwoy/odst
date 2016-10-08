#include <iostream>
#include "../include/Cstaticarray.h"
#include "../include/Cstack.h"


using namespace std;

typedef Cstack_interface<Cstaticarray<int,10>,int> stack_t;

int main()
{
	stack_t stack;

	for(int i=0;i<stack.getlength();i++)
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

