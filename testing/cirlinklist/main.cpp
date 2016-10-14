#include <iostream>
#include <Ccirlinklist.h>

#define NEXT linklist_t::next
#define PREV linklist_t::prev

typedef nodetype<int>::doublylinklist node_t;
typedef Ccirdoublylinklist<node_t> linklist_t;
typedef linklist_t::headtail_t headtail_t;

using namespace std;


void show(const headtail_t  &ht,unsigned int index)
{
	node_t *temp1;

	
	temp1=ht[index];
	
	do{
		cout<< temp1->data << endl;
		temp1=(*temp1)[index];
	}while(temp1!=ht[index]);
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
	
	show(linklist.head,NEXT);
	
	cout << "Backward\n";
	
	show(linklist.tail,PREV);
	
	
	cout << endl;
	
	for(i=0;i<10;i++)
	cout << "linklist.getNode(" << i << ") = " << linklist.getNode(i).data << endl;
	
	linklist.Insert(1).data=12345;
	cout << "linklist.Insert(1).data=12345\n";
	show(linklist.head,NEXT);

	linklist.Insert(0).data=45678;
	cout << "linklist.Insert(0).data=45678\n";
	show(linklist.head,NEXT);
	
	linklist.Insert(11).data=90123;
	cout << "linklist.Insert(11).data=90123\n";
	show(linklist.head,NEXT);
	cout << "Backward\n";	
	show(linklist.tail,PREV);
	
	linklist.Remove(12);
	cout << "linklist.Remove(12)\n";
	show(linklist.head,NEXT);
	cout << "Backward\n";	
	show(linklist.tail,PREV);
	
	linklist.Remove((unsigned int)0);
	cout << "linklist.Remove(0)\n";
	show(linklist.head,NEXT);
	cout << "Backward\n";	
	show(linklist.tail,PREV);
	
	
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
	
	show(linklist.head,NEXT);
	
	cout << "linklist Backward\n";
	
	show(linklist.tail,PREV);
	
	
	cout << "ll2 Forward\n";
	
	show(ll2.head,NEXT);
	
	cout << "ll2 Backward\n";
	
	show(ll2.tail,PREV);
	
	

	return 0;
}
