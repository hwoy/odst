#ifndef _ODST_CSET_H_
#define _ODST_CSET_H_

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
	
	
	private:
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
		unsigned int j;
		
		for(unsigned int k=1;(j=find(i+k,T::getn(),T::getobj(i)))!=-1;k++)
		{
			remove(i+k+j);
			count++;
		}

	}
	
	return count;
}


#endif


