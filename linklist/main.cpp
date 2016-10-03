#include <iostream>
#include "../include/Clinklist.h"

#define NEXT 0
#define PREV 1

#define ZNEXT 2
#define ZPREV 3

typedef Cnode<int,4> node_t;
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

	Clinklist<node_t,4> linklist;
	
	for(i=0;i<10;i++)
	{
		node_t &t=linklist.addnext(NEXT);
		linklist.addprev(&t,PREV).data=i;
	}
	
	for(i=10;i<20;i++)
	{
		node_t &t=linklist.addnext(ZNEXT);
		linklist.addprev(&t,ZPREV).data=i;
	}
	
	
	for(i=NEXT;i<=ZPREV;i++)
	show(i%2?linklist.tail[i]:linklist.head[i],i);
	

	

	return 0;
}

