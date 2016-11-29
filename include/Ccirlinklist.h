#include "Clinklist.h"

#ifndef _ODST_CCIRLINKLIST_H_
#define _ODST_CCIRLINKLIST_H_

namespace odst {

//===================================================== Ccirsinglylinklist
//=====================================================
template <typename T>
struct Ccirsinglylinklist : public Csinglylinklist<T> {
    ~Ccirsinglylinklist()
    {
        Destroy();
    }

    void Destroy()
    {
        deJoint(Ccirsinglylinklist<T>::tail[0], direction);

        Csinglylinklist<T>::Destroy();
        Ccirsinglylinklist<T>::clearbe();
    }

    void Add(T* t)
    {
        Csinglylinklist<T>::Add(t);

        Joint(Ccirsinglylinklist<T>::tail[0], Ccirsinglylinklist<T>::head[0],
            direction);
    }

    T& New()
    {
        T* t;
        Add(t = Ccirsinglylinklist<T>::alloc.allocate(1));
        return *t;
    }

    T& Insert(T* t, unsigned int index)
    {

        deJoint(Ccirsinglylinklist<T>::tail[0], direction);

        Csinglylinklist<T>::Insert(t, index);

        Joint(Ccirsinglylinklist<T>::tail[0], Ccirsinglylinklist<T>::head[0],
            direction);

        return *t;
    }

    T& Insert(unsigned int index)
    {
        return Insert(Ccirsinglylinklist<T>::alloc.allocate(1), index);
    }

    void Remove(T* t)
    {
        deJoint(Ccirsinglylinklist<T>::tail[0], direction);

        Csinglylinklist<T>::Remove(t);

        Joint(Ccirsinglylinklist<T>::tail[0], Ccirsinglylinklist<T>::head[0],
            direction);
    }

    void Remove(unsigned int index)
    {
        deJoint(Ccirsinglylinklist<T>::tail[0], direction);

        Csinglylinklist<T>::Remove(index);

        Joint(Ccirsinglylinklist<T>::tail[0], Ccirsinglylinklist<T>::head[0],
            direction);
    }

    T* Split(T* t)
    {
        deJoint(Ccirsinglylinklist<T>::tail[0], direction);

        Csinglylinklist<T>::Split(t);

        Joint(Ccirsinglylinklist<T>::tail[0], Ccirsinglylinklist<T>::head[0],
            direction);

        return t;
    }

    T* Split(unsigned int index)
    {
        T* t;
        deJoint(Ccirsinglylinklist<T>::tail[0], direction);

        t = Csinglylinklist<T>::Split(index);

        Joint(Ccirsinglylinklist<T>::tail[0], Ccirsinglylinklist<T>::head[0],
            direction);

        return t;
    }

    T& getNode(unsigned int index) const
    {
        T* temp1;
        unsigned int i;

        for (i = 0, temp1 = Ccirsinglylinklist<T>::head[0]; i < index;
             i++, temp1 = (*temp1)[direction]) {
            if (temp1 == Ccirsinglylinklist<T>::tail[0])
                return *(temp1 = nullptr);
        }

        return *temp1;
    }

    unsigned int getIndex(const T* t) const
    {
        T* temp1;
        unsigned int i;

        if (Ccirsinglylinklist<T>::isEmpty())
            return -1;

        temp1 = Ccirsinglylinklist<T>::head[0];
        i = 0;
        do {
            if (temp1 == t)
                return i;

            temp1 = (*temp1)[direction];
            i++;

        } while (temp1 != Ccirsinglylinklist<T>::head[0]);

        return -1;
    }

    unsigned int countNode() const
    {
        T* temp1;
        unsigned int i;

        if (Ccirsinglylinklist<T>::isEmpty())
            return 0;

        for (i = 1, temp1 = Ccirsinglylinklist<T>::head[0];
             temp1 != Ccirsinglylinklist<T>::tail[0];
             i++, temp1 = (*temp1)[direction])
            ;

        return i;
    }

    void deJoint(T* t, unsigned int direction)
    {
        if (Ccirsinglylinklist<T>::isEmpty())
            return;

        if (t)
            (*t)[direction] = nullptr;
    }

    void Joint(T* t1, T* t2, unsigned int direct)
    {
        if (Ccirsinglylinklist<T>::isEmpty())
            return;

        if (t1)
            (*t1)[direct] = t2;
    }

protected:
    static const unsigned int direction = 0;
};

//===================================================== Ccirdoublylinklist
//=====================================================
template <typename T>
struct Ccirdoublylinklist : public Cdoublylinklist<T> {
    ~Ccirdoublylinklist()
    {
        Destroy();
    }

    void Destroy()
    {

        deJoint(Ccirdoublylinklist<T>::tail[NEXT], NEXT);
        deJoint(Ccirdoublylinklist<T>::head[PREV], PREV);

        Cdoublylinklist<T>::Destroy();
        Ccirdoublylinklist<T>::clearbe();
    }

