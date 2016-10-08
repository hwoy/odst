#ifndef _ODST_CQUEUE_H_
#define _ODST_CQUEUE_H_

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
	T::insert(u,Cqueue_interface<T,U>::getn());
}

template <typename T,typename U>
U* Cqueue_interface<T,U>::pop()
{
	
	return T::split(0);
}

template <typename T,typename U>
Cqueue_interface<T,U>& Cqueue_interface<T,U>::operator<<(const U &u)
{
	push(u);
	return *this;
}

#endif


