#include "Cvector.h"
#ifndef _CLIST_H_
#define _CLIST_H_

//===================================================== Clist =====================================================
template <typename T>
class Clist : public Cvector<T>
{

	
	public:

	void insert(const T &t,unsigned int index);
	void remove(unsigned int index);
	
	Clist& operator<<(const T &t);
	
	void add(const T &t);
	void remove();
	
};


template <typename T>
void Clist<T>::insert(const T &t,unsigned int index)
{
	
		if(Clist<T>::n+1>Cvector<T>::length)
			Clist<T>::resize((Clist<T>::n+1)<<1);
			
				for(unsigned int i=Clist<T>::n;i>index;i--)
				{
					Cvector<T>::t[i]=Cvector<T>::t[i-1];
				}
		

		
		Cvector<T>::t[index]=t;
		Clist<T>::n++;
	
}

template <typename T>
void Clist<T>::add(const T &t)
{
  insert(t,Clist<T>::n);
}


template <typename T>
void Clist<T>::remove(unsigned int index)
{
	if(!Clist<T>::n) return;
	
	for(unsigned int i=index;i+1<Clist<T>::n;i++)
	{
		Cvector<T>::t[i]=Cvector<T>::t[i+1];
	}

	Clist<T>::n--;
		
	if(Cvector<T>::length >=3*Clist<T>::n) Clist<T>::resize((Clist<T>::n+1)<<2);
	
}

template <typename T>
void Clist<T>::remove()
{
  remove(Clist<T>::n-1);
}

template <typename T>
Clist<T>& Clist<T>::operator<<(const T &t)
{
  add(t);
  return *this;
}

#endif


