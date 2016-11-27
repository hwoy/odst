#ifndef _ODST_CARRAY_H_
#define _ODST_CARRAY_H_
#include "Citerator.h"
#include <memory>

namespace odst{
//===================================================== Carray_base
//=====================================================

template <typename T>
class Carray_base // Not for use
{
protected:
    T* t;
    std::allocator<T> alloc;
    unsigned int length;
    void reset()
    {
        t = nullptr;
        length = 0;
    }

    Carray_base():t(nullptr),length(0){}

public:
    typedef T data_t;

    T& operator[](unsigned int index);
    constexpr T& operator[](unsigned int index) const;

    T& getobj(unsigned int index); // interface
    constexpr T& getobj(unsigned int index) const; // interface

    unsigned int getlength() const;
};


template <typename T>
T& Carray_base<T>::operator[](unsigned int index)
{
    return t[index];
}

template <typename T>
constexpr T& Carray_base<T>::operator[](unsigned int index) const
{
    return t[index];
}

template <typename T>
T& Carray_base<T>::getobj(unsigned int index)
{
    return t[index];
}

template <typename T>
constexpr T& Carray_base<T>::getobj(unsigned int index) const
{
    return t[index];
}

template <typename T>
unsigned int
Carray_base<T>::getlength() const
{
    return length;
}

//===================================================== Carray_Citerator_base
//=====================================================
template <typename T>
class Carray_Citerator_base : public Carray_base<T> //Not for use
{
protected:
    Carray_Citerator_base() = default;

public:
    typedef Citerator<T> iterator;

    constexpr Citerator<T> begin() const { return Citerator<T>(Carray_Citerator_base::t); }
    constexpr Criterator<T> rend() const { return Criterator<T>(Carray_Citerator_base::t - 1); }
};

//===================================================== Carray_Citerator_n
//=====================================================
template <typename T>
class Carray_Citerator_n : public Carray_Citerator_base<T> //Not for use
{
protected:
    unsigned int n;
    Carray_Citerator_n()
        : n(0)
    {
    }

    ~Carray_Citerator_n() { destroy(); }

public:
    void reset()
    {
        Carray_Citerator_base<T>::reset();
        n = 0;
    }

    constexpr Citerator<T> end() const { return Citerator<T>(Carray_Citerator_n::t + n); }
    constexpr Criterator<T> rbegin() const { return Criterator<T>(Carray_Citerator_n::t + n - 1); }

    constexpr int size() const { return n; }

    void setn(unsigned int n) { this->n = n; }

    void destroy()
    {
        for (unsigned int i = Carray_Citerator_n::n; i > 0; i--)
            Carray_Citerator_n::alloc.destroy(Carray_Citerator_n::t + i - 1);

        destroy_raw();
    }
    void destroy_raw()
    {
        Carray_Citerator_n::alloc.deallocate(Carray_Citerator_n::t, Carray_Citerator_n::length);

        n = 0;
        Carray_Citerator_n::length = 0;
        Carray_Citerator_n::t = nullptr;
    }

    void assign_raw(unsigned int length)
    {
        destroy();
        if (length)
            Carray_Citerator_n::t = Carray_Citerator_n::alloc.allocate(this->length = length);
    }
};
//===================================================== Carray_Citerator_length
//=====================================================
template <typename T>
class Carray_Citerator_length : public Carray_Citerator_base<T> //Not for use
{
protected:

    Carray_Citerator_length() = default;
    ~Carray_Citerator_length() { destroy(); }

public:
    constexpr Citerator<T> end() const
    {
        return Citerator<T>(Carray_Citerator_length::t + Carray_Citerator_length::length);
    }

    constexpr Criterator<T> rbegin() const { return Criterator<T>(Carray_Citerator_length::t + Carray_Citerator_length::length - 1); }

    constexpr int size() const { return Carray_Citerator_length::length; }

    void destroy()
    {
        for (unsigned int i = Carray_Citerator_length::length; i > 0; i--)
            Carray_Citerator_length::alloc.destroy(Carray_Citerator_length::t + i - 1);

        destroy_raw();
    }

    void destroy_raw()
    {

        Carray_Citerator_length::alloc.deallocate(Carray_Citerator_length::t, Carray_Citerator_length::length);

        Carray_Citerator_length::length = 0;
        Carray_Citerator_length::t = nullptr;
    }

    void assign_raw(unsigned int length)
    {
        destroy();
        if (length)
            Carray_Citerator_length::t = Carray_Citerator_length::alloc.allocate(this->length = length);
    }
};

//===================================================== Carray
//=====================================================
template <typename T, unsigned int N>
struct Carray  {

T t[N>0?N:1];

T& getobj(unsigned int index) 
{
	return t[index];
}

constexpr T& getobj(unsigned int index) const
{
	return t[index];
}

T& operator[](unsigned int index)
{
	return t[index];
}

constexpr T& operator[](unsigned int index) const
{
	return t[index];
}
constexpr unsigned int size() const
{
	return N;
}
constexpr Citerator<T> begin() const
{
	return Citerator<T>((T *)t);
}
constexpr Citerator<T> end() const
{
	return Citerator<T>((T *)t+N);
}
constexpr Criterator<T> rbegin() const
{
	return Criterator<T>((T *)t+N-1);
}
constexpr Criterator<T> rend() const
{
	return Criterator<T>((T *)t-1);
}

};

}
#endif
