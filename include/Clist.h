#include "Cvector.h"
#ifndef _CLIST_H_
#define _CLIST_H_

//===================================================== Clist =====================================================
template <typename T>
class Clist : public Cvector<T>
{

	
	public:

	
	Clist& operator<<(const T &t);
	
	void add(const T &t);
	void remove(unsigned int index);
	void remove();
	
};



template <typename T>
void Clist<T>::add(const T &t)
{
  Clist<T>::insert(t,Clist<T>::n);
}


template <typename T>
void Clist<T>::remove(unsigned int index)
{
  Cvector<T>::remove(index);
}

template <typename T>
void Clist<T>::remove()
{
  Cvector<T>::remove(Clist<T>::n-1);
}


template <typename T>
Clist<T>& Clist<T>::operator<<(const T &t)
{
  add(t);
  return *this;
}

#endif


