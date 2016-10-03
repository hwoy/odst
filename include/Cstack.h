#include "Cvector.h"
#ifndef _CSTACK_H_
#define _CSTACK_H_

//===================================================== Cstack =====================================================
template <typename T,unsigned int N=0>
class Cstack : public Cvector<T,N>
{
	public:

	void push(const T &t);
	T* pop();
	
	Cstack& operator<<(const T &t);
};


template <typename T,unsigned int N>
void Cstack<T,N>::push(const T &t)
{
	Cstack<T,N>::add(t);
}

template <typename T,unsigned int N>
T* Cstack<T,N>::pop()
{
	T *t;
	
	if(!Cstack<T,N>::n) return nullptr;
		
	t=new T;
	*t=Cstack<T,N>::t[0];
	Cstack<T,N>::remove(0);
	
	return t;
}

template <typename T,unsigned int N>
Cstack<T,N>& Cstack<T,N>::operator<<(const T &t)
{
	push(t);
	return *this;
}


#endif


