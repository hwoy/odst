#ifndef _ODST_CQUEUE_H_
#define _ODST_CQUEUE_H_

//===================================================== Cqueue_interface =====================================================


template <typename T,typename U>
class Cqueue_interface : public T
{
	public:

	void push(const U &u);
	U* pop();
	
	void push_front(const U &u);
	U* pop_back();
	
	Cqueue_interface& operator<<(const U &u);
};


template <typename T,typename U>
void Cqueue_interface<T,U>::push(const U &u)
{
	push_front(u);
}

template <typename T,typename U>
U* Cqueue_interface<T,U>::pop()
{
	
	return pop_back();
}

template <typename T,typename U>
Cqueue_interface<T,U>& Cqueue_interface<T,U>::operator<<(const U &u)
{
	push(u);
	return *this;
}

template <typename T,typename U>
void Cqueue_interface<T,U>::push_front(const U &u)
{
  T::insert(u,T::getn());
}

template <typename T,typename U>
U* Cqueue_interface<T,U>::pop_back()
{
  return T::split(0);
}

#endif


