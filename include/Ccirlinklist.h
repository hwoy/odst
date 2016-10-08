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
	
	void deJoint(T *t,unsigned int direction);
	void Joint(T *t1,T *t2,unsigned int direct);
	
	unsigned int countNode() const;				//Not deJoint()
	
	protected:
	static const unsigned int direction=0;
};

template <typename T>
void Ccirsinglylinklist<T>::deJoint(T *t,unsigned int direction)
{
	if(Ccirsinglylinklist<T>::isEmpty())
	return;
	
	if(t)
	(*t)[direction]=nullptr;
}

template <typename T>
void Ccirsinglylinklist<T>::Joint(T *t1,T *t2,unsigned int direct)
{
	if(Ccirsinglylinklist<T>::isEmpty())
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
	deJoint(Ccirsinglylinklist<T>::tail[0],direction);
	
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

	deJoint(Ccirsinglylinklist<T>::tail[0],direction);
	
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
	deJoint(Ccirsinglylinklist<T>::tail[0],direction);
	
	Csinglylinklist<T>::Remove(t);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
}

template <typename T>
void Ccirsinglylinklist<T>::Remove(unsigned int index)
{
	deJoint(Ccirsinglylinklist<T>::tail[0],direction);
	
	Csinglylinklist<T>::Remove(index);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
}

template <typename T>
T* Ccirsinglylinklist<T>::Split(T *t)
{
	deJoint(Ccirsinglylinklist<T>::tail[0],direction);
	
	Csinglylinklist<T>::Split(t);
	
	Joint(Ccirsinglylinklist<T>::tail[0],Ccirsinglylinklist<T>::head[0],direction);
	
	return t;
}

template <typename T>
T* Ccirsinglylinklist<T>::Split(unsigned int index)
{
	T *t;
	deJoint(Ccirsinglylinklist<T>::tail[0],direction);
	
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
	
	if(Ccirsinglylinklist<T>::isEmpty())
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
	
	if(Ccirsinglylinklist<T>::isEmpty()) return 0;
	
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
	

	T& getNode(unsigned int index) const;					//Not deJoint()
	unsigned int getIndex(const T *t) const;				//Not deJoint()

	T& Insert(T *t,unsigned int index);
	T& Insert(unsigned int index);
	
	void Remove(T *t);
	void Remove(unsigned int index);
	
	T* Split(T *t);
	T* Split(unsigned int index);
	
	unsigned int countNode() const;							//Not deJoint()
	
	void Destroy();
	
	void deJoint(T *t,unsigned int direction);
	void Joint(T *t1,T *t2,unsigned int direct);
	
	protected:
	static const unsigned int NEXT=0;
	static const unsigned int PREV=1;
};

template <typename T>
void Ccirdoublylinklist<T>::deJoint(T *t,unsigned int direction)
{
	if(Ccirdoublylinklist<T>::isEmpty())
	return;
	
	if(t)
	(*t)[direction]=nullptr;
}

template <typename T>
void Ccirdoublylinklist<T>::Joint(T *t1,T *t2,unsigned int direct)
{
	if(Ccirdoublylinklist<T>::isEmpty())
	return;
	
	if(t1)
	(*t1)[direct]=t2;
}

template <typename T>
Ccirdoublylinklist<T>::~Ccirdoublylinklist()
{
	Destroy();
}


template <typename T>
void Ccirdoublylinklist<T>::Destroy()
{
	
	deJoint(Ccirdoublylinklist<T>::tail[NEXT],NEXT);
	deJoint(Ccirdoublylinklist<T>::head[PREV],PREV);
	
	Cdoublylinklist<T>::Destroy();
	Ccirdoublylinklist<T>::clearbe();
}

