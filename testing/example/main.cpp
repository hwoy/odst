#include <iostream>
#include <cstdlib>
#include <time.h>
#include <Cstaticarray.h>
#include <Cvector.h>

typedef Cvector<unsigned int,Cstaticarray<unsigned int,16> > vector_t;

static void dec2base(unsigned int num,unsigned int base,vector_t &list)
{
	unsigned int i;
	i=num;
	do
	{
		list.push_front(i%base);
	}while(i/=base);
}

static void show(unsigned int num,const vector_t &list)
{
	
	std::cout << num << " = ";
	
	for(auto &i:list)
	{
		std::cout << i << " ";
	}
	
	std::cout << '\n';
}

int main(void)
{
	unsigned int i,j;
	vector_t list;
	
	std::srand(time(nullptr));
	
	for(j=0;j<10;j++)
	{
		i=rand()%101;
		dec2base(i,2,list);
		show(i,list);
		list.clear();
	}
	
	return 0;
	
}
