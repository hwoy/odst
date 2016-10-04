#include "Cdynamicarray.h"
#ifndef _CSTACK_H_
#define _CSTACK_H_

//===================================================== Cstack =====================================================
template <typename T>
class Cstack : public Cdynamicarray_base<T>
{
	public:

	void push(const T &t);
	T* pop();
	
	Cstack& operator<<(const T &t);
};


template <typename T>
void Cstack<T>::push(const T &t)
{
	Cstack<T>::insert(t,Cstack<T>::n);
}

template <typename T>
T* Cstack<T>::pop()
{
	T *t;
	
	if(!Cstack<T>::n) return nullptr;
		
	t=new T;
	*t=Cstack<T>::t[Cstack<T>::n-1];
	Cstack<T>::remove(Cstack<T>::n-1);
	
	return t;
}

template <typename T>
Cstack<T>& Cstack<T>::operator<<(const T &t)
{
	push(t);
	return *this;
}


#endif


