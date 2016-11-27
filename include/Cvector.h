#ifndef _ODST_CVECTOR_H_
#define _ODST_CVECTOR_H_
#include <initializer_list>
#include "Cdynamicarray.h"

namespace odst{

//===================================================== Cvector
//=====================================================
template <typename U, typename T >
class Cvector : public T {

public:
    Cvector() = default;

    Cvector(const Cvector& t)
    {
        for (const auto& i : t)
            push_back(i);
    }

    Cvector& operator=(const Cvector& t)
    {
        Cvector::destroy();
        for (const auto& i : t)
            push_back(i);
        return *this;
    }

    Cvector(std::initializer_list<U> list)
    {
        for (const auto& i : list)
            push_back(i);
    }

    template <typename iter>
    Cvector(const iter a, const iter b)
    {
        for (iter i = a; i != b; ++i)
            push_back(*i);
    }

    Cvector& operator<<(const U& u);

    void add(const U& u);
    void remove(unsigned int index);
    void remove();

    void push(const U& u);
    U pop();

    void push_back(const U& u);
    U pop_back();

    void push_front(const U& u);
    U pop_front();

    void insert(const U& u, unsigned int index);
};

template <typename U, typename T>
void Cvector<U, T>::add(const U& u)
{
    T::insert(u, T::size());
}

template <typename U, typename T>
void Cvector<U, T>::remove(unsigned int index)
{
    T::remove(index);
}

template <typename U, typename T>
void Cvector<U, T>::remove()
{
    T::remove(T::size() - 1);
}

template <typename U, typename T>
Cvector<U, T>&
Cvector<U, T>::operator<<(const U& u)
{
    add(u);
    return *this;
}

template <typename U, typename T>
void Cvector<U, T>::push(const U& u)
{
    push_back(u);
}

template <typename U, typename T>
U Cvector<U, T>::pop()
{
    return pop_back();
}

template <typename U, typename T>
void Cvector<U, T>::push_front(const U& u)
{
    T::insert(u, 0);
}

template <typename U, typename T>
U Cvector<U, T>::pop_front()
{
    return T::split(0);
}

template <typename U, typename T>
void Cvector<U, T>::push_back(const U& u)
{
    T::insert(u, T::size());
}

template <typename U, typename T>
U Cvector<U, T>::pop_back()
{
    return T::split(T::size() - 1);
}

template <typename U, typename T>
void Cvector<U, T>::insert(const U& u, unsigned int index)
{
    T::insert(u, index);
}
}
#endif
