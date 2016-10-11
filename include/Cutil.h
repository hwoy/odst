#ifndef _ODST_CUTIL_H_
#define _ODST_CUTIL_H_

template <typename T>
void _swap(T *a,T *b)
{
	T tmp;
	tmp=*b;
	
	*b=*a;
	*a=tmp;
}

template <typename T>
void add(T &a,const T &b)
{
	for(unsigned int i=0;i<b.getn();i++)
	a.add(b[i]);	
}

template <typename T>
void copy(T &a,const T &b)
{
	a.clear();
	add<T>(a,b);
}

template <typename T,typename U,typename V>
void countif(const T &a,const U &b,V v)
{
	unsigned int count=0;
	for(unsigned int i=0;i<a.getn();i++)
	{
		if(v(b,a[i])) count++;
	}
	
	return count;
}

template <typename T,typename U>
unsigned int find(const T &t,unsigned int begin,unsigned int end,const U &u)
{
	unsigned int i;
	
	for(i=0;begin+i<end;i++)
	{
		if(u==t[begin+i]) break;
	}

	return begin+i==end?-1:i;
}
template <typename T,typename U>
unsigned int findm(const T &t,unsigned int begin,unsigned int end,U u)
{
	unsigned int i,j;
	if(begin > end) return -1;
	
	for(i=0,j=1;begin+j<end;j++)
	{

		if(u(t[begin+j],t[begin+i]))
			{
				i=j;
			}
	}
	
	return i;
}

template <typename T,typename U>
void arrang(const T &t,unsigned int begin,unsigned int end,U u)
{
	unsigned int i,j;
	if(begin > end) return;
	
	for(i=0;begin+i+1<end;i++)
	{
		
		j=findm<T,U>(t,i+begin,end,u);
		_swap(&t[i+begin],&t[i+j+begin]);
	}
}

/* ISO C++14 auto parameter lamda express
auto _lammax = [](auto &a,auto &b) {return a>b;};
auto _lammin = [](auto &a,auto &b) {return a<b;};
*/

template <typename T>
constexpr bool _max(const T &a,const T &b)
{
	return (a>b);
}

template <typename T>
constexpr bool _min(const T &a,const T &b)
{
	return (a<b);
}

#endif


