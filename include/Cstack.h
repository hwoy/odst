#ifndef _ODST_CSTACK_H_
#define _ODST_CSTACK_H_
#include "Cdynamicarray.h"
//===================================================== Cstack_interface =====================================================
template <typename U,typename T=Cdynamicarray<U> >
class Cstack : public T
{
	public:
	
	Cstack& operator<<(const U &u);
  
  	void push(const U &u);
	U* pop();
	
	void push_front(const U &u);
	U* pop_front();
};


template <typename U,typename T>
void Cstack<U,T>::push(const U &u)
{
	push_front(u);
}

template <typename U,typename T>
U* Cstack<U,T>::pop()
{
    return pop_front();
}

template <typename U,typename T>
Cstack<U,T>& Cstack<U,T>::operator<<(const U &u)
{
	push(u);
	return *this;
}

template <typename U,typename T>
void Cstack<U,T>::push_front(const U &u)
{
  T::insert(u,T::getn());
}

template <typename U,typename T>
U* Cstack<U,T>::pop_front()
{
  return T::split(T::getn()-1);
}

#endif


