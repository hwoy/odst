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
	typedef Clist<T*> headtail_t;
	
	headtail_t head;
	headtail_t tail;

	Clinklist_base();
	
	T& Addnext(T *t,unsigned int index);
	T& Newnext(unsigned int index);
	T& Addprev(T *t,unsigned int index);
	T& Newprev(unsigned int index);
	
	
	
	protected:
	void Destroy(headtail_t &ht,unsigned int index);
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
void Clinklist_base<T,N>::Destroy(headtail_t &ht,unsigned int index)
{
	T *temp1,*temp2;
	
	for(temp1=ht[index];temp1;)
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

//===================================================== stuct nodetype =====================================================
template <typename T>
struct nodetype
{
  typedef Cnode<T,1> singlylinklist;
  typedef Cnode<T,2> doublylinklist;
};

//===================================================== Cdoublylinklist =====================================================
template <typename T>
struct Cdoublylinklist: public Clinklist_base<T,2>
{
  
	~Cdoublylinklist();
	
	void Add(T *t);
	T& New();
	
	T& Insert(T *t,unsigned int index);
	T& Insert(unsigned int index);
	
	T& getNode(unsigned int) const;
	
	void Remove(T *t);
	void Remove(unsigned int index);
	
	T* Split(T *t);
	T* Split(unsigned int index);
	
	void Destroy();
	
	static const unsigned int next=0;
	static const unsigned int prev=1;
	static const unsigned int invalidnode=-1;
	
protected:
  static void Joint(T *t1,T *t2)
  {
    if(t1) (*t1)[next]=t2;
    if(t2) (*t2)[prev]=t1;
  }
	
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
T& Cdoublylinklist<T>::getNode(unsigned int index) const
{
  T *tmp;
  unsigned int i;
  
  for(i=0,tmp=Cdoublylinklist<T>::head[next];i<index;i++,tmp=(*tmp)[next])
  {
    if(!tmp) break;
  }
  
  return *tmp;
}

template <typename T>
T& Cdoublylinklist<T>::Insert(T *t,unsigned int index)
{
  T *tleft,*tright;
  
  tright=&getNode(index);
  tleft=(*tright)[prev];
  
  Joint(tleft,t);
  Joint(t,tright);
  
  if(tleft==nullptr)
  {
    Cdoublylinklist<T>::head[next]=t;
    Cdoublylinklist<T>::head[prev]=t;
  }
  
  return *t;
}

template <typename T>
T& Cdoublylinklist<T>::Insert(unsigned int index)
{
  
  return Insert(new T,index);
}

template <typename T>
void Cdoublylinklist<T>::Remove(T *t)
{
  delete Split(t);
}

template <typename T>
void Cdoublylinklist<T>::Remove(unsigned int index)
{
  Remove(&getNode(index));
}

template <typename T>
T* Cdoublylinklist<T>::Split(T *t)
{
  T *tleft,*tright;
  
  tright=(*t)[next];
  tleft=(*t)[prev];
  
  Joint(tleft,tright);
  
  if(tleft==nullptr)
  {
    Cdoublylinklist<T>::head[next]=tright;
    Cdoublylinklist<T>::head[prev]=tright;
  }
  
   if(tright==nullptr)
  {
    Cdoublylinklist<T>::tail[next]=tleft;
    Cdoublylinklist<T>::tail[prev]=tleft;
  }
  
  (*t)[next]=nullptr;
  (*t)[prev]=nullptr;

  return t;
}

template <typename T>
T* Cdoublylinklist<T>::Split(unsigned int index)
{
  return Split(&getNode(index));
}

template <typename T>
void Cdoublylinklist<T>::Destroy()
{
	if(Cdoublylinklist<T>::head[next] && Cdoublylinklist<T>::tail[next]) Clinklist_base<T,2>::Destroy(Clinklist_base<T,2>::head,next);
	Cdoublylinklist<T>::clearbe();
}

//===================================================== Csinglylinklist =====================================================
template <typename T>
struct Csinglylinklist: public Clinklist_base<T,1>
{
	unsigned int direct;
	
	Csinglylinklist();
	~Csinglylinklist();
	
	void Add(T *t);
	T& New();
	
	T& getNode(unsigned int index) const;
	unsigned int getIndex(const T *t) const;
	
	T& Insert(T *t,unsigned int index);
	T& Insert(unsigned int index);
	
	void Remove(T *t);
	void Remove(unsigned int index);
	
	T* Split(T *t);
	T* Split(unsigned int index);
	
	void Destroy();
	
	static const unsigned int direction=0;
	
	
protected:
  void Joint(T *t1,T *t2)
  {
    if(t1) (*t1)[direct]=t2;
  }
	
};


template <typename T>
Csinglylinklist<T>::Csinglylinklist()
{
	direct=direction;
}


template <typename T>
Csinglylinklist<T>::~Csinglylinklist()
{
	Clinklist_base<T,1>::Destroy(Csinglylinklist::head,direct);
}

template <typename T>
void Csinglylinklist<T>::Add(T *t)
{
	Csinglylinklist<T>::Addnext(t,direct);
}

template <typename T>
T& Csinglylinklist<T>::New()
{
	T *t;
	Add(t=new T);
	return *t;
}

template <typename T>
T& Csinglylinklist<T>::getNode(unsigned int index) const
{
  T *tmp;
  unsigned int i;
  
  for(i=0,tmp=Csinglylinklist<T>::head[0];i<index;i++,tmp=(*tmp)[direct])
  {
    if(!tmp) break;
  }
  
  return *tmp;
}

template <typename T>
unsigned int Csinglylinklist<T>::getIndex(const T *t) const
{
  T *tmp;
  unsigned int i;
  
  for(i=0,tmp=Csinglylinklist<T>::head[0];tmp!=t;i++,tmp=(*tmp)[direct])
  {
    if(!tmp) { i=-1;break;}
  }
  
  return i;
}

template <typename T>
T& Csinglylinklist<T>::Insert(T *t,unsigned int index)
{
  T *tleft,*tright;
  
  tright=&getNode(index);
  
  if(tright==Csinglylinklist<T>::head[0])
  {
	  Joint(t,tright);
	  Csinglylinklist<T>::head[0]=t;
  }
  else
  {
	tleft=&getNode(index-1);
	Joint(tleft,t);
	Joint(t,tright);
  }
  
  return *t;
}

template <typename T>
T& Csinglylinklist<T>::Insert(unsigned int index)
{
	return Insert(new T,index);
}

template <typename T>
T* Csinglylinklist<T>::Split(T *t)
{
  T *tleft,*tright;
  
  tleft=(t==Csinglylinklist<T>::head[0])?nullptr:&getNode(getIndex(t)-1);
  tright=(t==Csinglylinklist<T>::tail[0])?nullptr:(*t)[direction];
  
  
  Joint(tleft,tright);
  
  if(tleft==nullptr)
  {
    Csinglylinklist<T>::head[0]=tright;
  }
  
   if(tright==nullptr)
  {
    Csinglylinklist<T>::tail[0]=tleft;
  }

  (*t)[direct]=nullptr;

  return t;
}

template <typename T>
T* Csinglylinklist<T>::Split(unsigned int index)
{
	return Split(&getNode(index));
}

template <typename T>
void Csinglylinklist<T>::Remove(T *t)
{
  delete Split(t);
}

template <typename T>
void Csinglylinklist<T>::Remove(unsigned int index)
{
  Remove(&getNode(index));
}

template <typename T>
void Csinglylinklist<T>::Destroy()
{
	if(Csinglylinklist<T>::head[0] && Csinglylinklist<T>::tail[0]) Clinklist_base<T,1>::Destroy(Clinklist_base<T,1>::head,direction);
	Csinglylinklist<T>::clearbe();
}
#endif
