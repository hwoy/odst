#ifndef _ODST_CSTACK_H_
#define _ODST_CSTACK_H_

//===================================================== Cstack_interface =====================================================
template <typename T,typename U>
class Cstack_interface : public T
{
	public:
	
	Cstack_interface& operator<<(const U &u);
  
  	void push(const U &u);
	U* pop();
	
	void push_front(const U &u);
	U* pop_front();
};


template <typename T,typename U>
void Cstack_interface<T,U>::push(const U &u)
{
	push_front(u);
}

template <typename T,typename U>
U* Cstack_interface<T,U>::pop()
{
    return pop_front();
}

template <typename T,typename U>
Cstack_interface<T,U>& Cstack_interface<T,U>::operator<<(const U &u)
{
	push(u);
	return *this;
}

template <typename T,typename U>
void Cstack_interface<T,U>::push_front(const U &u)
{
  T::insert(u,T::getn());
}

template <typename T,typename U>
U* Cstack_interface<T,U>::pop_front()
{
  return T::split(T::getn()-1);
}

#endif


