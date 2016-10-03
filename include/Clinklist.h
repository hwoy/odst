#include "Clist.h"


#ifndef _CLINKLIST_H_
#define _CLINKLIST_H_

//===================================================== Cnode =====================================================

template <typename U,unsigned int N>
class Cnode : public Carray<Cnode<U,N> *,N>
{
	public:
	U data;

	Cnode(unsigned int length=N);
	void setall(Cnode* t);


};

template <typename U,unsigned int N>
Cnode<U,N>::Cnode(unsigned int length)
{
	setall(nullptr);
}


template <typename U,unsigned int N>
void Cnode<U,N>::setall(Cnode<U,N> *t)
{
	for(unsigned int i=0;i<Cnode<U,N>::length;i++)
		this->t[i]=t;
}


//===================================================== Clinklist_base =====================================================
template <typename T,unsigned int N>
struct Clinklist_base
{
	Clist<T*> head;
	Clist<T*> tail;

	Clinklist_base();
	
	T& Addnext(T *t,unsigned int index);
	T& Newnext(unsigned int index);
	T& Addprev(T *t,unsigned int index);
	T& Newprev(unsigned int index);
	
	
	
	protected:
	void Destroy(unsigned int index);
	void clearbe();
};

template <typename T,unsigned int N>
Clinklist_base<T,N>::Clinklist_base()
{
	for(unsigned int i=0;i<N;i++)
	{
	  head << nullptr;
	  tail << nullptr;
	}
	
	clearbe();
}


template <typename T,unsigned int N>
T& Clinklist_base<T,N>::Addnext(T *t,unsigned int index)
{
	
	if(!head[index] && !tail[index])
	{
		head[index]=t;
		tail[index]=t;
	}
	else
	{
		(*tail[index])[index]=t;
		tail[index]=t;
	}
	
	return *t;
}

template <typename T,unsigned int N>
T& Clinklist_base<T,N>::Newnext(unsigned int index)
{
	T *t;
	
	return Addnext(t=new T,index);
}

template <typename T,unsigned int N>
T& Clinklist_base<T,N>::Addprev(T *t,unsigned int index)
{
	
	if(!head[index] && !tail[index])
	{
		head[index]=t;
		tail[index]=t;
	}
	else
	{
		(*t)[index]=tail[index];
		tail[index]=t;
	}
	
	return *t;
}

template <typename T,unsigned int N>
T& Clinklist_base<T,N>::Newprev(unsigned int index)
{
	T *t;
	
	return Addprev(t=new T,index);
}

template <typename T,unsigned int N>
void Clinklist_base<T,N>::Destroy(unsigned int index)
{
	T *temp1,*temp2;
	
	for(temp1=head[index];temp1;)
	{
		temp2=temp1;
		temp1=(*temp1)[index];
		delete temp2;
	}
}


template <typename T,unsigned int N>
void Clinklist_base<T,N>::clearbe()
{
	
	for(unsigned int i=0;i<head.getn();i++)
	{
		head[i]=nullptr;
		tail[i]=nullptr;
	}
}

//===================================================== Cdoublylinklist =====================================================
template <typename T>
struct Cdoublylinklist: public Clinklist_base<T,2>
{
	~Cdoublylinklist();
	
	void Add(T *t);
	T& New();
	
	void Destroy();
	
	static const unsigned int next=0;
	static const unsigned int prev=1;
	
};

template <typename T>
Cdoublylinklist<T>::~Cdoublylinklist()
{
	Destroy();
}

template <typename T>
void Cdoublylinklist<T>::Add(T *t)
{
  Cdoublylinklist<T>::Addnext(t,next);
  Cdoublylinklist<T>::Addprev(t,prev);
}

template <typename T>
T& Cdoublylinklist<T>::New()
{
  T *t;
  Add(t=new T);
  return *t;
}

template <typename T>
void Cdoublylinklist<T>::Destroy()
{
	if(Cdoublylinklist<T>::head[next] && Cdoublylinklist<T>::tail[next]) Clinklist_base<T,2>::Destroy(next);
	Cdoublylinklist<T>::clearbe();
}

#endif
