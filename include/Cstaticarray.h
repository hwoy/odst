#include "Carray.h"
#ifndef _ODST_CSTATAICARRAY_H_
#define _ODST_CSTATAICARRAY_H_

//===================================================== Cdstaticarray_base =====================================================
template <typename T,unsigned int N>
class Cstaticarray : public Carray_iterator_base<T>
{
	
	public:
	Cstaticarray(unsigned int lenght=N);
	~Cstaticarray();
	
	unsigned int getn() const;						//interface
	void setn(unsigned int n);
	
	
	void insert(const T &t,unsigned int index);		//interface
	void remove(unsigned int index);				//interface	
	
	
	void destroy();									//interface
	Cstaticarray& assign(unsigned int length); //interface
	
	
	T* split(unsigned int index);					//interface
	
};

template <typename T,unsigned int N>
Cstaticarray<T,N>::Cstaticarray(unsigned int lenght)
{
	assign(lenght);
}

template <typename T,unsigned int N>
Cstaticarray<T,N>::~Cstaticarray()
{
	destroy();
}


template <typename T,unsigned int N>
unsigned int Cstaticarray<T,N>::getn() const
{
	return Cstaticarray<T,N>::n;
}


template <typename T,unsigned int N>
void Cstaticarray<T,N>::remove(unsigned int index)
{
	if(!Cstaticarray<T,N>::n) return;
	
	for(unsigned int i=index;i+1<Cstaticarray<T,N>::n;i++)
	{
		Cstaticarray<T,N>::t[i]=Cstaticarray<T,N>::t[i+1];
	}

	Cstaticarray<T,N>::n--;

	
}

template <typename T,unsigned int N>
void Cstaticarray<T,N>::insert(const T &t,unsigned int index)
{
	
			
				for(unsigned int i=Cstaticarray<T,N>::n;i>index;i--)
				{
					Cstaticarray<T,N>::t[i]=Cstaticarray<T,N>::t[i-1];
				}
		

		
		Cstaticarray<T,N>::t[index]=t;
		Cstaticarray<T,N>::n++;
	
}


template <typename T,unsigned int N>
void Cstaticarray<T,N>::destroy()
{
	if(Cstaticarray<T,N>::t)
	{
		delete[] Cstaticarray<T,N>::t;
		Cstaticarray<T,N>::t=nullptr;
		Cstaticarray<T,N>::length=0;
		Cstaticarray<T,N>::n=0;
	}
	
}


template <typename T,unsigned int N>
Cstaticarray<T,N>& Cstaticarray<T,N>::assign(unsigned int length)
{
	destroy();
	Cstaticarray<T,N>::t=new T[this->length=length];
	
	return *this;
}


template <typename T,unsigned int N>
T* Cstaticarray<T,N>::split(unsigned int index)
{
	T *t;
	
	if(!Cstaticarray<T,N>::n) return nullptr;
		
	t=new T;
	*t=Cstaticarray<T,N>::t[index];
	remove(index);
	
	return t;
}


template <typename T,unsigned int N>
void Cstaticarray<T,N>::setn(unsigned int n)
{
	this->n=n;
}

#endif


