#include <iostream>
#include "../include/Carray.h"


using namespace std;
int main()
{
	Carray<int,10> array;
	
	for(int i=0;i<10;i++)
	{
	  array[i]=i;
	}
	
	for(int i=0;i<10;i++)
	{
	  cout << array[i] << endl;
	}

	
	return 0;
}

