#include "Cdynamicarray.h"
#ifndef _CQUEUE_H_
#define _CQUEUE_H_

//===================================================== Cqueue =====================================================
template <typename T>
class Cqueue : public Cdynamicarray_base<T>
{
	public:

	void push(const T &t);
	T* pop();
	
	Cqueue& operator<<(const T &t);
};


template <typename T>
void Cqueue<T>::push(const T &t)
{
	Cdynamicarray_base<T>::push(t,Cqueue<T>::n);
}

template <typename T>
T* Cqueue<T>::pop()
{
	
	return Cdynamicarray_base<T>::pop(0);
}

template <typename T>
Cqueue<T>& Cqueue<T>::operator<<(const T &t)
{
	push(t);
	return *this;
}


#endif


