#include <iostream>
#include "../include/Cstaticarray.h"
#include "../include/Cqueue.h"


using namespace std;

typedef Cqueue_interface<Cstaticarray_base<int,10>,int> queue_t;

int main()
{
	queue_t queue;

	for(int i=0;i<queue.getlength();i++)
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

