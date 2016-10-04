#include <iostream>
#include "../include/Cstack.h"


using namespace std;



int main()
{
	Cstack<int> stack;

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

