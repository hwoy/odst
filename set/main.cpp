#include <iostream>
using namespace std;

#include "../include/Cdynamicarray.h"
#include "../include/Cset.h"



typedef Cset_interface<Cdynamicarray<int>,int> set_t;

static void show(set_t &set)
{
	for(unsigned int i=0;i<set.getn();i++)
	 cout << i << ": " << set[i] << endl;

}

int main()
{
	unsigned int i;
	set_t set,set2;
	
	set << 1 << 5 << 2 << 3 << 1 << 2 <<5 << 4 << 4 << 4;
	
	set2 << 20 << 1 << 10 << 2 << 30 << 20 << 30;
	
	cout << "SET1 List Elements\n";
	show(set);
	
	cout << "SET2 List Elements\n";
	show(set2);
	
	i=set._union(set2);
	cout << "SET1 List Elements:Union\n";
	show(set);
	cout << "SET1 N of Union = " << i << endl;
	
	i=set.intersect(set2);
	cout << "SET1 List Elements:Intersect\n";
	show(set);
	cout << "SET1 N of Intersect = " << i << endl;	
	
	i=set.pack();
	cout << "SET1 List Elements:pack()\n";
	show(set);
	cout << "SET1 N of Deletion = " << i << endl;
	
	
	
	
	
	return 0;
}

