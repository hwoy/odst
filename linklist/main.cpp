#include <iostream>
#include "../include/Clinklist.h"

#define NEXT Cdoublylinklist<node_t>::next
#define PREV Cdoublylinklist<node_t>::prev


typedef Cnode<int,2> node_t;
using namespace std;


void show(node_t *node,unsigned int index)
{
	node_t *temp1;
	int i;
	
	for(i=0,temp1=node;temp1;temp1=(*temp1)[index],i++)
	{
		cout<< temp1->data << endl;
	}	
}

int main()
{
	int i;

	Cdoublylinklist<node_t> linklist;
	
	for(i=0;i<10;i++)
	{
	  linklist.New().data=i;
	}
	
	show(linklist.head[NEXT],NEXT);
	
	show(linklist.tail[PREV],PREV);
	

	

	return 0;
}

