#include "Cdynamicarray.h"
#ifndef _CSTACK_H_
#define _CSTACK_H_

//===================================================== Cstack =====================================================
template <typename T>
class Cstack : public Cdynamicarray_base<T>
{
	public:
	
	Cstack& operator<<(const T &t);
  
  	void push(const T &t);
	T* pop();
};


template <typename T>
void Cstack<T>::push(const T &t)
{
	Cdynamicarray_base<T>::push(t,Cstack<T>::n);
}

template <typename T>
T* Cstack<T>::pop()
{
    return Cdynamicarray_base<T>::pop(Cstack<T>::n-1);
}

template <typename T>
Cstack<T>& Cstack<T>::operator<<(const T &t)
{
	push(t);
	return *this;
}


#endif


