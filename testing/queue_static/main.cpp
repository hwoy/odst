#include <iostream>
#include <Cstaticarray.h>
#include <Cqueue.h>


using namespace std;

typedef Cqueue_interface<Cstaticarray<int,10>,int> queue_t;

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
