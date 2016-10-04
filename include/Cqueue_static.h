#include "Cstaticarray.h"
#ifndef _CQUEUE_STATIC_H_
#define _CQUEUE_STATIC_H_

//===================================================== Cqueue_static =====================================================
template <typename T,unsigned int N>
class Cqueue_static : public Cstaticarray_base<T,N>
{
	public:

	void push(const T &t);
	T* pop();
	
	Cqueue_static& operator<<(const T &t);
};


template <typename T,unsigned int N>
void Cqueue_static<T,N>::push(const T &t)
{
	Cstaticarray_base<T,N>::push(t,Cqueue_static<T,N>::n);
}

template <typename T,unsigned int N>
T* Cqueue_static<T,N>::pop()
{
	
	return Cstaticarray_base<T,N>::pop(0);
}

template <typename T,unsigned int N>
Cqueue_static<T,N>& Cqueue_static<T,N>::operator<<(const T &t)
{
	push(t);
	return *this;
}


#endif


