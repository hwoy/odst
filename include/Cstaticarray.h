#include "Carray.h"
#ifndef _CSTATAICARRAY_H_
#define _CSTATAICARRAY_H_

//===================================================== Cdstaticarray_base =====================================================
template <typename T,unsigned int N>
class Cstaticarray_base : public Carray_base<T>
{
	protected:
	unsigned int n;
	
	public:
	Cstaticarray_base(unsigned int lenght=N);
	~Cstaticarray_base();
	
	unsigned int getn() const;
	void insert(const T &t,unsigned int index);
	void remove(unsigned int index);	
	
	
	void destroy();
	Cstaticarray_base& assign(unsigned int length=N);
	
	void setn(unsigned int n);
	
	
	protected:

	
	void push(const T &t,unsigned int index);
	T* pop(unsigned int index);
	
};

template <typename T,unsigned int N>
Cstaticarray_base<T,N>::Cstaticarray_base(unsigned int lenght)
{
	assign(lenght);
	n=0;
}

template <typename T,unsigned int N>
Cstaticarray_base<T,N>::~Cstaticarray_base()
{
	destroy();
}


template <typename T,unsigned int N>
unsigned int Cstaticarray_base<T,N>::getn() const
{
	return n;
}


template <typename T,unsigned int N>
void Cstaticarray_base<T,N>::remove(unsigned int index)
{
	if(!n) return;
	
	for(unsigned int i=index;i+1<n;i++)
	{
		Cstaticarray_base<T,N>::t[i]=Cstaticarray_base<T,N>::t[i+1];
	}

	n--;

	
}

template <typename T,unsigned int N>
void Cstaticarray_base<T,N>::insert(const T &t,unsigned int index)
{
	
			
				for(unsigned int i=n;i>index;i--)
				{
					Cstaticarray_base<T,N>::t[i]=Cstaticarray_base<T,N>::t[i-1];
				}
		

		
		Cstaticarray_base<T,N>::t[index]=t;
		n++;
	
}


template <typename T,unsigned int N>
void Cstaticarray_base<T,N>::destroy()
{
	if(Cstaticarray_base<T,N>::t)
	{
		delete[] Cstaticarray_base<T,N>::t;
		Cstaticarray_base<T,N>::t=nullptr;
		Cstaticarray_base<T,N>::length=0;
		n=0;
	}
	
}


template <typename T,unsigned int N>
Cstaticarray_base<T,N>& Cstaticarray_base<T,N>::assign(unsigned int length)
{
	destroy();
	Cstaticarray_base<T,N>::t=new T[this->length=length];
	
	return *this;
}

template <typename T,unsigned int N>
void Cstaticarray_base<T,N>::push(const T &t,unsigned int index)
{
	insert(t,index);
}

template <typename T,unsigned int N>
T* Cstaticarray_base<T,N>::pop(unsigned int index)
{
	T *t;
	
	if(!n) return nullptr;
		
	t=new T;
	*t=Cstaticarray_base<T,N>::t[index];
	remove(index);
	
	return t;
}


template <typename T,unsigned int N>
void Cstaticarray_base<T,N>::setn(unsigned int n)
{
	this->n=n;
}

#endif


