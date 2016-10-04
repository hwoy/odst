#include <iostream>
#include "../include/Cqueue.h"


using namespace std;



int main()
{
	Cqueue<int> queue;

	for(int i=0;i<5;i++)
	queue.push(i);
	
	
	while(queue.getn())
	{
	  int *s;
	  s=queue.pop();
	  cout << *s << endl;
	  delete s;
	}
	
	
	
	return 0;
}

