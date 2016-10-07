#ifndef _CLIST_H_
#define _CLIST_H_

//===================================================== Clist_interface =====================================================
template <typename T,typename U>
class Clist_interface : public T
{

	
	public:

	
	Clist_interface& operator<<(const U &u);
	
	void add(const U &u);
	void remove(unsigned int index);
	void remove();
	
	void push(const U &u);
	U* pop();

	void push_back(const U &u);
	U* pop_back();
	
		
	
};



template <typename T,typename U>
void Clist_interface<T,U>::add(const U &u)
{
  T::insert(u,T::getn());
}


template <typename T,typename U>
void Clist_interface<T,U>::remove(unsigned int index)
{
  T::remove(index);
}

template <typename T,typename U>
void Clist_interface<T,U>::remove()
{
  T::remove(T::getn()-1);
}


template <typename T,typename U>
Clist_interface<T,U>& Clist_interface<T,U>::operator<<(const U &u)
{
  add(u);
  return *this;
}

template <typename T,typename U>
void Clist_interface<T,U>::push(const U &u)
{
  T::insert(u,T::getn());
}

template <typename T,typename U>
U* Clist_interface<T,U>::pop()
{
  return T::split(T::getn()-1);
}

template <typename T,typename U>
void Clist_interface<T,U>::push_back(const U &u)
{
  T::insert(u,0);
}

template <typename T,typename U>
U* Clist_interface<T,U>::pop_back()
{
  return T::split(0);
}
#endif


