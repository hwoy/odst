#ifndef _CQUEUE_H_
#define _CQUEUE_H_

//===================================================== Cqueue_interface =====================================================


template <typename T,typename U>
class Cqueue_interface : public T
{
	public:

	void push(const U &u);
	U* pop();
	
	Cqueue_interface& operator<<(const U &u);
};


template <typename T,typename U>
void Cqueue_interface<T,U>::push(const U &u)
{
	T::push(u,Cqueue_interface<T,U>::n);
}

template <typename T,typename U>
U* Cqueue_interface<T,U>::pop()
{
	
	return T::pop(0);
}

template <typename T,typename U>
Cqueue_interface<T,U>& Cqueue_interface<T,U>::operator<<(const U &u)
{
	push(u);
	return *this;
}

#endif


