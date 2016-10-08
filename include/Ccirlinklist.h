#include "Clinklist.h"


#ifndef _ODST_CCIRLINKLIST_H_
#define _ODST_CCIRLINKLIST_H_


//===================================================== Ccirsinglylinklist =====================================================
template <typename T>
struct Ccirsinglylinklist: public Csinglylinklist<T>
{
	~Ccirsinglylinklist();

	void Add(T *t);
	T& New();
	

	T& getNode(unsigned int index) const;		//Not deJoint()
	unsigned int getIndex(const T *t) const;	//Not deJoint()

	T& Insert(T *t,unsigned int index);
	T& Insert(unsigned int index);
	
	void Remove(T *t);
	void Remove(unsigned int index);
	
	T* Split(T *t);
	T* Split(unsigned int index);
	
	void Destroy();
	
	void deJoint(T *t,unsigned int index,unsigned int direction);
	void Joint(T *t1,T *t2,unsigned int direct);
	
	unsigned int countNode() const;
	
	protected:
	static const unsigned int direction=0;
};

template <typename T>
void Ccirsinglylinklist<T>::deJoint(T *t,unsigned int index,unsigned int direction)
{
	if(!Ccirsinglylinklist<T>::head[0] && !Ccirsinglylinklist<T>::tail[0])
	return;
	
	if(t)
	(*t)[direction]=nullptr;
}

template <typename T>
void Ccirsinglylinklist<T>::Joint(T *t1,T *t2,unsigned int direct)
{
	if(!Ccirsinglylinklist<T>::head[0] && !Ccirsinglylinklist<T>::tail[0])
	return;
	
	if(t1)
	(*t1)[direct]=t2;
}


template <typename T>
Ccirsinglylinklist<T>::~Ccirsinglylinklist()
{
	Destroy();
}


template <typename T>
void Ccirsinglylinklist<T>::Destroy()
{
	deJoint(Ccirsinglylinklist<T>::tail[0],0,direction);
	
	Csinglylinklist<T>::Destroy();
	Ccirsinglylinklist<T>::clearbe();
}

template <typename T>
void Ccirsinglylinklist<T>::Add(T *t)
{
	Csinglylinklist<T>::Add(t);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
}

template <typename T>
T& Ccirsinglylinklist<T>::New()
{
	T *t;
	Add(t=new T);
	return *t;
}

template <typename T>
T& Ccirsinglylinklist<T>::Insert(T *t,unsigned int index)
{

	deJoint(Ccirsinglylinklist<T>::tail[0],0,direction);
	
	Csinglylinklist<T>::Insert(t,index);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
	
	
	return *t;
}
	
template <typename T>
T& Ccirsinglylinklist<T>::Insert(unsigned int index)
{
	return Insert(new T,index);
}

template <typename T>
void Ccirsinglylinklist<T>::Remove(T *t)
{
	deJoint(Ccirsinglylinklist<T>::tail[0],0,direction);
	
	Csinglylinklist<T>::Remove(t);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
}

template <typename T>
void Ccirsinglylinklist<T>::Remove(unsigned int index)
{
	deJoint(Ccirsinglylinklist<T>::tail[0],0,direction);
	
	Csinglylinklist<T>::Remove(index);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
}

template <typename T>
T* Ccirsinglylinklist<T>::Split(T *t)
{
	deJoint(Ccirsinglylinklist<T>::tail[0],0,direction);
	
	Csinglylinklist<T>::Split(t);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
	
	return t;
}

template <typename T>
T* Ccirsinglylinklist<T>::Split(unsigned int index)
{
	T *t;
	deJoint(Ccirsinglylinklist<T>::tail[0],0,direction);
	
	t=Csinglylinklist<T>::Split(index);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
	
	return t;
}

template <typename T>
T& Ccirsinglylinklist<T>::getNode(unsigned int index) const
{
	T *temp1;
	unsigned int i;

	
	for(i=0,temp1=Ccirsinglylinklist<T>::head[0];i<index;i++,temp1=(*temp1)[direction])
	{
		if(temp1==Ccirsinglylinklist<T>::tail[0]) return *(temp1=nullptr);
		
	}
	
	return *temp1;
}

template <typename T>
unsigned int Ccirsinglylinklist<T>::getIndex(const T *t) const
{
	T *temp1;
	unsigned int i;
	
	if(!Ccirsinglylinklist<T>::head[0] && !Ccirsinglylinklist<T>::tail[0])
	return -1;

	temp1=Ccirsinglylinklist<T>::head[0];
	i=0;
	do
	{
		if(temp1==t)
			return i;
		
		temp1=(*temp1)[direction];
		i++;
		
	}while(temp1!=Ccirsinglylinklist<T>::head[0]);
	
	
	return -1;
}

