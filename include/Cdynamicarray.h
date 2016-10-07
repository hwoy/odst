#include "Carray.h"
#ifndef _CDYNAMICARRAY_H_
#define _CDYNAMICARRAY_H_

//===================================================== Cdynamicarray_base =====================================================
template <typename T>
class Cdynamicarray_base : public Carray_base<T>
{
	protected:
	unsigned int n;
	
	public:
	Cdynamicarray_base();
	~Cdynamicarray_base();
	
	unsigned int getn() const;					//interface
	
	void insert(const T &t,unsigned int index); //interface
	void remove(unsigned int index);			//interface
	
	
	void destroy();								//destroy
	
	
	protected:

	Cdynamicarray_base& assign(unsigned int length);
	void resize(unsigned int length);
	
	T* split(unsigned int index);				//interface
	
};

template <typename T>
Cdynamicarray_base<T>::Cdynamicarray_base()
{
	n=0;
}

template <typename T>
Cdynamicarray_base<T>::~Cdynamicarray_base()
{
	destroy();
}


template <typename T>
unsigned int Cdynamicarray_base<T>::getn() const
{
	return n;
}


template <typename T>
void Cdynamicarray_base<T>::remove(unsigned int index)
{
	if(!n) return;
	
	for(unsigned int i=index;i+1<n;i++)
	{
		Cdynamicarray_base<T>::t[i]=Cdynamicarray_base<T>::t[i+1];
	}

	n--;
		
	if(Cdynamicarray_base<T>::length >=3*n) resize((n+1)<<2);
	
}

template <typename T>
void Cdynamicarray_base<T>::insert(const T &t,unsigned int index)
{
	
		if(n+1>Cdynamicarray_base<T>::length)
			resize((n+1)<<1);
			
				for(unsigned int i=n;i>index;i--)
				{
					Cdynamicarray_base<T>::t[i]=Cdynamicarray_base<T>::t[i-1];
				}
		

		
		Cdynamicarray_base<T>::t[index]=t;
		n++;
	
}

template <typename T>
void Cdynamicarray_base<T>::resize(unsigned int length)
{
	Carray<T> tmp(length);
	unsigned int n=this->n;
	
	
	for(unsigned int i=0;i<n;i++)
	{
		tmp[i]=Cdynamicarray_base<T>::t[i];
	}
	
	assign(length);
	this->n=n;
	
	for(unsigned int i=0;i<n;i++)
	{
		Cdynamicarray_base<T>::t[i]=tmp[i];
	}	
}

template <typename T>
void Cdynamicarray_base<T>::destroy()
{
	if(Cdynamicarray_base<T>::t)
	{
		delete[] Cdynamicarray_base<T>::t;
		Cdynamicarray_base<T>::t=nullptr;
		Cdynamicarray_base<T>::length=0;
		n=0;
	}
	
}


template <typename T>
Cdynamicarray_base<T>& Cdynamicarray_base<T>::assign(unsigned int length)
{
	destroy();
	Cdynamicarray_base<T>::t=new T[this->length=length];
	
	return *this;
}


template <typename T>
T* Cdynamicarray_base<T>::split(unsigned int index)
{
	T *t;
	
	if(!n) return nullptr;
		
	t=new T;
	*t=Cdynamicarray_base<T>::t[index];
	remove(index);
	
	return t;
}



#endif


