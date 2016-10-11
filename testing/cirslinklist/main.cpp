#include <iostream>
#include <Ccirlinklist.h>

#define NEXT linklist_t::next
#define PREV linklist_t::prev

typedef nodetype<int>::singlylinklist node_t;
typedef Ccirsinglylinklist<node_t> linklist_t;
typedef linklist_t::headtail_t headtail_t;

using namespace std;


void show(linklist_t  &ll)
{
	node_t *temp1;
	int i;
	

	i=0,temp1=ll.head[0];
	
	do
	{
		cout<< temp1->data << endl;
		
		temp1=(*temp1)[0],i++;
		
	}while(temp1!=ll.head[0]);	
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
	
	cout << "ll2 Index 4 =" << ll2.getNode(ll2.getIndex(&ll2.getNode(4))).data << endl;
	cout << "linklist Index 4 =" << linklist.getNode(linklist.getIndex(&linklist.getNode(4))).data << endl;
	
}

