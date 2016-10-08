#ifndef _ODST_CDEQUE_H_
#define _ODST_CDEQUE_H_

//===================================================== Cdeque_interface =====================================================


template <typename T,typename U>
class Cdeque_interface : public T
{
	public:

	void push_front(const U &u);
	U* pop_front();
	
	void push_back(const U &u);
	U* pop_back();
	
};


template <typename T,typename U>
void Cdeque_interface<T,U>::push_front(const U &u)
{
	T::insert(u,Cdeque_interface<T,U>::getn());
}
template <typename T,typename U>
void Cdeque_interface<T,U>::push_back(const U &u)
{
	T::insert(u,0);
}

template <typename T,typename U>
U* Cdeque_interface<T,U>::pop_back()
{
	
	return T::split(0);
}
template <typename T,typename U>
U* Cdeque_interface<T,U>::pop_front()
{
	
	return T::split(Cdeque_interface<T,U>::getn()-1);
}


#endif


