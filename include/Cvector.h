#ifndef _ODST_CVECTOR_H_
#define _ODST_CVECTOR_H_
#include "Cdynamicarray.h"
#include <initializer_list>

namespace odst {

//===================================================== Cvector
//=====================================================
template <typename U, typename T>
class Cvector : public T {

public:
    Cvector() = default;

    Cvector(const Cvector& t)
    {
        for (unsigned int i = 0; i < t.size(); ++i)
            push_back(t[i]);
    }

    Cvector(std::initializer_list<U> list)
    {
        assign(list.begin(), list.end());
    }

    template <typename iter>
    Cvector(const iter a, const iter b)
    {
        assign(a, b);
    }

    Cvector& operator=(const Cvector& t)
    {
        Cvector::destroy();
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
    void add(const U& u)
    {
        T::insert(u, T::size());
    }

    void remove(unsigned int index)
    {
        T::remove(index);
    }

    void remove()
    {
        T::remove(T::size() - 1);
    }

    Cvector<U, T>& operator<<(const U& u)
    {
        add(u);
        return *this;
    }

    void push(const U& u)
    {
        push_back(u);
    }

    U pop()
    {
        return pop_back();
    }

    void push_front(const U& u)
    {
        T::insert(u, 0);
    }

    U pop_front()
    {
        return T::split(0);
    }

    void push_back(const U& u)
    {
        T::insert(u, T::size());
    }

    U pop_back()
    {
        return T::split(T::size() - 1);
    }

    void insert(const U& u, unsigned int index)
    {
        T::insert(u, index);
    }
};
}
#endif
