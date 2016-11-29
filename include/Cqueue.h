#ifndef _ODST_CQUEUE_H_
#define _ODST_CQUEUE_H_
#include "Cdynamicarray.h"

namespace odst {

//===================================================== Cqueue_interface
//=====================================================

template <typename U, typename T>
class Cqueue : public T {
public:
    Cqueue() = default;

    Cqueue(const Cqueue& t)
    {
        for (const auto& i : t)
            T::insert(i, T::size());
    }

    Cqueue& operator=(const Cqueue& t)
    {
        Cqueue::destroy();
        for (const auto& i : t)
            T::insert(i, T::size());
        ;
        return *this;
    }

    void push_front(const U& u)
    {
        T::insert(u, T::size());
    }

    U pop_back()
    {
        return T::split(0);
    }
};
}
#endif