    void Add(T* t)
    {
        Cdoublylinklist<T>::Add(t);

        Joint(Ccirdoublylinklist<T>::tail[NEXT], Ccirdoublylinklist<T>::head[NEXT],
            NEXT);
        Joint(Ccirdoublylinklist<T>::head[PREV], Ccirdoublylinklist<T>::tail[PREV],
            PREV);
    }

    T& New()
    {
        T* t;
        Add(t = Ccirdoublylinklist<T>::alloc.allocate(1));
        return *t;
    }

    T& Insert(T* t, unsigned int index)
    {
        deJoint(Ccirdoublylinklist<T>::tail[NEXT], NEXT);
        deJoint(Ccirdoublylinklist<T>::head[PREV], PREV);

        Cdoublylinklist<T>::Insert(t, index);

        Joint(Ccirdoublylinklist<T>::tail[NEXT], Ccirdoublylinklist<T>::head[NEXT],
            NEXT);
        Joint(Ccirdoublylinklist<T>::head[PREV], Ccirdoublylinklist<T>::tail[PREV],
            PREV);

        return *t;
    }

    T& Insert(unsigned int index)
    {
        return Insert(Ccirdoublylinklist<T>::alloc.allocate(1), index);
    }

    void Remove(T* t)
    {
        deJoint(Ccirdoublylinklist<T>::tail[NEXT], NEXT);
        deJoint(Ccirdoublylinklist<T>::head[PREV], PREV);

        Cdoublylinklist<T>::Remove(t);

        Joint(Ccirdoublylinklist<T>::tail[NEXT], Ccirdoublylinklist<T>::head[NEXT],
            NEXT);
        Joint(Ccirdoublylinklist<T>::head[PREV], Ccirdoublylinklist<T>::tail[PREV],
            PREV);
    }

    void Remove(unsigned int index)
    {
        deJoint(Ccirdoublylinklist<T>::tail[NEXT], NEXT);
        deJoint(Ccirdoublylinklist<T>::head[PREV], PREV);

        Cdoublylinklist<T>::Remove(index);

        Joint(Ccirdoublylinklist<T>::tail[NEXT], Ccirdoublylinklist<T>::head[NEXT],
            NEXT);
        Joint(Ccirdoublylinklist<T>::head[PREV], Ccirdoublylinklist<T>::tail[PREV],
            PREV);
    }

    T* Split(T* t)
    {
        deJoint(Ccirdoublylinklist<T>::tail[NEXT], NEXT);
        deJoint(Ccirdoublylinklist<T>::head[PREV], PREV);

        Cdoublylinklist<T>::Split(t);

        Joint(Ccirdoublylinklist<T>::tail[NEXT], Ccirdoublylinklist<T>::head[NEXT],
            NEXT);
        Joint(Ccirdoublylinklist<T>::head[PREV], Ccirdoublylinklist<T>::tail[PREV],
            PREV);

        return t;
    }

    T* Split(unsigned int index)
    {
        T* t;

        deJoint(Ccirdoublylinklist<T>::tail[NEXT], NEXT);
        deJoint(Ccirdoublylinklist<T>::head[PREV], PREV);

        t = Cdoublylinklist<T>::Split(index);

        Joint(Ccirdoublylinklist<T>::tail[NEXT], Ccirdoublylinklist<T>::head[NEXT],
            NEXT);
        Joint(Ccirdoublylinklist<T>::head[PREV], Ccirdoublylinklist<T>::tail[PREV],
            PREV);

        return t;
    }

    T& getNode(unsigned int index) const
    {
        T* temp1;
        unsigned int i;

        for (i = 0, temp1 = Ccirdoublylinklist<T>::head[NEXT]; i < index;
             i++, temp1 = (*temp1)[NEXT]) {
            if (temp1 == Ccirdoublylinklist<T>::tail[NEXT])
                return *(temp1 = nullptr);
        }

        return *temp1;
    }

    unsigned int getIndex(const T* t) const
    {
        T* temp1;
        unsigned int i;

        if (Ccirdoublylinklist<T>::isEmpty())
            return -1;

        temp1 = Ccirdoublylinklist<T>::head[NEXT];
        i = 0;
        do {
            if (temp1 == t)
                return i;

            temp1 = (*temp1)[NEXT];
            i++;

        } while (temp1 != Ccirdoublylinklist<T>::head[NEXT]);

        return -1;
    }

    unsigned int countNode() const
    {
        T* temp1;
        unsigned int i;

        if (Ccirdoublylinklist<T>::isEmpty())
            return 0;

        for (i = 1, temp1 = Ccirdoublylinklist<T>::head[0];
             temp1 != Ccirdoublylinklist<T>::tail[0]; i++, temp1 = (*temp1)[NEXT])
            ;

        return i;
    }

    void deJoint(T* t, unsigned int direction)
    {
        if (Ccirdoublylinklist<T>::isEmpty())
            return;

        if (t)
            (*t)[direction] = nullptr;
    }

    void Joint(T* t1, T* t2, unsigned int direct)
    {
        if (Ccirdoublylinklist<T>::isEmpty())
            return;

        if (t1)
            (*t1)[direct] = t2;
    }

protected:
    static const unsigned int NEXT = 0;
    static const unsigned int PREV = 1;
};
}

#endif
