#include "Citerator.h"
#include "Cvector.h"
#include <memory>

#ifndef _ODST_CLINKLIST_H_
#define _ODST_CLINKLIST_H_

namespace odst {

//===================================================== Cnode
//=====================================================

template <typename U, unsigned int N>
class Cnode : public Carray<Cnode<U, N>*, N> {
public:
    typedef U data_t;
    U data;

    Cnode()
    {
        setall(nullptr);
    }

    Cnode(const U& data)
        : data(data)
    {
        setall(nullptr);
    }
    void setall(Cnode* t)
    {
        for (unsigned int i = 0; i < N; i++)
            this->t[i] = t;
    }
};

//===================================================== Clinklist_base
//=====================================================
template <typename T, unsigned int N>
struct Clinklist_base {
    typedef Cvector<T*, Cdynamicarray<T*> > headtail_t;
    typedef T node_t;

    typedef typename T::data_t value_type;
    typedef typename T::data_t& reference;
    typedef const typename T::data_t& const_reference;
    typedef typename std::allocator_traits<std::allocator<T> >::pointer pointer;
    typedef typename std::allocator_traits<std::allocator<T> >::const_pointer const_pointer;

    headtail_t head;
    headtail_t tail;

    std::allocator<T> alloc;

    bool isEmpty() const
    {
        for (unsigned int i = 0; i < head.size(); i++) {
            if (head[i] || tail[i])
                return false;
        }

        return true;
    }

    T& Addnext(T* t, unsigned int index)
    {

        if (!head[index] && !tail[index]) {
            head[index] = t;
            tail[index] = t;
        } else {
            (*tail[index])[index] = t;
            tail[index] = t;
        }

        return *t;
    }

    T& Newnext(unsigned int index)
    {

        return Addnext(alloc.allocate(1), index);
    }

    T& Addprev(T* t, unsigned int index)
    {

        if (!head[index] && !tail[index]) {
            head[index] = t;
            tail[index] = t;
        } else {
            (*t)[index] = tail[index];
            tail[index] = t;
        }

        return *t;
    }

    T& Newprev(unsigned int index)
    {

        return Addprev(alloc.allocate(1), index);
    }

protected:
    Clinklist_base()
    {
        for (unsigned int i = 0; i < N; i++) {
            head << nullptr;
            tail << nullptr;
        }

        clearbe();
    }

    void Destroy(headtail_t& ht, unsigned int index)
    {
        T *temp1, *temp2;

        for (temp1 = ht[index]; temp1;) {
            temp2 = temp1;
            temp1 = (*temp1)[index];
            alloc.destroy(temp2);
            alloc.deallocate(temp2, 1);
        }
    }

    void clearbe()
    {

        for (unsigned int i = 0; i < head.size(); i++) {
            head[i] = nullptr;
            tail[i] = nullptr;
        }
    }

    T& getNode(const headtail_t& ht, unsigned int direct,
        unsigned int index) const
    {
        T* tmp;
        unsigned int i;

        for (i = 0, tmp = ht[direct]; i < index; i++, tmp = (*tmp)[direct]) {
            if (!tmp)
                break;
        }

        return *tmp;
    }

    unsigned int getIndex(const headtail_t& ht, unsigned int direct,
        const T* t) const
    {
        T* tmp;
        unsigned int i;

        for (i = 0, tmp = ht[direct]; tmp != t; i++, tmp = (*tmp)[direct]) {
            if (!tmp) {
                i = -1;
                break;
            }
        }

        return i;
    }

    unsigned int countNode(const headtail_t& ht, unsigned int direct,
        unsigned int index) const
    {
        T* tmp;
        unsigned int i;

        for (i = 0, tmp = ht[index]; tmp; i++, tmp = (*tmp)[direct])
            ;

        return i;
    }
};

//===================================================== Cdoublylinklist
//=====================================================
template <typename T>
struct Cdoublylinklist : public Clinklist_base<T, 2> {

    ~Cdoublylinklist()
    {
        Destroy();
    }

    void Add(T* t)
    {
        Cdoublylinklist<T>::Addnext(t, next);
        Cdoublylinklist<T>::Addprev(t, prev);
    }

    T& New()
    {
        T* t;
        Add(t = Cdoublylinklist<T>::alloc.allocate(1));
        return *t;
    }

    T& getNode(unsigned int index) const
    {
        return Clinklist_base<T, 2>::getNode(Cdoublylinklist<T>::head, next, index);
    }

    unsigned int getIndex(const T* t) const
    {
        return Clinklist_base<T, 2>::getIndex(Cdoublylinklist<T>::head, next, t);
    }

    T& Insert(T* t, unsigned int index)
    {
        T *tleft, *tright;

        if (!(tright = &getNode(index))) {
            Add(t);
        }

        else {

            tleft = (*tright)[prev];

            Joint(tleft, t);
            Joint(t, tright);

            if (tleft == nullptr) {
                Cdoublylinklist<T>::head[next] = t;
                Cdoublylinklist<T>::head[prev] = t;
            }
        }

        return *t;
    }

    T& Insert(unsigned int index)
    {

        return Insert(Cdoublylinklist<T>::alloc.allocate(1), index);
    }

    void Remove(T* t)
    {
        delete Split(t);
    }

    void Remove(unsigned int index)
    {
        Remove(&getNode(index));
    }

