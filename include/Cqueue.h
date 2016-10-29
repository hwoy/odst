#ifndef _ODST_CQUEUE_H_
#define _ODST_CQUEUE_H_
#include "Cdynamicarray.h"
//===================================================== Cqueue_interface
//=====================================================

template <typename U, typename T = Cdynamicarray<U>>
class Cqueue : public T
{
public:

  void push_front(const U& u);
  U* pop_back();

};

template <typename U, typename T>
void
Cqueue<U, T>::push_front(const U& u)
{
  T::insert(u, T::size());
}

template <typename U, typename T>
U*
Cqueue<U, T>::pop_back()
{
  return T::split(0);
}

#endif
