#ifndef _ODST_CSET_H_
#define _ODST_CSET_H_

#include "Cutil.h"


//===================================================== Cset_interface =====================================================
template <typename T,typename U>
class Cset_interface : public T
{

	
	public:

	
	Cset_interface& operator<<(const U &u);
	U& operator[](unsigned int index) const;
	
	
	void add(const U &u);
	void remove(unsigned int index);
	void remove();
	
	
	void insert(const U &u ,unsigned int index);
	
	
	
	/*		Core Methodes		*/
	
	unsigned int pack();
	unsigned int _union(const Cset_interface &set);
	unsigned int intersect(const Cset_interface &set);
	unsigned int sub(const Cset_interface &set);
	bool issubset(const Cset_interface &set) const;
	bool equal(const Cset_interface &setconst ) const;
	
	
};



template <typename T,typename U>
void Cset_interface<T,U>::add(const U &u)
{
  T::insert(u,T::getn());
}


template <typename T,typename U>
void Cset_interface<T,U>::remove(unsigned int index)
{
  T::remove(index);
}

template <typename T,typename U>
void Cset_interface<T,U>::remove()
{
  T::remove(T::getn()-1);
}


template <typename T,typename U>
Cset_interface<T,U>& Cset_interface<T,U>::operator<<(const U &u)
{
  add(u);
  return *this;
}

template <typename T,typename U>
U& Cset_interface<T,U>::operator[](unsigned int index) const
{
  return T::getobj(index);
}

template <typename T,typename U>
void Cset_interface<T,U>::insert(const U &u ,unsigned int index)
{
T::insert(u,index);
}


template <typename T,typename U>
unsigned int Cset_interface<T,U>::pack()
{
	unsigned int count;
	count=0;
	
	for(unsigned int i=0;i<T::getn();i++)
	{
		
		for(unsigned int j=i+1;j<T::getn();)
		{
			if(T::getobj(i)==T::getobj(j))
			{
				remove(j);
				count++;
				continue;
			}
			j++;
			
		}

	}
	
	return count;
}

template <typename T,typename U>
unsigned int Cset_interface<T,U>::_union(const Cset_interface<T,U> &set)
{
	unsigned int count;
	count=0;
	
	for(unsigned int i=0;i<set.getn();i++)
	{
		if(::find(*this,0,T::getn(),set.getobj(i))==-1U)
		{
			add(set.getobj(i));
			count++;
		}

	}
	
	return count;
}

template <typename T,typename U>
unsigned int Cset_interface<T,U>::intersect(const Cset_interface<T,U> &set)
{
	unsigned int count=0;
		
	for(unsigned int i=T::getn(); i>0;i--)
	{
		if(::find(set,0,set.getn(),T::getobj(i-1))==-1U)
		{
			remove(i-1);
			count++;
		}
	}


	
	return count;
}

template <typename T,typename U>
bool Cset_interface<T,U>::issubset(const Cset_interface &set) const
{
	for(unsigned int j=0;j<set.getn();j++)
	{
		for(unsigned int i=0;i<T::getn();i++)
		{
			if(!(T::getobj(i)==set.getobj(j)))
			{
				return false;
			}
		}
	}
	
	return true;	
}

template <typename T,typename U>
unsigned int Cset_interface<T,U>::sub(const Cset_interface<T,U> &set)
{
	unsigned int count=0;
		
	for(unsigned int i=T::getn(); i>0;i--)
	{
		if(::find(set,0,set.getn(),T::getobj(i-1))!=-1U)
		{
			remove(i-1);
			count++;
		}
	}


	
	return count;
}

template <typename T,typename U>
bool Cset_interface<T,U>::equal(const Cset_interface &set) const
{
	Cset_interface<T,U> a,b;
	bool isequal;
	::copy(a,*this);
	::copy(b,set);
	
	a.pack();
	b.pack();
	
	if(a.getn() != b.getn()) return false;
	
	for(unsigned int i=0;i<a.getn();i++)
	{
		isequal=false;
		for(unsigned int j=0;j<b.getn();j++)
		{
			if(a[i]==b[j])
				isequal=true;
		}
		if(!isequal) return false;
	}
	
	return true;
}


#endif


