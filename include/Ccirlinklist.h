#include "Clinklist.h"


#ifndef _CCIRLINKLIST_H_
#define _CCIRLINKLIST_H_


//===================================================== Ccirsinglylinklist =====================================================
template <typename T>
struct Ccirsinglylinklist: public Csinglylinklist<T>
{
	~Ccirsinglylinklist();

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
	static const unsigned int direction=0;
};


template <typename T>
Ccirsinglylinklist<T>::~Ccirsinglylinklist()
{
	Destroy();
}


template <typename T>
void Ccirsinglylinklist<T>::Destroy()
{
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=nullptr;
	
	Csinglylinklist<T>::Destroy();
	Ccirsinglylinklist<T>::clearbe();
}

template <typename T>
void Ccirsinglylinklist<T>::Add(T *t)
{
	Csinglylinklist<T>::Add(t);
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=Ccirsinglylinklist<T>::head[direction];
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
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=nullptr;
	
	Csinglylinklist<T>::Insert(t,index);
	
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=Ccirsinglylinklist<T>::head[direction];
	
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
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=nullptr;
	
	Csinglylinklist<T>::Remove(t);
	
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=Ccirsinglylinklist<T>::head[direction];
}

template <typename T>
void Ccirsinglylinklist<T>::Remove(unsigned int index)
{
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=nullptr;
	
	Csinglylinklist<T>::Remove(index);
	
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=Ccirsinglylinklist<T>::head[direction];
}

template <typename T>
T* Ccirsinglylinklist<T>::Split(T *t)
{
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=nullptr;
	
	Csinglylinklist<T>::Split(t);
	
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=Ccirsinglylinklist<T>::head[direction];
	
	return t;
}

template <typename T>
T* Ccirsinglylinklist<T>::Split(unsigned int index)
{
	T *t;
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=nullptr;
	
	t=Csinglylinklist<T>::Split(index);
	
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=Ccirsinglylinklist<T>::head[direction];
	
	return t;
}

template <typename T>
T& Ccirsinglylinklist<T>::getNode(unsigned int index) const
{
	T *t;
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=nullptr;
	
	t=&Csinglylinklist<T>::getNode(index);
	
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=Ccirsinglylinklist<T>::head[direction];
	
	return *t;
}

template <typename T>
unsigned int Ccirsinglylinklist<T>::getIndex(const T *t) const
{
	unsigned int i;
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=nullptr;
	
	i=Csinglylinklist<T>::getIndex(t);
	
	(*(Ccirsinglylinklist<T>::tail[direction]))[direction]=Ccirsinglylinklist<T>::head[direction];
	
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