template <typename T>
unsigned int Ccirsinglylinklist<T>::countNode() const
{
	T *temp1;
	unsigned int i;
	
	if(!Ccirsinglylinklist<T>::head[0] && !Ccirsinglylinklist<T>::tail[0]) return 0;
	
	for(i=1,temp1=Ccirsinglylinklist<T>::head[0];temp1!=Ccirsinglylinklist<T>::tail[0];i++,temp1=(*temp1)[direction]);
	
	return i;	
}

//===================================================== Ccirdoublylinklist =====================================================
template <typename T>
struct Ccirdoublylinklist: public Cdoublylinklist<T>
{
	~Ccirdoublylinklist();

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
	
	protected:
	static const unsigned int NEXT=0;
	static const unsigned int PREV=1;
};


template <typename T>
Ccirdoublylinklist<T>::~Ccirdoublylinklist()
{
	Destroy();
}


template <typename T>
void Ccirdoublylinklist<T>::Destroy()
{
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=nullptr;
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=nullptr;
	
	
	Cdoublylinklist<T>::Destroy();
	Ccirdoublylinklist<T>::clearbe();
}

template <typename T>
void Ccirdoublylinklist<T>::Add(T *t)
{
	Cdoublylinklist<T>::Add(t);
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=Ccirdoublylinklist<T>::head[NEXT];
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=Ccirdoublylinklist<T>::tail[PREV];
}

template <typename T>
T& Ccirdoublylinklist<T>::New()
{
	T *t;
	Add(t=new T);
	return *t;
}

template <typename T>
T& Ccirdoublylinklist<T>::Insert(T *t,unsigned int index)
{
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=nullptr;
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=nullptr;
	
	Cdoublylinklist<T>::Insert(t,index);
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=Ccirdoublylinklist<T>::head[NEXT];
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=Ccirdoublylinklist<T>::tail[PREV];
	
	return *t;
}
	
template <typename T>
T& Ccirdoublylinklist<T>::Insert(unsigned int index)
{
	return Insert(new T,index);
}

template <typename T>
void Ccirdoublylinklist<T>::Remove(T *t)
{
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=nullptr;
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=nullptr;
	
	Cdoublylinklist<T>::Remove(t);
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=Ccirdoublylinklist<T>::head[NEXT];
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=Ccirdoublylinklist<T>::tail[PREV];
}

template <typename T>
void Ccirdoublylinklist<T>::Remove(unsigned int index)
{
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=nullptr;
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=nullptr;
	
	Cdoublylinklist<T>::Remove(index);
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=Ccirdoublylinklist<T>::head[NEXT];
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=Ccirdoublylinklist<T>::tail[PREV];
}

template <typename T>
T* Ccirdoublylinklist<T>::Split(T *t)
{
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=nullptr;
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=nullptr;
	
	Cdoublylinklist<T>::Split(t);
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=Ccirdoublylinklist<T>::head[NEXT];
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=Ccirdoublylinklist<T>::tail[PREV];
	
	return t;
}

template <typename T>
T* Ccirdoublylinklist<T>::Split(unsigned int index)
{
	T *t;
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=nullptr;
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=nullptr;
	
	t=Cdoublylinklist<T>::Split(index);
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=Ccirdoublylinklist<T>::head[NEXT];
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=Ccirdoublylinklist<T>::tail[PREV];
	
	return t;
}

template <typename T>
T& Ccirdoublylinklist<T>::getNode(unsigned int index) const
{
	T *t;
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=nullptr;
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=nullptr;
	
	t=&Cdoublylinklist<T>::getNode(index);
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=Ccirdoublylinklist<T>::head[NEXT];
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=Ccirdoublylinklist<T>::tail[PREV];
	
	return *t;
}

template <typename T>
unsigned int Ccirdoublylinklist<T>::getIndex(const T *t) const
{
	unsigned int i;
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=nullptr;
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=nullptr;
	
	i=Cdoublylinklist<T>::getIndex(t);
	
	(*(Ccirdoublylinklist<T>::tail[NEXT]))[NEXT]=Ccirdoublylinklist<T>::head[NEXT];
	(*(Ccirdoublylinklist<T>::head[PREV]))[PREV]=Ccirdoublylinklist<T>::tail[PREV];
	
	return i;
}

#endif
