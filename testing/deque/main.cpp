#include <iostream>
#include <Cdynamicarray.h>
#include <Cdeque.h>


using namespace std;

typedef Cdeque_interface<Cdynamicarray<int>,int> deque_t;

void show(deque_t &queue,unsigned int i)
{
	cout << ((i==1)?"Show front":"show back") << endl;
	while(queue.getn())
	{
	  int *s;
	  s=(i==1)?queue.pop_front():queue.pop_back();
	  cout << *s << endl;
	  delete s;
	}
}

int main()
{
	deque_t queue;

	for(int i=0;i<5;i++)
	queue.push_front(i);
	show(queue,1);
	
	for(int i=0;i<5;i++)
	queue.push_front(i);
	show(queue,0);
	
	for(int i=0;i<5;i++)
	queue.push_back(i);
	show(queue,1);
	
	for(int i=0;i<5;i++)
	queue.push_back(i);
	show(queue,0);
	
	
	
	return 0;
}