template <typename T>
void Ccirdoublylinklist<T>::Add(T *t)
{
	Cdoublylinklist<T>::Add(t);
	
	
	Joint(Ccirdoublylinklist<T>::tail[NEXT],Ccirdoublylinklist<T>::head[NEXT],NEXT);
	Joint(Ccirdoublylinklist<T>::head[PREV],Ccirdoublylinklist<T>::tail[PREV],PREV);
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
	deJoint(Ccirdoublylinklist<T>::tail[NEXT],NEXT);
	deJoint(Ccirdoublylinklist<T>::head[PREV],PREV);
	
	Cdoublylinklist<T>::Insert(t,index);
	
	Joint(Ccirdoublylinklist<T>::tail[NEXT],Ccirdoublylinklist<T>::head[NEXT],NEXT);
	Joint(Ccirdoublylinklist<T>::head[PREV],Ccirdoublylinklist<T>::tail[PREV],PREV);
	
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
	deJoint(Ccirdoublylinklist<T>::tail[NEXT],NEXT);
	deJoint(Ccirdoublylinklist<T>::head[PREV],PREV);
	
	Cdoublylinklist<T>::Remove(t);
	
	Joint(Ccirdoublylinklist<T>::tail[NEXT],Ccirdoublylinklist<T>::head[NEXT],NEXT);
	Joint(Ccirdoublylinklist<T>::head[PREV],Ccirdoublylinklist<T>::tail[PREV],PREV);
}

template <typename T>
void Ccirdoublylinklist<T>::Remove(unsigned int index)
{
	deJoint(Ccirdoublylinklist<T>::tail[NEXT],NEXT);
	deJoint(Ccirdoublylinklist<T>::head[PREV],PREV);
	
	Cdoublylinklist<T>::Remove(index);
	
	Joint(Ccirdoublylinklist<T>::tail[NEXT],Ccirdoublylinklist<T>::head[NEXT],NEXT);
	Joint(Ccirdoublylinklist<T>::head[PREV],Ccirdoublylinklist<T>::tail[PREV],PREV);
}

template <typename T>
T* Ccirdoublylinklist<T>::Split(T *t)
{
	deJoint(Ccirdoublylinklist<T>::tail[NEXT],NEXT);
	deJoint(Ccirdoublylinklist<T>::head[PREV],PREV);
	
	Cdoublylinklist<T>::Split(t);
	
	Joint(Ccirdoublylinklist<T>::tail[NEXT],Ccirdoublylinklist<T>::head[NEXT],NEXT);
	Joint(Ccirdoublylinklist<T>::head[PREV],Ccirdoublylinklist<T>::tail[PREV],PREV);
	
	return t;
}

template <typename T>
T* Ccirdoublylinklist<T>::Split(unsigned int index)
{
	T *t;
	
	deJoint(Ccirdoublylinklist<T>::tail[NEXT],NEXT);
	deJoint(Ccirdoublylinklist<T>::head[PREV],PREV);
	
	t=Cdoublylinklist<T>::Split(index);
	
	Joint(Ccirdoublylinklist<T>::tail[NEXT],Ccirdoublylinklist<T>::head[NEXT],NEXT);
	Joint(Ccirdoublylinklist<T>::head[PREV],Ccirdoublylinklist<T>::tail[PREV],PREV);
	
	return t;
}

template <typename T>
T& Ccirdoublylinklist<T>::getNode(unsigned int index) const
{
	T *temp1;
	unsigned int i;

	
	for(i=0,temp1=Ccirdoublylinklist<T>::head[NEXT];i<index;i++,temp1=(*temp1)[NEXT])
	{
		if(temp1==Ccirdoublylinklist<T>::tail[NEXT]) return *(temp1=nullptr);
		
	}
	
	return *temp1;
}

template <typename T>
unsigned int Ccirdoublylinklist<T>::getIndex(const T *t) const
{
	T *temp1;
	unsigned int i;
	
	if(Ccirdoublylinklist<T>::isEmpty())
	return -1;

	temp1=Ccirdoublylinklist<T>::head[NEXT];
	i=0;
	do
	{
		if(temp1==t)
			return i;
		
		temp1=(*temp1)[NEXT];
		i++;
		
	}while(temp1!=Ccirdoublylinklist<T>::head[NEXT]);
	
	
	return -1;
}

template <typename T>
unsigned int Ccirdoublylinklist<T>::countNode() const
{
	T *temp1;
	unsigned int i;
	
	if(Ccirdoublylinklist<T>::isEmpty()) return 0;
	
	for(i=1,temp1=Ccirdoublylinklist<T>::head[0];temp1!=Ccirdoublylinklist<T>::tail[0];i++,temp1=(*temp1)[NEXT]);
	
	return i;	
}

#endif
