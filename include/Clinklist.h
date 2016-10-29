#include "Citerator.h"
#include "Cvector.h"

#ifndef _ODST_CLINKLIST_H_
#define _ODST_CLINKLIST_H_

//===================================================== Cnode
//=====================================================

template <typename U, unsigned int N>
class Cnode : public Carray<Cnode<U, N>*, N>
{
public:
  U data;

  Cnode(unsigned int length = N);
  void setall(Cnode* t);
};

template <typename U, unsigned int N>
Cnode<U, N>::Cnode(unsigned int length)
{
  setall(nullptr);
}

template <typename U, unsigned int N>
void
Cnode<U, N>::setall(Cnode<U, N>* t)
{
  for (unsigned int i = 0; i < Cnode<U, N>::length; i++)
    this->t[i] = t;
}

//===================================================== Clinklist_base
//=====================================================
template <typename T, unsigned int N>
struct Clinklist_base
{
  typedef Cvector<T*> headtail_t;
  typedef T node_t;

  headtail_t head;
  headtail_t tail;

  Clinklist_base();

  T& Addnext(T* t, unsigned int index);
  T& Newnext(unsigned int index);
  T& Addprev(T* t, unsigned int index);
  T& Newprev(unsigned int index);

  bool isEmpty() const;

protected:
  void Destroy(headtail_t& ht, unsigned int index);
  void clearbe();
  T& getNode(const headtail_t& ht, unsigned int direct,
             unsigned int index) const;
  unsigned int getIndex(const headtail_t& ht, unsigned int direct,
                        const T* t) const;
  unsigned int countNode(const headtail_t& ht, unsigned int direct,
                         unsigned int index) const;
};

template <typename T, unsigned int N>
bool
Clinklist_base<T, N>::isEmpty() const
{
  for (unsigned int i = 0; i < head.size(); i++) {
    if (head[i] || tail[i])
      return false;
  }

  return true;
}

template <typename T, unsigned int N>
Clinklist_base<T, N>::Clinklist_base()
{
  for (unsigned int i = 0; i < N; i++) {
    head << nullptr;
    tail << nullptr;
  }

  clearbe();
}

template <typename T, unsigned int N>
T&
Clinklist_base<T, N>::Addnext(T* t, unsigned int index)
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

template <typename T, unsigned int N>
T&
Clinklist_base<T, N>::Newnext(unsigned int index)
{
  T* t;

  return Addnext(t = new T, index);
}

template <typename T, unsigned int N>
T&
Clinklist_base<T, N>::Addprev(T* t, unsigned int index)
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

template <typename T, unsigned int N>
T&
Clinklist_base<T, N>::Newprev(unsigned int index)
{
  T* t;

  return Addprev(t = new T, index);
}

template <typename T, unsigned int N>
void
Clinklist_base<T, N>::Destroy(headtail_t& ht, unsigned int index)
{
  T *temp1, *temp2;

  for (temp1 = ht[index]; temp1;) {
    temp2 = temp1;
    temp1 = (*temp1)[index];
    delete temp2;
  }
}

template <typename T, unsigned int N>
void
Clinklist_base<T, N>::clearbe()
{

  for (unsigned int i = 0; i < head.size(); i++) {
    head[i] = nullptr;
    tail[i] = nullptr;
  }
}

