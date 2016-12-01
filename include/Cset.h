#ifndef _ODST_CSET_H_
#define _ODST_CSET_H_
#include "Cdynamicarray.h"
#include "Cutil.h"

namespace odst {

//===================================================== Cset_interface
//=====================================================
template <typename U, typename T, typename V>
class Cset : public T {

public:
    typedef V key_compare;
    typedef V value_compare;

    Cset() = default;

    Cset(const Cset& t)
    {
        for (unsigned int i = 0; i < t.size(); ++i)
            push_back(t[i]);
    }

    Cset(std::initializer_list<U> list)
    {
        assign(list.begin(), list.end());
    }

    template <typename iter>
    Cset(const iter a, const iter b)
    {
        assign(a, b);
    }

    Cset& operator=(const Cset& t)
    {
        Cset::destroy();
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

    template <typename It>
    void erase(It i)
    {
        T::remove(i.base());
    }

    template <typename It>
    void erase(It i, It j)
    {

        for (; i != j;) {
            It m = i;
            i++;
            T::remove(m.base());
        }
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

    Cset& operator<<(const U& u)
    {
        add(u);
        return *this;
    }

    void insert(const U& u, unsigned int index)
    {
        T::insert(u, index);
    }

    unsigned int pack()
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

    unsigned int _union(const Cset& set)
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

    unsigned int intersect(const Cset& set)
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

    bool issubset(const Cset& set) const
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

    unsigned int sub(const Cset& set)
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

    bool equal(const Cset& set) const
    {
        if (!issubset(set) || !set.issubset(*this))
            return false;

        return true;
    }

    bool operator==(const Cset& set) const
    {
        return equal(set);
    }

    bool operator!=(const Cset& set) const
    {
        return !equal(set);
    }

    //*************************************************
    Cset operator|(const Cset& set) const
    {
        Cset tmp(*this);
        tmp._union(set);

        return Cset(tmp);
    }

    Cset operator&(const Cset& set) const
    {
        Cset tmp(*this);
        tmp.intersect(set);

        return Cset(tmp);
    }

    Cset operator-(const Cset& set) const
    {
        Cset tmp(*this);
        tmp.sub(set);

        return Cset(tmp);
    }

    //*************************************************
    Cset& operator|=(const Cset& set)
    {
        _union(set);
        return *this;
    }

    Cset& operator&=(const Cset& set)
    {
        intersect(set);
        return *this;
    }

    Cset& operator-=(const Cset& set)
    {
        sub(set);
        return *this;
    }

    //******************************************************************//

    bool operator<(const Cset& vec) const
    {
        unsigned int i, j;
        Cset set1(*this), set2(vec);

        set1.pack();
        sort(set1, 0, set1.size(), V());

        set2.pack();
        sort(set2, 0, set2.size(), V());

        for (i = 0, j = 0; i < set1.size() && j < set2.size(); ++i, ++j) {
            if (set1[i] < set2[j])
                return true;
            else if (set1[i] > set2[j])
                return false;
        }

        return (i == set1.size() && j != set2.size());
    }

    bool operator>=(const Cset& vec) const
    {

        return !operator<(vec);
    }

    bool operator>(const Cset& vec) const
    {
        unsigned int i, j;
        Cset set1(*this), set2(vec);

        set1.pack();
        sort(set1, 0, set1.size(), V());

        set2.pack();
        sort(set2, 0, set2.size(), V());

        for (i = 0, j = 0; i < set1.size() && j < set2.size(); ++i, ++j) {
            if (set1[i] > set2[j])
                return true;
            else if (set1[i] < set2[j])
                return false;
        }

        return (i != set1.size() && j == set2.size());
    }

    bool operator<=(const Cset& vec) const
    {

        return !operator>(vec);
    }

    //******************************************************************//

protected:
    void push_back(const U& u)
    {
        T::insert(u, T::size());
    }
};
}

template <typename Char, typename CharT, typename U, typename T, typename V>
std::basic_ostream<Char, CharT>& operator<<(std::basic_ostream<Char, CharT>& out, const odst::Cset<U, T, V>& set)
{
    out << '{';
    for (unsigned int i = 0; i < set.size(); i++) {
        out << set[i];
        if (i + 1 != set.size())
            out << ',';
    }
    out << '}';
    return out;
}
#endif
