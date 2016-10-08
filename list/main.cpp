#include <iostream>
#include "../include/Cdynamicarray.h"
#include "../include/Clist.h"


using namespace std;

typedef Cvector_interface<Cdynamicarray<int>,int> vector_t;

static void show(vector_t &list)
{
	for(unsigned int i=0;i<list.getn();i++)
	  cout << list[i] << endl;

}

int main()
{
	vector_t list;
	
	for(int i=0;i<10;i++)
	  list<<i;
	
	cout << "List Element\n" ;
	show(list);
	
	list.remove(5);
	cout << "List Element ::list.remove(5)\n" ;
	show(list);
	
	list << 100 << 200;
	cout << "List Element ::list << 100 << 200\n" ;
	show(list);
	
	list.insert(10,1);
	cout << "List Element ::list.insert(10,1)\n" ;
	show(list);

	list.remove();
	cout << "List Element ::list.remove()\n" ;
	show(list);
	
	cout << "List Element ::push_back\n" ;
	list.destroy();
	for(int i=0;i<10;i++)
	  list.push(i);
	
	
	for(int i=10;i<20;i++)
	  list.push_back(i);	
	  show(list);
	
	return 0;
}

