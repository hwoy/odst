#ifndef _CSTACK_H_
#define _CSTACK_H_

//===================================================== Cstack_interface =====================================================
template <typename T,typename U>
class Cstack_interface : public T
{
	public:
	
	Cstack_interface& operator<<(const U &u);
  
  	void push(const U &u);
	U* pop();
};


template <typename T,typename U>
void Cstack_interface<T,U>::push(const U &u)
{
	T::push(u,Cstack_interface<T,U>::n);
}

template <typename T,typename U>
U* Cstack_interface<T,U>::pop()
{
    return T::pop(Cstack_interface<T,U>::n-1);
}

template <typename T,typename U>
Cstack_interface<T,U>& Cstack_interface<T,U>::operator<<(const U &u)
{
	push(u);
	return *this;
}

#endif