template <typename T, unsigned int N>
T&
Clinklist_base<T, N>::getNode(const headtail_t& ht, unsigned int direct,
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

template <typename T, unsigned int N>
unsigned int
Clinklist_base<T, N>::getIndex(const headtail_t& ht, unsigned int direct,
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

template <typename T, unsigned int N>
unsigned int
Clinklist_base<T, N>::countNode(const headtail_t& ht, unsigned int direct,
                                unsigned int index) const
{
  T* tmp;
  unsigned int i;

  for (i = 0, tmp = ht[index]; tmp; i++, tmp = (*tmp)[direct])
    ;

  return i;
}


//===================================================== Cdoublylinklist
//=====================================================
template <typename T>
struct Cdoublylinklist : public Clinklist_base<T, 2>
{

  ~Cdoublylinklist();

  void Add(T* t);
  T& New();

  T& Insert(T* t, unsigned int index);
  T& Insert(unsigned int index);

  T& getNode(unsigned int) const;
  unsigned int getIndex(const T* t) const;

  void Remove(T* t);
  void Remove(unsigned int index);

  T* Split(T* t);
  T* Split(unsigned int index);

  void Destroy();

  unsigned int countNode() const;

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

template <typename T>
Cdoublylinklist<T>::~Cdoublylinklist()
{
  Destroy();
}

template <typename T>
void
Cdoublylinklist<T>::Add(T* t)
{
  Cdoublylinklist<T>::Addnext(t, next);
  Cdoublylinklist<T>::Addprev(t, prev);
}

template <typename T>
T&
Cdoublylinklist<T>::New()
{
  T* t;
  Add(t = new T);
  return *t;
}

template <typename T>
T&
Cdoublylinklist<T>::getNode(unsigned int index) const
{
  return Clinklist_base<T, 2>::getNode(Cdoublylinklist<T>::head, next, index);
}

template <typename T>
unsigned int
Cdoublylinklist<T>::getIndex(const T* t) const
{
  return Clinklist_base<T, 2>::getIndex(Cdoublylinklist<T>::head, next, t);
}

template <typename T>
T&
Cdoublylinklist<T>::Insert(T* t, unsigned int index)
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

template <typename T>
T&
Cdoublylinklist<T>::Insert(unsigned int index)
{

  return Insert(new T, index);
}

template <typename T>
void
Cdoublylinklist<T>::Remove(T* t)
{
  delete Split(t);
}

template <typename T>
void
Cdoublylinklist<T>::Remove(unsigned int index)
{
  Remove(&getNode(index));
}

template <typename T>
T*
Cdoublylinklist<T>::Split(T* t)
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

template <typename T>
T*
Cdoublylinklist<T>::Split(unsigned int index)
{
  return Split(&getNode(index));
}

template <typename T>
void
Cdoublylinklist<T>::Destroy()
{
  if (Cdoublylinklist<T>::head[next] && Cdoublylinklist<T>::tail[next])
    Clinklist_base<T, 2>::Destroy(Clinklist_base<T, 2>::head, next);
  Cdoublylinklist<T>::clearbe();
}

template <typename T>
unsigned int
Cdoublylinklist<T>::countNode() const
{
  return Clinklist_base<T, 2>::countNode(Cdoublylinklist<T>::head, next, 0);
}

//===================================================== Csinglylinklist
//=====================================================
template <typename T>
struct Csinglylinklist : public Clinklist_base<T, 1>
{

  ~Csinglylinklist();

  void Add(T* t);
  T& New();

  T& getNode(unsigned int index) const;
  unsigned int getIndex(const T* t) const;

  T& Insert(T* t, unsigned int index);
  T& Insert(unsigned int index);

  void Remove(T* t);
  void Remove(unsigned int index);

  T* Split(T* t);
  T* Split(unsigned int index);

  void Destroy();
  unsigned int countNode() const;

  static const unsigned int direction = 0;

protected:
  void Joint(T* t1, T* t2)
  {
    if (t1)
      (*t1)[direction] = t2;
  }
};

template <typename T>
Csinglylinklist<T>::~Csinglylinklist()
{
  Clinklist_base<T, 1>::Destroy(Csinglylinklist::head, direction);
}

template <typename T>
void
Csinglylinklist<T>::Add(T* t)
{
  Csinglylinklist<T>::Addnext(t, direction);
}

template <typename T>
T&
Csinglylinklist<T>::New()
{
  T* t;
  Add(t = new T);
  return *t;
}

template <typename T>
T&
Csinglylinklist<T>::getNode(unsigned int index) const
{
  return Clinklist_base<T, 1>::getNode(Csinglylinklist<T>::head, direction,
                                       index);
}

template <typename T>
unsigned int
Csinglylinklist<T>::getIndex(const T* t) const
{
  return Clinklist_base<T, 1>::getIndex(Csinglylinklist<T>::head, direction, t);
}

template <typename T>
T&
Csinglylinklist<T>::Insert(T* t, unsigned int index)
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

template <typename T>
T&
Csinglylinklist<T>::Insert(unsigned int index)
{
  return Insert(new T, index);
}

template <typename T>
T*
Csinglylinklist<T>::Split(T* t)
{
  T *tleft, *tright;

  tleft = (t == Csinglylinklist<T>::head[direction])
            ? nullptr
            : &getNode(getIndex(t) - 1);
  tright =
    (t == Csinglylinklist<T>::tail[direction]) ? nullptr : (*t)[direction];

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

template <typename T>
T*
Csinglylinklist<T>::Split(unsigned int index)
{
  return Split(&getNode(index));
}

template <typename T>
void
Csinglylinklist<T>::Remove(T* t)
{
  delete Split(t);
}

template <typename T>
void
Csinglylinklist<T>::Remove(unsigned int index)
{
  Remove(&getNode(index));
}

template <typename T>
void
Csinglylinklist<T>::Destroy()
{
  if (Csinglylinklist<T>::head[direction] &&
      Csinglylinklist<T>::tail[direction])
    Clinklist_base<T, 1>::Destroy(Clinklist_base<T, 1>::head, direction);
  Csinglylinklist<T>::clearbe();
}

template <typename T>
unsigned int
Csinglylinklist<T>::countNode() const
{
  return Clinklist_base<T, 1>::countNode(Csinglylinklist<T>::head, direction,
                                         0);
}

template <typename U,typename T=Cnode<U,2> >
struct Clist : public Cdoublylinklist<T>
{

  Citerator_linklist<T> begin() const
  {
    return Citerator_linklist<T>(Clist::head[0]);
  }
  Citerator_linklist<T> end() const
  {
    return Citerator_linklist<T>(Clist::tail[0] ? Clist::tail[0]->getobj(0)
                                                : nullptr);
  }
};

template <typename U,typename T=Cnode<U,1> >
struct Clist_forward : public Csinglylinklist<T>
{

  Citerator_linklist<T> begin() const
  {
    return Citerator_linklist<T>(Clist_forward::head[0]);
  }
  Citerator_linklist<T> end() const
  {
    return Citerator_linklist<T>(
      Clist_forward::tail[0] ? Clist_forward::tail[0]->getobj(0) : nullptr);
  }
};
#endif
