#ifndef _ODST_CVECTOR_H_
#define _ODST_CVECTOR_H_

//===================================================== Cvector_interface =====================================================
template <typename T,typename U>
class Cvector_interface : public T
{

	
	public:

	
	Cvector_interface& operator<<(const U &u);
	U& operator[](unsigned int index) const;
	
	
	void add(const U &u);
	void remove(unsigned int index);
	void remove();
	
	void push(const U &u);
	U* pop();

	void push_back(const U &u);
	U* pop_back();
	
	void insert(const U &u ,unsigned int index);
	
};



template <typename T,typename U>
void Cvector_interface<T,U>::add(const U &u)
{
  T::insert(u,T::getn());
}


template <typename T,typename U>
void Cvector_interface<T,U>::remove(unsigned int index)
{
  T::remove(index);
}

template <typename T,typename U>
void Cvector_interface<T,U>::remove()
{
  T::remove(T::getn()-1);
}


template <typename T,typename U>
Cvector_interface<T,U>& Cvector_interface<T,U>::operator<<(const U &u)
{
  add(u);
  return *this;
}

template <typename T,typename U>
U& Cvector_interface<T,U>::operator[](unsigned int index) const
{
  return T::getobj(index);
}

template <typename T,typename U>
void Cvector_interface<T,U>::push(const U &u)
{
  T::insert(u,T::getn());
}

template <typename T,typename U>
U* Cvector_interface<T,U>::pop()
{
  return T::split(T::getn()-1);
}

template <typename T,typename U>
void Cvector_interface<T,U>::push_back(const U &u)
{
  T::insert(u,0);
}

template <typename T,typename U>
U* Cvector_interface<T,U>::pop_back()
{
  return T::split(0);
}

template <typename T,typename U>
void Cvector_interface<T,U>::insert(const U &u ,unsigned int index)
{
T::insert(u,index);
}


#endif


