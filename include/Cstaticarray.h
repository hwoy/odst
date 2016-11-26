#include "Carray.h"
#ifndef _ODST_CSTATAICARRAY_H_
#define _ODST_CSTATAICARRAY_H_

//===================================================== Cdstaticarray_base
//=====================================================
template <typename T, unsigned int N>
class Cstaticarray : public Carray_Citerator_n<T> {

public:
    Cstaticarray(unsigned int lenght = N);

    void insert(const T& t, unsigned int index); // interface
    void remove(unsigned int index); // interface
    int clear(); // interface

    T* split(unsigned int index); // interface
};

template <typename T, unsigned int N>
int Cstaticarray<T, N>::clear()
{
    Cstaticarray<T, N>::n = 0;
    return 1;
}

template <typename T, unsigned int N>
Cstaticarray<T, N>::Cstaticarray(unsigned int lenght)
{
    Cstaticarray<T, N>::assign(lenght);
}

template <typename T, unsigned int N>
void Cstaticarray<T, N>::remove(unsigned int index)
{
    if (!Cstaticarray<T, N>::n)
        return;

    for (unsigned int i = index; i + 1 < Cstaticarray<T, N>::n; i++) {
        Cstaticarray<T, N>::t[i] = Cstaticarray<T, N>::t[i + 1];
    }

    Cstaticarray<T, N>::n--;
}

template <typename T, unsigned int N>
void Cstaticarray<T, N>::insert(const T& t, unsigned int index)
{

    for (unsigned int i = Cstaticarray<T, N>::n; i > index; i--) {
        Cstaticarray<T, N>::t[i] = Cstaticarray<T, N>::t[i - 1];
    }

    Cstaticarray<T, N>::t[index] = t;
    Cstaticarray<T, N>::n++;
}

template <typename T, unsigned int N>
T* Cstaticarray<T, N>::split(unsigned int index)
{
    T* t;

    if (!Cstaticarray<T, N>::n)
        return nullptr;

    t = new T;
    *t = Cstaticarray<T, N>::t[index];
    remove(index);

    return t;
}

#endif
