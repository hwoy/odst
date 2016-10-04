#include <iostream>
#include "../include/Cstack_static.h"


using namespace std;



int main()
{
	Cstack_static<int,10> stack;

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

