#ifndef _CITERATOR_H_
#define _CITERATOR_H_

template <typename T>
struct Citerator
{
	typedef Citerator self_type;
	typedef T value_type;
    typedef T& reference;
	typedef T* pointer;
	typedef std::forward_iterator_tag iterator_category;
	typedef std::ptrdiff_t difference_type;

	Citerator(T *t):current(t){}
	
	bool operator!=(const Citerator &hs) const
	{
		return this->current!=hs.current;
	}
	
	
	Citerator& operator++()
	{
		current++;
		return *this;
	}
	
	Citerator& operator++(int i)
	{
		current++;
		return *this;
	}
	
	reference operator*() const
	{
		return *current;
	}

	pointer base() const
	{
		return current;
	}
	
	protected:
	T *current;
	
	
};

#endif