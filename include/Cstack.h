#ifndef _ODST_CSTACK_H_
#define _ODST_CSTACK_H_
#include "Cdynamicarray.h"

namespace odst {

//===================================================== Cstack_interface
//=====================================================
template <typename U, typename T>
class Cstack : public T {
public:
    Cstack() = default;

    Cstack(const Cstack& t)
    {
        for (unsigned int i = 0; i < t.size(); ++i)
            push_back(t[i]);
    }

    Cstack(std::initializer_list<U> list)
    {
        assign(list.begin(), list.end());
    }

    template <typename iter>
    Cstack(const iter a, const iter b)
    {
        assign(a, b);
    }

    Cstack& operator=(const Cstack& t)
    {
        Cstack::destroy();
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

    void push(const U& u)
    {
        push_back(u);
    }

    U pop()
    {
        return pop_back();
    }

    Cstack<U, T>& operator<<(const U& u)
    {
        push(u);
        return *this;
    }

    void push_back(const U& u)
    {
        T::insert(u, T::size());
    }

    U pop_back()
    {
        return T::split(T::size() - 1);
    }
};
}
#endif
