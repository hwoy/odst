#include <iostream>
#include "../include/Cqueue_static.h"


using namespace std;



int main()
{
	Cqueue_static<int,10> queue;

	for(int i=0;i<queue.getlength();i++)
	queue.push(i);
	
	
	while(queue.getn())
	{
	  int *s;
	  s=queue.pop();
	  cout << *s << endl;
	  delete s;
	}
	
	
	
	return 0;
}

