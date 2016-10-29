#include <iostream>
#include <algorithm>
#include <Cvector.h>


using namespace std;

typedef Cvector<int> vector_t;

static void show(const vector_t &vector)
{
	for(auto i:vector)
	  cout << i << endl;

}

int main()
{
	vector_t vector;
	
	for(int i=0;i<10;i++)
	  vector<<i;
	
	cout << "List Element\n" ;
	show(vector);
	
	vector.remove(5);
	cout << "List Element ::vector.remove(5)\n" ;
	show(vector);
	
	vector << 100 << 200;
	cout << "List Element ::vector << 100 << 200\n" ;
	show(vector);
	
	vector.insert(10,1);
	cout << "List Element ::vector.insert(10,1)\n" ;
	show(vector);

	vector.remove();
	cout << "List Element ::vector.remove()\n" ;
	show(vector);
	
	cout << "List Element ::push_back\n" ;
	vector.destroy();
	for(int i=0;i<10;i++)
	  vector.push(i);
	
	
	for(int i=10;i<20;i++)
	  vector.push_back(i);	
	  show(vector);
	  
	  
	 vector.destroy();
	 for(int i=0;i<10;i++)
			vector<<i;
			
	vector << 1 << 1 << 2 << 1;
	
	cout << "List Element\n" ;
	show(vector);
	
	cout << "count if n=1 = " << count(vector.begin(),vector.end(),1) << endl;
	
	
	
	
	
	return 0;
}

