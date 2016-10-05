#include <iostream>
#include "../include/Clinklist.h"

#define NEXT linklist_t::next
#define PREV linklist_t::prev

typedef nodetype<int>::singlylinklist node_t;
typedef Csinglylinklist<node_t> linklist_t;
typedef linklist_t::headtail_t headtail_t;

using namespace std;


void show(linklist_t  &ll)
{
	node_t *temp1;
	int i;
	
	for(i=0,temp1=ll.head[0];temp1;temp1=(*temp1)[0],i++)
	{
		cout<< temp1->data << endl;
	}	
}

int main()
{
	int i;

	linklist_t linklist,ll2;
	
	for(i=0;i<10;i++)
	{
	  linklist.New().data=i;
	}
	
	cout << "Forward\n";
	
	show(linklist);
	
	linklist.Insert(1).data=12345;
	cout << "linklist.Insert(1).data=12345\n";
	show(linklist);

	linklist.Insert(0).data=45678;
	cout << "linklist.Insert(0).data=45678\n";
	show(linklist);
	
	linklist.Insert(11).data=90123;
	cout << "linklist.Insert(11).data=90123\n";
	show(linklist);

	linklist.Remove(12);
	cout << "linklist.Remove(12)\n";
	show(linklist);

	
	linklist.Remove((unsigned int)0);
	cout << "linklist.Remove(0)\n";
	show(linklist);

	linklist.Remove((unsigned int)0);
	cout << "linklist.Remove(0)\n";
	show(linklist);

	linklist.Destroy();
	for(i=0;i<10;i++)
	{
	  linklist.New().data=i;
	}

	for(i=0;i<5;i++)
	{
	  ll2.Add(linklist.Split((unsigned int)0));
	}
	
	
	cout << "linklist Forward\n";
	
	show(linklist);
	
	
	cout << "ll2 Forward\n";
	
	show(ll2);
	
	return 0;
}

