#ifndef _CITERATOR_H_
#define _CITERATOR_H_

template <typename T>
struct Citerator_base
{

  Citerator_base(T* t)
    : current(t)
  {
  }

  bool operator!=(const Citerator_base& hs) const
  {
    return this->current != hs.current;
  }

  T* base() const { return current; }

protected:
  T* current;
};

template <typename T>
struct Citerator : public Citerator_base<T>
{
  typedef Citerator self_type;
  typedef T value_type;
  typedef T& reference;
  typedef T* pointer;
  typedef std::forward_iterator_tag iterator_category;
  typedef std::ptrdiff_t difference_type;

  Citerator(T* t)
    : Citerator_base<T>(t)
  {
  }

  self_type& operator++()
  {
    Citerator::current++;
    return *this;
  }

  self_type& operator++(int i)
  {
    Citerator::current++;
    return *this;
  }
  reference operator*() const { return *Citerator::current; }
};

template <typename T>
struct Citerator_linklist : public Citerator_base<T>
{
  typedef Citerator_linklist self_type;
  typedef T value_type;
  typedef T& reference;
  typedef T* pointer;
  typedef std::forward_iterator_tag iterator_category;
  typedef std::ptrdiff_t difference_type;

  Citerator_linklist(T* t)
    : Citerator_base<T>(t)
  {
  }

  self_type& operator++()
  {
    Citerator_linklist::current = Citerator_linklist::current->getobj(0);
    return *this;
  }

  self_type& operator++(int i)
  {
    Citerator_linklist::current = Citerator_linklist::current->getobj(0);
    return *this;
  }
  auto& operator*() const { return Citerator_linklist::current->data; }
};

#endif
