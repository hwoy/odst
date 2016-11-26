#include <iostream>
#include <odst.h>

template <typename T>
void print(const T &i)
{
		std::cout << i << std::endl;
}
template <typename T>

void rprint(const T &i)
{
		std::cout << i << std::endl;
}

template <typename T,unsigned int N>
void print(const odst::Carray<T,N> &array)
{
	for(const auto &i:array)
		print(i);
}

template <typename T,unsigned int N>
void rprint(const odst::Carray<T,N> &array)
{
	for(auto i=array.rbegin();i!=array.rend();i++)
		rprint(*i);
}

int main()
{
	{
	std::cout << "Array 1\n";
	odst::Carray<odst::Carray<int,3>,2> array={ {  {{1,2,3}}  , {{4,5,6}}      }  };
	print(array);
	rprint(array);
	}
	{

		std::cout << "Array 2\n";
		odst::Carray<odst::Cvector<int>,2> array={ {  {1,2,3,4} , {5,6,7,8,9}     }  };
	
		for(const auto i:array)
			for(const auto j:i)
				std::cout << j << std::endl;

	}
	{

		std::cout << "Array 3\n";
		odst::Cvector<odst::Carray<int,2>> array={ {{1,2}} , {{3,4}} , {{5,6}} };
	
		for(const auto i:array)
			for(const auto j:i)
				std::cout << j << std::endl;

	}
  return 0;
}
