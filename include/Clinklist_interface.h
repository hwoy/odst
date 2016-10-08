
#ifndef _CLINKLIST_INTERFACE_H_
#define _CLINKLIST_INTERFACE_H_

//===================================================== Clinklist_interface =====================================================


template <typename T,typename V,typename U>
struct Clinklist_interface : public T
{
	unsigned int getn() const
	{
		V *v;
		unsigned int n;
		
		for(n=0,v=T::head[0];v;v=(*v)[0],n++);
		
		return n;
	}
	
	void insert(const U &u,unsigned int index)
	{
		V *v;
		v = new V;
		v->data=u;
		
		T::Insert(v,index);
	}
	
	void remove(unsigned int index)
	{
		T::Remove(index);
	}
	
	void destroy()
	{
		T::Destroy();
	}
	
	U* split(unsigned int index)
	{
		U *u;
		
		u = new U;
		
		*u=T::getNode(index).data;
		
		T::Remove(index);
		
		return u;
	}
	
	U& operator[](unsigned int index) const
	{
		return T::getNode(index).data;
	}
	
	Clinklist_interface& assign(unsigned int length)
	{
		T::Destroy();
		for(unsigned int i=0;i<length;i++)
		{
			T::New();
		}
		
		return *this;
	}
	
	
};

#endif
