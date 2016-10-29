#ifndef _ODST_CVECTOR_H_
#define _ODST_CVECTOR_H_
#include "Cdynamicarray.h"
//===================================================== Cvector
//=====================================================
template <typename U, typename T = Cdynamicarray<U>>
class Cvector : public T
{

public:
  Cvector& operator<<(const U& u);
  U& operator[](unsigned int index) const;

  void add(const U& u);
  void remove(unsigned int index);
  void remove();

  void push(const U& u);
  U* pop();

  void push_back(const U& u);
  U* pop_back();

  void push_front(const U& u);
  U* pop_front();

  void insert(const U& u, unsigned int index);
};

template <typename U, typename T>
void
Cvector<U, T>::add(const U& u)
{
  T::insert(u, T::getn());
}

template <typename U, typename T>
void
Cvector<U, T>::remove(unsigned int index)
{
  T::remove(index);
}

template <typename U, typename T>
void
Cvector<U, T>::remove()
{
  T::remove(T::getn() - 1);
}

template <typename U, typename T>
Cvector<U, T>&
Cvector<U, T>::operator<<(const U& u)
{
  add(u);
  return *this;
}

template <typename U, typename T>
U& Cvector<U, T>::operator[](unsigned int index) const
{
  return T::getobj(index);
}

template <typename U, typename T>
void
Cvector<U, T>::push(const U& u)
{
  push_back(u);
}

template <typename U, typename T>
U*
Cvector<U, T>::pop()
{
  return pop_back();
}

template <typename U, typename T>
void
Cvector<U, T>::push_front(const U& u)
{
  T::insert(u, 0);
}

template <typename U, typename T>
U*
Cvector<U, T>::pop_front()
{
  return T::split(0);
}

template <typename U, typename T>
void
Cvector<U, T>::push_back(const U& u)
{
  T::insert(u, T::getn());
}

template <typename U, typename T>
U*
Cvector<U, T>::pop_back()
{
  return T::split(T::getn() - 1);
}

template <typename U, typename T>
void
Cvector<U, T>::insert(const U& u, unsigned int index)
{
  T::insert(u, index);
}

#endif
