#include "Clinklist.h"


#ifndef _CCIRLINKLIST_H_
#define _CCIRLINKLIST_H_



//===================================================== Ccirlinklist_base =====================================================
template <typename T,unsigned int N>
struct Ccirlinklist_base : public Clinklist_base<T,N>
{
	
	T& Addnext(T *t,unsigned int index);
	T& Newnext(unsigned int index);
	T& Addprev(T *t,unsigned int index);
	T& Newprev(unsigned int index);
	
	protected:
	void Destroy(unsigned int index);
};


template <typename T,unsigned int N>
T& Ccirlinklist_base<T,N>::Addnext(T *t,unsigned int index)
{
	Clinklist_base<T,N>::Addnext(t,index);
	
	(*t)[index]=Ccirlinklist_base<T,N>::head[index];
	
	return *t;
}

template <typename T,unsigned int N>
T& Ccirlinklist_base<T,N>::Newnext(unsigned int index)
{
	T *t;
	
	return Addnext(t=new T,index);
}

template <typename T,unsigned int N>
T& Ccirlinklist_base<T,N>::Addprev(T *t,unsigned int index)
{
	Clinklist_base<T,N>::Addprev(t,index);
	Ccirlinklist_base<T,N>::head[index]=t;
	
	return *t;
}

template <typename T,unsigned int N>
T& Ccirlinklist_base<T,N>::Newprev(unsigned int index)
{
	T *t;
	
	return Addprev(t=new T,index);
}

template <typename T,unsigned int N>
void Ccirlinklist_base<T,N>::Destroy(unsigned int index)
{
	T *temp1,*temp2;
	
	temp1=Ccirlinklist_base<T,N>::head[index];
	do(temp1)
	{
		temp2=temp1;
		temp1=(*temp1)[index];
		delete temp2;
	}while(temp1!=Ccirlinklist_base<T,N>::tail[index]);
}






#endif
