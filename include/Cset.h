#ifndef _ODST_CSET_H_
#define _ODST_CSET_H_

#include "../include/Cdynamicarray.h"
#include "../include/Cvector.h"
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
	bool issubset(const Cset_interface &set) const;
	
	protected:
	unsigned int find(unsigned int begin,unsigned int end,U &u) const;
	
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
unsigned int Cset_interface<T,U>::find(unsigned int begin,unsigned int end,U &u) const
{
	unsigned int i;
	
	for(i=0;begin+i<end;i++)
	{
		if(u==T::getobj(begin+i)) break;
	}

	return begin+i==end?-1:i;
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
		if(find(0,T::getn(),set.getobj(i))==-1)
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
	Cvector_interface<Cdynamicarray<unsigned int>,unsigned int> tmp;
	unsigned int count=0;
	for(unsigned int i=0;i<T::getn();i++)
	{
		for(unsigned int j=0;j<set.getn();j++)
		{
			if(T::getobj(i)==set.getobj(j))
			{
				tmp << i;
				break;
			}
		}
	}

		
	for(unsigned int i=T::getn(); i>0;i--)
	{
		unsigned int j;
		for(j=tmp.getn(); j>0;j--)
			{
				if((i-1)==tmp.getobj(j-1)) break;
			}
			if(j==0 || tmp.getn()==0)
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


#endif


