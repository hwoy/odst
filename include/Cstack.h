#ifndef _ODST_CSTACK_H_
#define _ODST_CSTACK_H_
#include "Cdynamicarray.h"

namespace odst{

//===================================================== Cstack_interface
//=====================================================
template <typename U, typename T>
class Cstack : public T {
public:
    Cstack& operator<<(const U& u);

    void push(const U& u);
    U* pop();

    void push_back(const U& u);
    U* pop_back();
};

template <typename U, typename T>
void Cstack<U, T>::push(const U& u)
{
    push_back(u);
}

template <typename U, typename T>
U* Cstack<U, T>::pop()
{
    return pop_back();
}

template <typename U, typename T>
Cstack<U, T>&
Cstack<U, T>::operator<<(const U& u)
{
    push(u);
    return *this;
}

template <typename U, typename T>
void Cstack<U, T>::push_back(const U& u)
{
    T::insert(u, T::size());
}

template <typename U, typename T>
U* Cstack<U, T>::pop_back()
{
    return T::split(T::size() - 1);
}
}
#endif
