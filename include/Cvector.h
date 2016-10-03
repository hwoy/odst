#include "Carray.h"
#ifndef _CVECTOR_H_
#define _CVECTOR_H_

//===================================================== Cvector =====================================================
template <typename T>
class Cvector : public Carray_base<T>
{
	protected:
	unsigned int n;
	
	public:
	Cvector();
	~Cvector();
	
	unsigned int getn() const;
	void insert(const T &t,unsigned int index);
	void remove(unsigned int index=0);
	void add(const T &t);
	
	Cvector& assign(unsigned int length);
	
	Cvector& operator<<(const T &t);
	Cvector& operator>>(unsigned int index);
	
	
	protected:
	void resize(unsigned int length);
	void destroy();
	
};

template <typename T>
Cvector<T>::Cvector()
{
	n=0;
}

template <typename T>
Cvector<T>::~Cvector()
{
	destroy();
}


template <typename T>
unsigned int Cvector<T>::getn() const
{
	return n;
}

template <typename T>
void Cvector<T>::insert(const T &t,unsigned int index)
{
	
		if(n+1>Cvector<T>::length)
			resize((n+1)<<1);
			
				for(unsigned int i=n;i>index;i--)
				{
					Cvector<T>::t[i]=Cvector<T>::t[i-1];
				}
		

		
		Cvector<T>::t[index]=t;
		n++;
	
}

template <typename T>
void Cvector<T>::remove(unsigned int index)
{
	if(!n) return;
	
	for(unsigned int i=index;i+1<n;i++)
	{
		Cvector<T>::t[i]=Cvector<T>::t[i+1];
	}

	n--;
		
	if(Cvector<T>::length >=3*n) resize((n+1)<<2);
	
}

template <typename T>
void Cvector<T>::add(const T &t)
{
  insert(t,0);
}

template <typename T>
void Cvector<T>::resize(unsigned int length)
{
	Carray<T> tmp(length);
	unsigned int n=this->n;
	
	
	for(unsigned int i=0;i<n;i++)
	{
		tmp[i]=Cvector<T>::t[i];
	}
	
	assign(length);
	this->n=n;
	
	for(unsigned int i=0;i<n;i++)
	{
		Cvector<T>::t[i]=tmp[i];
	}	
}

template <typename T>
void Cvector<T>::destroy()
{
	if(Cvector<T>::t)
	{
		delete[] Cvector<T>::t;
		Cvector<T>::t=nullptr;
		Cvector<T>::length=0;
		n=0;
	}
	
}


template <typename T>
Cvector<T>& Cvector<T>::operator<<(const T &t)
{
	add(t);
	return *this;
}

template <typename T>
Cvector<T>& Cvector<T>::operator>>(unsigned int index)
{
	remove(index);
	return *this;
}


template <typename T>
Cvector<T>& Cvector<T>::assign(unsigned int length)
{
	destroy();
	Cvector<T>::t=new T[this->length=length];
	
	return *this;
}



#endif


