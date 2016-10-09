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

//===================================================== Carray_iterator =====================================================
template <typename T>
class Carray_iterator_base: public Carray_base<T>
{
	protected:
	unsigned int n;
	
	public:
		
	/*		for iterator					*/
	Carray_iterator_base():n(0){}
	
	constexpr const T *begin() const
	{
		return Carray_iterator_base::t;
	}
	constexpr const T *end() const
	{
		return Carray_iterator_base::t+n;
	}
	constexpr int size() const
	{
		return n;
	}
	
	/*			for dynamic and static				*/
	
	~Carray_iterator_base()
	{
		destroy();
	}

	
	void destroy()
{
	if(Carray_iterator_base::t)
	{
		delete[] Carray_iterator_base::t;
		Carray_iterator_base::t=nullptr;
		Carray_iterator_base::length=0;
		n=0;
	}
}
	
	void assign(unsigned int length)
	{
		destroy();
		Carray_iterator_base::t=new T[this->length=length];
	
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

//===================================================== Carray =====================================================
template <typename T,unsigned int N=0>
class Carray : public Carray_base<T>
{
	
	public:
	Carray(unsigned int length=N);
	~Carray();
	
	void operator=(unsigned int length);
	
	
	void assign(unsigned int length);
	void destroy();
};


template <typename T,unsigned int N>
Carray<T,N>::Carray(unsigned int length)
{
	assign(length);
}

template <typename T,unsigned int N>
Carray<T,N>::~Carray()
{
	destroy();
}



template <typename T,unsigned int N>
void Carray<T,N>::operator=(unsigned int length)
{
	assign(length);
}


template <typename T,unsigned int N>
void Carray<T,N>::assign(unsigned int length)
{
	destroy();
	Carray<T,N>::t=new T[this->length=length];
	
}

template <typename T,unsigned int N>
void Carray<T,N>::destroy()
{
	if(Carray<T,N>::t)
	{
		delete[] Carray<T,N>::t;
		Carray<T,N>::t=nullptr;
		Carray<T,N>::length=0;
	}
}


#endif


