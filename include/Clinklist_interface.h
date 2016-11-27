
#ifndef _ODST_CLINKLIST_INTERFACE_H_
#define _ODST_CLINKLIST_INTERFACE_H_
#include "Clinklist.h"

namespace odst{
//===================================================== Clinklist_interface
//=====================================================

template <typename U, unsigned int N = 2, typename V = Cnode<U, N>,
    typename T = Clist_base<U> >
struct Clinklist_interface : public T {

    unsigned int size() const { return T::countNode(); }

    void insert(const U& u, unsigned int index)
    {
        V* v;
        v = T::alloc.allocate(1);
	T::alloc.construct(v,u);

        T::Insert(v, index);
    }

    void remove(unsigned int index) { T::Remove(index); }

    void destroy() { T::Destroy(); }

    int clear()
    {
        T::Destroy();
        return 0;
    }

    U split(unsigned int index)
    {
        U u= T::getNode(index).data;

        T::Remove(index);

        return U(u);
    }

    U& getobj(unsigned int index) const { return T::getNode(index).data; }
    U& operator[](unsigned int index) const { getobj(index); }

    void assign(unsigned int length)
    {
        T::Destroy();
        for (unsigned int i = 0; i < length; i++) {
            T::New();
        }
    }
};
}
#endif
