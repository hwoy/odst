#ifndef _ODST_CDEQUE_H_
#define _ODST_CDEQUE_H_
#include "Cdynamicarray.h"

namespace odst{
//===================================================== Cdeque_interface
//=====================================================

template <typename U, typename T = Cdynamicarray<U> >
class Cdeque : public T {
public:
    void push_front(const U& u);
    U* pop_front();

    void push_back(const U& u);
    U* pop_back();
};

template <typename U, typename T>
void Cdeque<U, T>::push_back(const U& u)
{
    T::insert(u, T::size());
}
template <typename U, typename T>
void Cdeque<U, T>::push_front(const U& u)
{
    T::insert(u, 0);
}

template <typename U, typename T>
U* Cdeque<U, T>::pop_front()
{

    return T::split(0);
}
template <typename U, typename T>
U* Cdeque<U, T>::pop_back()
{

    return T::split(T::size() - 1);
}

}

#endif
