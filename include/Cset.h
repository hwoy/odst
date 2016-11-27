#ifndef _ODST_CSET_H_
#define _ODST_CSET_H_
#include "Cdynamicarray.h"
#include "Cutil.h"

namespace odst{

//===================================================== Cset_interface
//=====================================================
template <typename U, typename T>
class Cset : public T {

public:
    Cset& operator<<(const U& u);
    U& operator[](unsigned int index) const;

    void add(const U& u);
    void remove(unsigned int index);
    void remove();

    void insert(const U& u, unsigned int index);

    /*		Core Methodes		*/

    unsigned int pack();
    unsigned int _union(const Cset& set);
    unsigned int intersect(const Cset& set);
    unsigned int sub(const Cset& set);
    bool issubset(const Cset& set) const;
    bool equal(const Cset& setconst) const;
};

template <typename U, typename T>
void Cset<U, T>::add(const U& u)
{
    T::insert(u, T::size());
}

template <typename U, typename T>
void Cset<U, T>::remove(unsigned int index)
{
    T::remove(index);
}

template <typename U, typename T>
void Cset<U, T>::remove()
{
    T::remove(T::size() - 1);
}

template <typename U, typename T>
Cset<U, T>&
Cset<U, T>::operator<<(const U& u)
{
    add(u);
    return *this;
}

template <typename U, typename T>
U& Cset<U, T>::operator[](unsigned int index) const
{
    return T::getobj(index);
}

template <typename U, typename T>
void Cset<U, T>::insert(const U& u, unsigned int index)
{
    T::insert(u, index);
}

template <typename U, typename T>
unsigned int
Cset<U, T>::pack()
{
    unsigned int count;
    count = 0;

    for (unsigned int i = 0; i < T::size(); i++) {

        for (unsigned int j = i + 1; j < T::size();) {
            if (T::getobj(i) == T::getobj(j)) {
                remove(j);
                count++;
                continue;
            }
            j++;
        }
    }

    return count;
}

template <typename U, typename T>
unsigned int
Cset<U, T>::_union(const Cset<U, T>& set)
{
    unsigned int count;
    count = 0;

    for (unsigned int i = 0; i < set.size(); i++) {
        if (find(*this, 0, T::size(), set.getobj(i)) == -1U) {
            add(set.getobj(i));
            count++;
        }
    }

    return count;
}

template <typename U, typename T>
unsigned int
Cset<U, T>::intersect(const Cset<U, T>& set)
{
    unsigned int count = 0;

    for (unsigned int i = T::size(); i > 0; i--) {
        if (find(set, 0, set.size(), T::getobj(i - 1)) == -1U) {
            remove(i - 1);
            count++;
        }
    }

    return count;
}

template <typename U, typename T>
bool Cset<U, T>::issubset(const Cset& set) const
{
    bool isequal;

    for (unsigned int j = 0; j < set.size(); j++) {
        isequal = false;
        for (unsigned int i = 0; i < T::size(); i++) {
            if (T::getobj(i) == set[j]) {
                isequal = true;
                break;
            }
        }
        if (!isequal)
            return false;
    }

    return true;
}

template <typename U, typename T>
unsigned int
Cset<U, T>::sub(const Cset<U, T>& set)
{
    unsigned int count = 0;

    for (unsigned int i = T::size(); i > 0; i--) {
        if (find(set, 0, set.size(), T::getobj(i - 1)) != -1U) {
            remove(i - 1);
            count++;
        }
    }

    return count;
}

template <typename U, typename T>
bool Cset<U, T>::equal(const Cset& set) const
{
    if (!issubset(set) || !set.issubset(*this))
        return false;

    return true;
}
}
#endif
