#include "Cdynamicarray.h"
#ifndef _CLIST_H_
#define _CLIST_H_

//===================================================== Clist =====================================================
template <typename T>
class Clist : public Cdynamicarray_base<T>
{

	
	public:

	
	Clist& operator<<(const T &t);
	
	void add(const T &t);
	void remove(unsigned int index);
	void remove();
	
	void push(const T &t);
	T* pop();

	void push_back(const T &t);
	T* pop_back();
	
		
	
};



template <typename T>
void Clist<T>::add(const T &t)
{
  Clist<T>::insert(t,Clist<T>::n);
}


template <typename T>
void Clist<T>::remove(unsigned int index)
{
  Cdynamicarray_base<T>::remove(index);
}

template <typename T>
void Clist<T>::remove()
{
  Cdynamicarray_base<T>::remove(Clist<T>::n-1);
}


template <typename T>
Clist<T>& Clist<T>::operator<<(const T &t)
{
  add(t);
  return *this;
}

template <typename T>
void Clist<T>::push(const T &t)
{
  Cdynamicarray_base<T>::push(t,Clist<T>::n);
}

template <typename T>
T* Clist<T>::pop()
{
  return Cdynamicarray_base<T>::pop(Clist<T>::n-1);
}

template <typename T>
void Clist<T>::push_back(const T &t)
{
  Cdynamicarray_base<T>::push(t,0);
}

template <typename T>
T* Clist<T>::pop_back()
{
  return Cdynamicarray_base<T>::pop(0);
}

#endif


