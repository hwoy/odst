#ifndef _ODST_CDEQUE_H_
#define _ODST_CDEQUE_H_
#include "Cdynamicarray.h"

namespace odst {
//===================================================== Cdeque_interface
//=====================================================

template <typename U, typename T>
class Cdeque : public T {
public:
    Cdeque() = default;

    Cdeque(const Cdeque& t)
    {
        for (unsigned int i = 0; i < t.size(); ++i)
            push_back(t[i]);
    }

    Cdeque(std::initializer_list<U> list)
    {
        assign(list.begin(), list.end());
    }

    template <typename iter>
    Cdeque(const iter a, const iter b)
    {
        assign(a, b);
    }

    Cdeque& operator=(const Cdeque& t)
    {
        Cdeque::destroy();
        for (unsigned int i = 0; i < t.size(); ++i)
            push_back(t[i]);
        return *this;
    }

    template <typename Input>
    void assign(Input a, Input b)
    {
        for (Input i = a; i != b; ++i)
            push_back(*i);
    }

    void assign(std::initializer_list<U> list)
    {
        assign(list.begin(), list.end());
    }

    //******************************************************************//

    void push_back(const U& u)
    {
        T::insert(u, T::size());
    }

    void push_front(const U& u)
    {
        T::insert(u, 0);
    }

    U pop_front()
    {

        return T::split(0);
    }

    U pop_back()
    {

        return T::split(T::size() - 1);
    }
};
}

#endif
