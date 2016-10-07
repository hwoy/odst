#include <iostream>
#include "../include/Cdynamicarray.h"
#include "../include/Cqueue.h"


using namespace std;

typedef Cqueue_interface<Cdynamicarray_base<int>,int> queue_t;

int main()
{
	queue_t queue;

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

