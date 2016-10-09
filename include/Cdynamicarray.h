#include "Carray.h"
#ifndef _ODST_CDYNAMICARRAY_H_
#define _ODST_CDYNAMICARRAY_H_

//===================================================== Cdynamicarray =====================================================
template <typename T>
class Cdynamicarray : public Carray_iterator_base<T>
{
	
	public:
	~Cdynamicarray();
	
	unsigned int getn() const;					//interface
	
	void insert(const T &t,unsigned int index); //interface
	void remove(unsigned int index);			//interface
	
	
	void destroy();								//interface
	
	T* split(unsigned int index);				//interface
	Cdynamicarray& assign(unsigned int length); //interface
	
	protected:

	void resize(unsigned int length);
	
	
};


template <typename T>
Cdynamicarray<T>::~Cdynamicarray()
{
	destroy();
}


template <typename T>
unsigned int Cdynamicarray<T>::getn() const
{
	return Cdynamicarray::n;
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
	
	assign(length);
	this->n=n;
	
	for(unsigned int i=0;i<n;i++)
	{
		Cdynamicarray<T>::t[i]=tmp[i];
	}	
}

template <typename T>
void Cdynamicarray<T>::destroy()
{
	if(Cdynamicarray<T>::t)
	{
		delete[] Cdynamicarray<T>::t;
		Cdynamicarray<T>::t=nullptr;
		Cdynamicarray<T>::length=0;
		Cdynamicarray::n=0;
	}
	
}


template <typename T>
Cdynamicarray<T>& Cdynamicarray<T>::assign(unsigned int length)
{
	destroy();
	Cdynamicarray<T>::t=new T[this->length=length];
	
	return *this;
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


