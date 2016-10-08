#include <iostream>
#include "../include/Clinklist_interface.h"
#include "../include/Clinklist.h"
#include "../include/Cqueue.h"


using namespace std;

typedef Cnode<int,1> node_t;
typedef Csinglylinklist<node_t> linklist_t;
typedef Clinklist_interface<linklist_t,node_t,int> linklist_if_t;
typedef Cvector_interface<linklist_if_t, int> queue_t;
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

