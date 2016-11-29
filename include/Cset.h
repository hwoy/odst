#ifndef _ODST_CSET_H_
#define _ODST_CSET_H_
#include "Cdynamicarray.h"
#include "Cutil.h"

namespace odst {

//===================================================== Cset_interface
//=====================================================
template <typename U, typename T>
class Cset : public T {

public:
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

    Cset<U, T>& operator<<(const U& u)
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

    unsigned int _union(const Cset<U, T>& set)
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

    unsigned int intersect(const Cset<U, T>& set)
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

    unsigned int sub(const Cset<U, T>& set)
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

protected:
    void push_back(const U& u)
    {
        T::insert(u, T::size());
    }
};
}

template <typename Char ,typename CharT,typename U, typename T>
std::basic_ostream<Char,CharT>& operator<< (std::basic_ostream<Char,CharT>& out,const odst::Cset<U,T> &set)
{
	out << '{';
	for(unsigned int i=0;i<set.size();i++)
	{
		out << set[i];
		if(i+1!=set.size())
			out << ',';
	}
	out << '}';
	return out;
}
#endif
