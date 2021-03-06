#include "Carray.h"
#ifndef _ODST_CDYNAMICARRAY_H_
#define _ODST_CDYNAMICARRAY_H_

namespace odst {
//===================================================== Cdynamicarray
//=====================================================
template <typename T>
class Cdynamicarray : public Carray_Citerator_n<T> {

public:
    int clear()
    {
        Cdynamicarray<T>::destroy();
        return 0;
    }

    void remove(T* p)
    {
        if (p < Cdynamicarray<T>::t && p >= Cdynamicarray<T>::t + Cdynamicarray::n)
            return;

        Cdynamicarray<T>::alloc.destroy(p);

        for (T* i = p; i + 1 < Cdynamicarray<T>::t + Cdynamicarray::n; i++) {
            *i = *(i + 1);
        }

        Cdynamicarray::n--;

        Cdynamicarray<T>::alloc.destroy(Cdynamicarray<T>::t + Cdynamicarray::n);

        if (Cdynamicarray<T>::length >= 3 * Cdynamicarray::n)
            resize((Cdynamicarray::n + 1) << 2);
    }

    void remove(unsigned int index)
    {
        remove(Cdynamicarray<T>::t + index);
    }

    void insert(const T& t, unsigned int index)
    {

        if (Cdynamicarray<T>::n + 1 > Cdynamicarray<T>::length)
            resize((Cdynamicarray::n + 1) << 1);

        for (unsigned int i = Cdynamicarray::n; i > index; i--) {
            Cdynamicarray<T>::alloc.construct(Cdynamicarray<T>::t + i, Cdynamicarray<T>::t[i - 1]);
            Cdynamicarray<T>::alloc.destroy(Cdynamicarray<T>::t + i - 1);
        }

        Cdynamicarray<T>::alloc.construct(Cdynamicarray<T>::t + index, t);
        Cdynamicarray::n++;
    }

    T split(unsigned int index)
    {
        T t = Cdynamicarray<T>::t[index];
        remove(index);

        return T(t);
    }

public:
    void resize(unsigned int length)
    {
        T* tmp;
        std::allocator<T> alloc;

        tmp = alloc.allocate(length);

        unsigned int n = this->n;

        for (unsigned int i = 0; i < n; ++i)
            alloc.construct(tmp + i, Cdynamicarray<T>::t[i]);

        Cdynamicarray<T>::reserve(length);
        Cdynamicarray<T>::n = n;

        for (unsigned int i = 0; i < n; i++) {
            Cdynamicarray<T>::alloc.construct(Cdynamicarray<T>::t + i, tmp[i]);
        }

        for (unsigned int i = 0; i < n; ++i)
            alloc.destroy(tmp + i);

        alloc.deallocate(tmp, length);
    }
};
}
#endif
