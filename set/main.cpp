#include <iostream>
#include "../include/Cdynamicarray.h"
#include "../include/Cset.h"


using namespace std;

typedef Cset_interface<Cdynamicarray<int>,int> set_t;

static void show(set_t &set)
{
	for(unsigned int i=0;i<set.getn();i++)
	  cout << set[i] << endl;

}

int main()
{
	unsigned int i;
	set_t set;
	
	set << 1 << 5 << 2 << 3 << 1 << 2 <<5 << 4;
	
	cout << "SET1 List Elements\n";
	show(set);
	
	i=set.pack();
	cout << "SET1 List Elements:pack()\n";
	show(set);
	cout << "SET1 N of Deletion = " << i << endl;
	
	
	
	
	
	
	return 0;
}

