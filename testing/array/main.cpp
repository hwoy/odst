#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <iterator>
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
void rprint(const odst::array<T,N> &array)
{
	for(auto i=array.rbegin();i!=array.rend();i++)
		rprint(*i);
}

int main()
{
	{
	std::cout << "Array 1\n";
	odst::array<odst::array<int,3>,2> array={ {  {{1,2,3}}  , {{4,5,6}}      }  };
	print(array);
	rprint(array);
	}
	{

		std::cout << "Array 2\n";
		odst::array<odst::vector<int>,2> array={ {  {1,2,3,4} , {5,6,7,8,9}     }  };
	
		for(const auto i:array)
			for(const auto j:i)
				std::cout << j << std::endl;

	}
	{

		std::cout << "Array 3\n";
		odst::vector<odst::array<int,2>> array={ {{1,2}} , {{3,4}} , {{5,6}} };
	
		for(const auto i:array)
			for(const auto j:i)
				std::cout << j << std::endl;

	}
	{
		std::cout << "Doubly linklist\n";
		odst::list<odst::list<unsigned int>> list={{1},{1,2,3},{0,1}};

		for(const auto i:list)
			for(const auto j:i)
				std::cout << j << std::endl;
	}
	{
		std::cout << "Doubly linklist Reverse\n";
		std::vector<unsigned int> vec={1,2,3,4,5};
		odst::list<unsigned int> list(vec.begin(),vec.end());

		for(auto i=list.rbegin();i!=list.rend();i++)
				std::cout << *i << std::endl;
	}
	{
		std::cout << "Singly linklist\n";
		odst::list_forward<odst::list_forward<unsigned int>> list={{1,2,3,4,5,6},{1,2,3},{0,1}};

		for(const auto i:list)
			for(const auto j:i)
				std::cout << j << std::endl;
	}
	{
		std::cout << "Circular Doubly linklist\n";
		odst::cirlist<odst::cirlist<unsigned int>> list={{1,2,3},{2,3,4,5}};

		while(list.size())
		{
			auto i=list.split(0);
			
			while(i.size())
			std::cout << i.split(0) << std::endl;
		}


	}
	{
		std::cout << "Circular Singly linklist\n";
		odst::cirlist_forward<unsigned int> list={6,7,8,9,10};
		while(list.size())
		{
			std::cout << list.split(0) << std::endl;
		}

	}
	
	{
		std::cout << "Random vector\n";
		std::mt19937 gen(time(nullptr));
		odst::vector<int> vec={1,2,3,4,5,6,7,8,9,10};
		std::shuffle(vec.begin(),vec.end(),gen);
		
		for(const auto i:vec)
			std::cout << i << std::endl;
	}
	
	{
		std::cout << "Vector Back Inserter\n";
		odst::vector<int> vec={1,2,3,4,5,6,7,8,9,10};
		std::fill_n(std::back_inserter(vec),50,-1);
		
		for(const auto i:vec)
			std::cout << i << std::endl;
	}
	
	{
		std::cout << "List Back Inserter\n";
		odst::list<int> list={1,2,3,4,5};
		std::fill_n(std::back_inserter(list),50,-2);
		
		for(const auto i:list)
			std::cout << i << std::endl;
	}
 	return 0;
}
