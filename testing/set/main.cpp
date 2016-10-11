#include <iostream>
#include <initializer_list>

#include <Cdynamicarray.h>
#include <Cset.h>
#include <Cutil.h>

using namespace std;


typedef Cset_interface<Cdynamicarray<int>,int> _set_t;

class set_t:public _set_t
{
	public:
	set_t(){}
	
	set_t(const initializer_list<int> &l)
	{
		for(auto i:l)
		add(i);
	}
	
	set_t& operator=(const initializer_list<int> &l)
	{
		clear();
		for(auto i:l)
		add(i);
		return *this;
	}
};

static void show(set_t &set)
{
	for(auto i:set)
	 cout << i << ": " << i << endl;

}


int main()
{
	unsigned int i;
	set_t set,set2,set3;
	
	set ={ 1 , 5 ,2 ,3 , 1 , 2 ,5 , 4 , 4 , 4};
	
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
	
	set3 ={ 10 ,2 ,100 ,200};
	
	cout << "SET3 List Elements\n";
	show(set3);
	
	set.sub(set3);
	cout << "SET1 List Elements:sub\n";
	show(set);
	
	cout << "Max of set =" << set[findm(set,0,set.getn(),_max<int>)] << endl;
	cout << "Min of set =" << set[findm(set,0,set.getn(),_min<int>)] << endl;
	
	cout << "SET2" << endl;
	show(set2);
	
	arrang(set2,0,set2.getn(),_min<int>);
	cout << "SET2 Arranged " << endl;
	show(set2);
	
	
	
	
	return 0;
}

