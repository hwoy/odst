#include "Carray.h"
#include "Cvector.h"

#ifndef _CLINKLIST_H_
#define _CLINKLIST_H_

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


// Clinklist<Cnode<int,1>,1 >
template <typename T,unsigned int N>
struct Clinklist
{
	Cvector<T*> head;
	Cvector<T*> tail;

	Clinklist();
	~Clinklist();
	
	T& addnext(T *t,unsigned int index);
	T& addnext(unsigned int index);
	T& addprev(T *t,unsigned int index);
	T& addprev(unsigned int index);
	
	
	void destroy();
	
	protected:
	void destroy(unsigned int index);
	void assignbe(unsigned int n=N);
};

template <typename T,unsigned int N>
Clinklist<T,N>::Clinklist()
{
	assignbe(N);
}

template <typename T,unsigned int N>
Clinklist<T,N>::~Clinklist()
{
	destroy();
}

template <typename T,unsigned int N>
T& Clinklist<T,N>::addnext(T *t,unsigned int index)
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
T& Clinklist<T,N>::addnext(unsigned int index)
{
	T *t;
	
	return addnext(t=new T,index);
}

template <typename T,unsigned int N>
T& Clinklist<T,N>::addprev(T *t,unsigned int index)
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
T& Clinklist<T,N>::addprev(unsigned int index)
{
	T *t;
	
	return addprev(t=new T,index);
}

template <typename T,unsigned int N>
void Clinklist<T,N>::destroy(unsigned int index)
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
void Clinklist<T,N>::destroy()
{
	
	for(unsigned int i=0;i<head.getn();i++)
	{
		if(i==0 || (head[i]!=head[i-1] && tail[i]!=tail[i-1]))
		destroy(i);
	}
	
	assignbe(head.getlength());
}

template <typename T,unsigned int N>
void Clinklist<T,N>::assignbe(unsigned int n)
{
	
	head.assign(n);
	tail.assign(n);
	
	for(unsigned int i=0;i<head.getlength();i++)
	{
		head[i]=nullptr;
		tail[i]=nullptr;
	}
}

#endif