    T* Split(T* t)
    {
        T *tleft, *tright;

        tright = (*t)[next];
        tleft = (*t)[prev];

        Joint(tleft, tright);

        if (tleft == nullptr) {
            Cdoublylinklist<T>::head[next] = tright;
            Cdoublylinklist<T>::head[prev] = tright;
        }

        if (tright == nullptr) {
            Cdoublylinklist<T>::tail[next] = tleft;
            Cdoublylinklist<T>::tail[prev] = tleft;
        }

        (*t)[next] = nullptr;
        (*t)[prev] = nullptr;

        return t;
    }

    T* Split(unsigned int index)
    {
        return Split(&getNode(index));
    }

    void Destroy()
    {
        if (Cdoublylinklist<T>::head[next] && Cdoublylinklist<T>::tail[next])
            Clinklist_base<T, 2>::Destroy(Clinklist_base<T, 2>::head, next);
        Cdoublylinklist<T>::clearbe();
    }

    unsigned int countNode() const
    {
        return Clinklist_base<T, 2>::countNode(Cdoublylinklist<T>::head, next, 0);
    }

    static const unsigned int next = 0;
    static const unsigned int prev = 1;
    static const unsigned int invalidnode = -1;

protected:
    static void Joint(T* t1, T* t2)
    {
        if (t1)
            (*t1)[next] = t2;
        if (t2)
            (*t2)[prev] = t1;
    }
};

//===================================================== Csinglylinklist
//=====================================================
template <typename T>
struct Csinglylinklist : public Clinklist_base<T, 1> {

    ~Csinglylinklist()
    {
        Clinklist_base<T, 1>::Destroy(Csinglylinklist::head, direction);
    }

    void Add(T* t)
    {
        Csinglylinklist<T>::Addnext(t, direction);
    }

    T& New()
    {
        T* t = Csinglylinklist<T>::alloc.allocate(1);

        Add(t);
        return *t;
    }

    T& getNode(unsigned int index) const
    {
        return Clinklist_base<T, 1>::getNode(Csinglylinklist<T>::head, direction,
            index);
    }

    unsigned int getIndex(const T* t) const
    {
        return Clinklist_base<T, 1>::getIndex(Csinglylinklist<T>::head, direction, t);
    }

    T& Insert(T* t, unsigned int index)
    {
        T *tleft, *tright;

        if (!(tright = &getNode(index))) {
            Add(t);
        }

        else {

            if (tright == Csinglylinklist<T>::head[0]) {
                Joint(t, tright);
                Csinglylinklist<T>::head[0] = t;
            } else {
                tleft = &getNode(index - 1);
                Joint(tleft, t);
                Joint(t, tright);
            }
        }

        return *t;
    }

    T& Insert(unsigned int index)
    {
        return Insert(Csinglylinklist<T>::alloc.allocate(1), index);
    }

    T* Split(T* t)
    {
        T *tleft, *tright;

        tleft = (t == Csinglylinklist<T>::head[direction])
            ? nullptr
            : &getNode(getIndex(t) - 1);
        tright = (t == Csinglylinklist<T>::tail[direction]) ? nullptr : (*t)[direction];

        Joint(tleft, tright);

        if (tleft == nullptr) {
            Csinglylinklist<T>::head[direction] = tright;
        }

        if (tright == nullptr) {
            Csinglylinklist<T>::tail[direction] = tleft;
        }

        (*t)[direction] = nullptr;

        return t;
    }

    T* Split(unsigned int index)
    {
        return Split(&getNode(index));
    }

    void Remove(T* t)
    {
        delete Split(t);
    }

    void Remove(unsigned int index)
    {
        Remove(&getNode(index));
    }

    void Destroy()
    {
        if (Csinglylinklist<T>::head[direction] && Csinglylinklist<T>::tail[direction])
            Clinklist_base<T, 1>::Destroy(Clinklist_base<T, 1>::head, direction);
        Csinglylinklist<T>::clearbe();
    }

    unsigned int countNode() const
    {
        return Clinklist_base<T, 1>::countNode(Csinglylinklist<T>::head, direction,
            0);
    }

    static const unsigned int direction = 0;

protected:
    void Joint(T* t1, T* t2)
    {
        if (t1)
            (*t1)[direction] = t2;
    }
};

//============================== Clist_base ===================================
template <typename U, typename T = Cnode<U, 2> >
struct Clist_base : public Cdoublylinklist<T> {

    Citerator_doublylinklist<T> begin() const
    {
        return Citerator_doublylinklist<T>(Clist_base::head[0]);
    }

    Citerator_doublylinklist<T> end() const
    {
        return Citerator_doublylinklist<T>(Clist_base::tail[0] ? Clist_base::tail[0]->getobj(0)
                                                         : nullptr);
    }

    Criterator_linklist<T> rbegin() const
    {
        return Criterator_linklist<T>(Clist_base::tail[1]);
    }

    Criterator_linklist<T> rend() const
    {
        return Criterator_linklist<T>(Clist_base::head[1] ? Clist_base::head[1]->getobj(1)
                                                          : nullptr);
    }
};

//============================== Clist_forward_base ===================================

template <typename U, typename T = Cnode<U, 1> >
struct Clist_forward_base : public Csinglylinklist<T> {

    Citerator_linklist<T> begin() const
    {
        return Citerator_linklist<T>(Clist_forward_base::head[0]);
    }
    Citerator_linklist<T> end() const
    {
        return Citerator_linklist<T>(
            Clist_forward_base::tail[0] ? Clist_forward_base::tail[0]->getobj(0) : nullptr);
    }
};
}
#endif
