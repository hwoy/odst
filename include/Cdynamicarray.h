#include "Carray.h"
#ifndef _ODST_CDYNAMICARRAY_H_
#define _ODST_CDYNAMICARRAY_H_

//===================================================== Cdynamicarray =====================================================
template <typename T>
class Cdynamicarray : public Carray_iterator_base<T>
{
	
	public:	
	
	void insert(const T &t,unsigned int index); //interface
	void remove(unsigned int index);			//interface
	
	
	
	T* split(unsigned int index);				//interface
	int clear();								//interface
	
	protected:

	void resize(unsigned int length);
	
	
};


template <typename T>
int Cdynamicarray<T>::clear()
{
	Cdynamicarray<T>::destroy();
	return 0;
}

template <typename T>
void Cdynamicarray<T>::remove(unsigned int index)
{
	if(!Cdynamicarray::n) return;
	
	for(unsigned int i=index;i+1<Cdynamicarray::n;i++)
	{
		Cdynamicarray<T>::t[i]=Cdynamicarray<T>::t[i+1];
	}

	Cdynamicarray::n--;
		
	if(Cdynamicarray<T>::length >=3*Cdynamicarray::n) resize((Cdynamicarray::n+1)<<2);
	
}

template <typename T>
void Cdynamicarray<T>::insert(const T &t,unsigned int index)
{
	
		if(Cdynamicarray<T>::n+1>Cdynamicarray<T>::length)
			resize((Cdynamicarray::n+1)<<1);
			
				for(unsigned int i=Cdynamicarray::n;i>index;i--)
				{
					Cdynamicarray<T>::t[i]=Cdynamicarray<T>::t[i-1];
				}
		

		
		Cdynamicarray<T>::t[index]=t;
		Cdynamicarray::n++;
	
}

template <typename T>
void Cdynamicarray<T>::resize(unsigned int length)
{
	Carray<T> tmp(length);
	unsigned int n=this->n;
	
	
	for(unsigned int i=0;i<n;i++)
	{
		tmp[i]=Cdynamicarray<T>::t[i];
	}
	
	Cdynamicarray<T>::assign(length);
	this->n=n;
	
	for(unsigned int i=0;i<n;i++)
	{
		Cdynamicarray<T>::t[i]=tmp[i];
	}	
}




template <typename T>
T* Cdynamicarray<T>::split(unsigned int index)
{
	T *t;
	
	if(!Cdynamicarray::n) return nullptr;
		
	t=new T;
	*t=Cdynamicarray<T>::t[index];
	remove(index);
	
	return t;
}



#endif


