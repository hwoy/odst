#include <iostream>
#include <algorithm>
#include <Clinklist.h>


using namespace std;
typedef Clist_forward<int> linklist_t;

void show(const linklist_t  &ll)
{
	for(auto &i:ll)	
	{
		cout<< i << endl;
	}	
}

int main()
{
	int i;

	linklist_t linklist,ll2;
	
	ll2.Insert(new linklist_t::node_t,0).data=1;
	
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
	
	cout << "Index 5 =" << ll2.getNode(ll2.getIndex(&ll2.getNode(5))).data << endl;

	cout << ">=1: " << count_if(ll2.begin(),ll2.end(),[](int i){return i>=1;}) << endl;
	
	return 0;
}

