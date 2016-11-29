#ifndef _CITERATOR_H_
#define _CITERATOR_H_

namespace odst {

template <typename T>
struct Citerator_base {

    Citerator_base(T* t)
        : current(t)
    {
    }

	bool operator==(const Citerator_base& hs) const
    {
        return this->current == hs.current;
    }
	
	//************************* Input *******************
	
    bool operator!=(const Citerator_base& hs) const
    {
        return this->current != hs.current;
    }
	
	T* operator-> ()
	{
		return current;
	}
	
	const T* operator-> () const
	{
		return current;
	}

    T* base() { return current; }
	
	const T* base() const { return current; }
	

protected:
    T* current;
};

template <typename T>
struct Citerator : public Citerator_base<T> {
    typedef Citerator self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::random_access_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    Citerator(T* t)
        : Citerator_base<T>(t)
    {
    }

	reference operator*() const { return *Citerator::current; }
		
    self_type& operator++()
    {
        Citerator::current++;
        return *this;
    }

    self_type& operator++(int i)
    {
        Citerator::current++;
        return *this;
    }
	

	//************************ Binary Acess ***********************	
    self_type& operator--()
    {
        Citerator::current--;
        return *this;
    }

    self_type& operator--(int i)
    {
        Citerator::current--;
        return *this;
    }
	
	//************************ Random Acess ***********************
	
	self_type& operator+=(difference_type n)
	{
		Citerator::current+=n;
		return *this;
	}
	
	self_type operator+(difference_type n) const
	{
		return Citerator(Citerator::current+n);
	}
	
	self_type& operator-=(difference_type n)
	{
		Citerator::current-=n;
		return *this;
	}
	
	self_type operator-(difference_type n) const
	{
		return Citerator(Citerator::current-n);
	}
	
	difference_type operator-(Citerator a) const
	{
		return Citerator::current-a.current;
	}
	
	self_type& operator[](difference_type n)
	{
		return *(Citerator::current+n);
	}
	
	const self_type& operator[](difference_type n) const
	{
		return *(Citerator::current+n);
	}
	
	bool operator<(Citerator b) const
	{
		return (b.current-Citerator::current)>0;
	}
	
	bool operator>(Citerator b) const
	{
		return Citerator::current>b.current;
	}
	
	bool operator<=(Citerator b) const
	{
		return !(Citerator::current>b.current);
	}
	
	bool operator>=(Citerator b) const
	{
		return !(Citerator::current<b.current);
	}
};

template <typename T>
struct Criterator : public Citerator_base<T> {
    typedef Criterator self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    Criterator(T* t)
        : Citerator_base<T>(t)
    {
    }

    self_type& operator++()
    {
        Criterator::current--;
        return *this;
    }

    self_type& operator++(int i)
    {
        Criterator::current--;
        return *this;
    }

    reference operator*() const { return *Criterator::current; }
};

template <typename T>
struct Citerator_linklist : public Citerator_base<T> {
    typedef Citerator_linklist self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    Citerator_linklist(T* t)
        : Citerator_base<T>(t)
    {
    }

    self_type& operator++()
    {
        Citerator_linklist::current = Citerator_linklist::current->getobj(0);
        return *this;
    }

    self_type& operator++(int i)
    {
        Citerator_linklist::current = Citerator_linklist::current->getobj(0);
        return *this;
    }
    typename T::data_t& operator*() const { return Citerator_linklist::current->data; }
};

template <typename T>
struct Criterator_linklist : public Citerator_base<T> {
    typedef Criterator_linklist self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::forward_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    Criterator_linklist(T* t)
        : Citerator_base<T>(t)
    {
    }

    self_type& operator++()
    {
        Criterator_linklist::current = Criterator_linklist::current->getobj(1);
        return *this;
    }

    self_type& operator++(int i)
    {
        Criterator_linklist::current = Criterator_linklist::current->getobj(1);
        return *this;
    }
    typename T::data_t& operator*() const { return Criterator_linklist::current->data; }
};
}
#endif
