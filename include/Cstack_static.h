#include "Cstaticarray.h"
#ifndef _CSTACK_STATIC_H_
#define _CSTACK_STATIC_H_

//===================================================== Cstack_static =====================================================
template <typename T,unsigned int N>
class Cstack_static : public Cstaticarray_base<T,N>
{
	public:
	
	Cstack_static& operator<<(const T &t);
  
  	void push(const T &t);
	T* pop();
};


template <typename T,unsigned int N>
void Cstack_static<T,N>::push(const T &t)
{
	Cstaticarray_base<T,N>::push(t,Cstack_static<T,N>::n);
}

template <typename T,unsigned int N>
T* Cstack_static<T,N>::pop()
{
    return Cstaticarray_base<T,N>::pop(Cstack_static<T,N>::n-1);
}

template <typename T,unsigned int N>
Cstack_static<T,N>& Cstack_static<T,N>::operator<<(const T &t)
{
	push(t);
	return *this;
}


#endif


