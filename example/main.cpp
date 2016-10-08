#include <iostream>
#include <cstdlib>
#include <time.h>
#include "../include/Cstaticarray.h"
#include "../include/Clist.h"

typedef Cvector_interface<Cstaticarray<unsigned int,16>,unsigned int> list_t;

static void dec2base(unsigned int num,unsigned int base,list_t &list)
{
	unsigned int i;
	i=num;
	do
	{
		list.push_back(i%base);
	}while(i/=base);
}

static void show(unsigned int num,list_t &list)
{
	
	std::cout << num << " = ";
	
	for(unsigned int i=0;i<list.getn();i++)
	{
		std::cout << list[i] << " ";
	}
	
	std::cout << '\n';
}

int main(void)
{
	unsigned int i,j;
	list_t list;
	
	std::srand(time(nullptr));
	
	for(j=0;j<10;j++)
	{
		i=random()%101;
		dec2base(i,2,list);
		show(i,list);
		list.setn(0);
	}
	
	return 0;
	
}
