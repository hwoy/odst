#ifndef _ODST_CQUEUE_H_
#define _ODST_CQUEUE_H_
#include "Cdynamicarray.h"
//===================================================== Cqueue_interface =====================================================


template <typename U,typename T=Cdynamicarray<U> >
class Cqueue : public T
{
	public:

	void push(const U &u);
	U* pop();
	
	void push_front(const U &u);
	U* pop_back();
	
	Cqueue& operator<<(const U &u);
};


template <typename U,typename T>
void Cqueue<U,T>::push(const U &u)
{
	push_front(u);
}

template <typename U,typename T>
U* Cqueue<U,T>::pop()
{
	
	return pop_back();
}

template <typename U,typename T>
Cqueue<U,T>& Cqueue<U,T>::operator<<(const U &u)
{
	push(u);
	return *this;
}

template <typename U,typename T>
void Cqueue<U,T>::push_front(const U &u)
{
  T::insert(u,T::getn());
}

template <typename U,typename T>
U* Cqueue<U,T>::pop_back()
{
  return T::split(0);
}

#endif


