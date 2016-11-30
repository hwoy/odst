#include "Carray.h"
#ifndef _ODST_CSTATAICARRAY_H_
#define _ODST_CSTATAICARRAY_H_

namespace odst {

//===================================================== Cdstaticarray_base
//=====================================================
template <typename T, unsigned int N>
class Cstaticarray : public Carray_Citerator_n<T> {

public:
    int clear()
    {
        Cstaticarray<T, N>::n = 0;
        return 1;
    }

    Cstaticarray(unsigned int lenght = N)
    {
        Cstaticarray<T, N>::reserve(lenght);
    }

    void remove(T* p)
    {
        if (p < Cstaticarray<T, N>::t && p >= Cstaticarray<T, N>::t + Cstaticarray::n)
            return;

        for (T* i = p; i + 1 < Cstaticarray<T, N>::t + Cstaticarray::n; i++) {
            *i = *(i + 1);
        }

        Cstaticarray<T, N>::n--;
        Cstaticarray<T, N>::alloc.destroy(Cstaticarray<T, N>::t + Cstaticarray<T, N>::n);
    }

    void remove(unsigned int index)
    {
        remove(Cstaticarray<T, N>::t + index);
    }

    void insert(const T& t, unsigned int index)
    {

        for (unsigned int i = Cstaticarray<T, N>::n; i > index; i--) {
            Cstaticarray<T, N>::t[i] = Cstaticarray<T, N>::t[i - 1];
        }

        Cstaticarray<T, N>::alloc.construct(Cstaticarray<T, N>::t + index, t);
        Cstaticarray<T, N>::n++;
    }

    T split(unsigned int index)
    {
        T t = Cstaticarray<T, N>::t[index];
        remove(index);

        return T(t);
    }
};
}
#endif
