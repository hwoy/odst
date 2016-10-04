#include "Cstaticarray.h"
#ifndef _CLIST_STATIC_H_
#define _CLIST_STATIC_H_

//===================================================== Clist_static =====================================================
template <typename T,unsigned int N>
class Clist_static : public Cstaticarray_base<T,N>
{

	
	public:

	
	Clist_static& operator<<(const T &t);
	
	void add(const T &t);
	void remove(unsigned int index);
	void remove();
	
	void push(const T &t);
	T* pop();

	void push_back(const T &t);
	T* pop_back();
	
		
	
};



template <typename T,unsigned int N>
void Clist_static<T,N>::add(const T &t)
{
  Clist_static<T,N>::insert(t,Clist_static<T,N>::n);
}


template <typename T,unsigned int N>
void Clist_static<T,N>::remove(unsigned int index)
{
  Cstaticarray_base<T,N>::remove(index);
}

template <typename T,unsigned int N>
void Clist_static<T,N>::remove()
{
  Cstaticarray_base<T,N>::remove(Clist_static<T,N>::n-1);
}


template <typename T,unsigned int N>
Clist_static<T,N>& Clist_static<T,N>::operator<<(const T &t)
{
  add(t);
  return *this;
}

template <typename T,unsigned int N>
void Clist_static<T,N>::push(const T &t)
{
  Cstaticarray_base<T,N>::push(t,Clist_static<T,N>::n);
}

template <typename T,unsigned int N>
T* Clist_static<T,N>::pop()
{
  return Cstaticarray_base<T,N>::pop(Clist_static<T,N>::n-1);
}

template <typename T,unsigned int N>
void Clist_static<T,N>::push_back(const T &t)
{
  Cstaticarray_base<T,N>::push(t,0);
}

template <typename T,unsigned int N>
T* Clist_static<T,N>::pop_back()
{
  return Cstaticarray_base<T,N>::pop(0);
}

#endif


