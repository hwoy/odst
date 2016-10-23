#ifndef _ODST_CARRAY_H_
#define _ODST_CARRAY_H_

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

//===================================================== Carray_iterator_base =====================================================
template <typename T>
class Carray_iterator_base: public Carray_base<T>
{
	
	public:
		
	T *begin() const
	{
		return Carray_iterator_base::t;
	}
	
	
	~Carray_iterator_base()
	{
		destroy();
	}

	
	void destroy()
{
		delete[] Carray_iterator_base::t;
		Carray_iterator_base::t=nullptr;
		Carray_iterator_base::length=0;

}
	
	void assign(unsigned int length)
	{
		destroy();
		Carray_iterator_base::t=new T[this->length=length];
	
	}
	
	
	
};

//===================================================== Carray_iterator_n =====================================================
template <typename T>
class Carray_iterator_n: public Carray_iterator_base<T>
{
	protected:
	unsigned int n;
	
	public:
		
	Carray_iterator_n():n(0){}
	
	T *end() const
	{
		return Carray_iterator_n::t+n;
	}
	constexpr int size() const
	{
		return n;
	}
	

	
	void destroy()
{
	Carray_iterator_base<T>::destroy();
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
//===================================================== Carray_iterator_length =====================================================
template <typename T>
class Carray_iterator_length: public Carray_iterator_base<T>
{
	public:
	T *end() const
	{
		return  Carray_iterator_length::t+ Carray_iterator_length::length;
	}
	constexpr int size() const
	{
		return  Carray_iterator_length::length;
	}
};

//===================================================== Carray =====================================================
template <typename T,unsigned int N=0>
class Carray : public Carray_iterator_length<T>
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


