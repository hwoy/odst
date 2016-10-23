#include <iostream>
#include <algorithm>
#include <Carray.h>


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
	
	cout << "count if < 3 =" << count_if(array.begin(),array.end(),[](int i) {return i<3;}) << endl;

	
	return 0;
}

