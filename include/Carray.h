#ifndef _ODST_CARRAY_H_
#define _ODST_CARRAY_H_
#include "Citerator.h"
//===================================================== Carray_base =====================================================

template <typename T>
class Carray_base
{
	protected:
	T *t;	
	unsigned int length;
	
	public:
	
	Carray_base();
	
	T& operator[](unsigned int index) const;
	T& getobj(unsigned int index) const;	//interface
	
	unsigned int getlength() const;
	
	
};

template <typename T>
Carray_base<T>::Carray_base()
{
	t=nullptr;
	length=0;
}

template <typename T>
T& Carray_base<T>::operator[](unsigned int index) const
{
	return t[index];
}

template <typename T>
T& Carray_base<T>::getobj(unsigned int index) const
{
	return t[index];
}

template <typename T>
unsigned int Carray_base<T>::getlength() const
{
	return length;
}

//===================================================== Carray_Citerator_base =====================================================
template <typename T>
class Carray_Citerator_base: public Carray_base<T>
{
	
	public:
	
	typedef Citerator<T> iterator;
		
	Citerator<T> begin() const
	{
		return Citerator<T>(Carray_Citerator_base::t);
	}
	
	
	~Carray_Citerator_base()
	{
		destroy();
	}

	
	void destroy()
{
		delete[] Carray_Citerator_base::t;
		Carray_Citerator_base::t=nullptr;
		Carray_Citerator_base::length=0;

}
	
	void assign(unsigned int length)
	{
		destroy();
		Carray_Citerator_base::t=new T[this->length=length];
	
	}
	
	
	
};

//===================================================== Carray_Citerator_n =====================================================
template <typename T>
class Carray_Citerator_n: public Carray_Citerator_base<T>
{
	protected:
	unsigned int n;
	
	public:
		
	Carray_Citerator_n():n(0){}
	
	Citerator<T> end() const
	{
		return Citerator<T>(Carray_Citerator_n::t+n);
	}
	constexpr int size() const
	{
		return n;
	}
	

	
	void destroy()
{
	Carray_Citerator_base<T>::destroy();
	n=0;
}
	
	
	unsigned int getn() const
{
	return n;
}
	
void setn(unsigned int n)
{
	this->n=n;
}
	
};
//===================================================== Carray_Citerator_length =====================================================
template <typename T>
class Carray_Citerator_length: public Carray_Citerator_base<T>
{
	public:
	Citerator<T> end() const
	{
		return  Citerator<T>(Carray_Citerator_length::t+ Carray_Citerator_length::length);
	}
	constexpr int size() const
	{
		return  Carray_Citerator_length::length;
	}
};

//===================================================== Carray =====================================================
template <typename T,unsigned int N=0>
class Carray : public Carray_Citerator_length<T>
{
	
	public:
	Carray(unsigned int length=N);
	
	
};


template <typename T,unsigned int N>
Carray<T,N>::Carray(unsigned int length)
{
	Carray<T,N>::assign(length);
}

#endif


