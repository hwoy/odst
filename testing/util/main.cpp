#include <iostream>
#include <initializer_list>
#include <Cdynamicarray.h>
#include <Cstaticarray.h>
#include <Cvector.h>
#include <Cset.h>
#include <Cutil.h>


using namespace std;

typedef Cvector<int> _vector_t;
typedef Cset<int,Cstaticarray<int,32> > set_t;

class vector_t: public _vector_t
{
	public:
	vector_t(){}
	vector_t(const initializer_list<int> &list)
	{
		operator=(list);
	}
	vector_t& operator+=(const initializer_list<int> &list)
	{
		for(auto i:list)
		add(i);
		return *this;
	}
	vector_t& operator=(const initializer_list<int> &list)
	{
		clear();
		operator+=(list);
		return *this;
	}
};

template <typename T>
static void show(const T &t)
{
	for(auto i:t)
	  cout << i << endl;

}


ostream& operator<<(ostream &out,const vector_t &vector)
{
	show(vector);
	return out;
}

ostream& operator<<(ostream &out,const set_t &set)
{
	show(set);
	return out;
}

int main()
{
	vector_t vector,vector2;
	set_t set;
	
	vector={1,2,2,8,5,10,3,2,1};
	cout << "Show element(vector):\n";
	cout << vector << endl;
	
	cout << "Countif vector[i] == 2 :: " << countif(vector,2,_eq<int>) << endl << endl;
	cout << "Countif vector[i]  > 2 :: " << countif(vector,2,_gt<int>) << endl << endl;
	
	
	add(vector2,vector);
	cout << "Show element(vector2):\n";
	cout << vector2 << endl;
	
	cout << "find max vector :: " << vector[findm(vector,0,vector.getn(),_max<int>)] << endl << endl;
	cout << "find min vector :: " << vector[findm(vector,0,vector.getn(),_min<int>)] << endl << endl;
	
	arrang(vector2,0,vector2.getn(),_max<int>);
	cout << "max to min (vector2):\n";
	cout << vector2 << endl;
	
	arrang(vector2,0,vector2.getn(),_min<int>);
	cout << "min to max (vector2):\n";
	cout << vector2 << endl;
	
	vector2+={100,200,300,400,500};
	cout << "Show element(vector2):\n";
	cout << vector2 << endl;
	
	copy(set,vector2);
	set.pack();
	cout << "Show element(set):\n";
	cout << set << endl;	
	
	
	return 0;
}

