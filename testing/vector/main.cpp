#include <iostream>
#include <algorithm>
#include <vector>
#include <odst.h>



int main()
{
	{
		std::cout << "vetor\n";
		odst::svector<int,32> list={1,2,3,4,5};
		list.erase(std::remove_if(list.begin(),list.end(),[](int a)->bool{return a>1 && a<5;}),list.end());
	
		
		for(const auto i:list)
			std::cout << i << std::endl;
	
	}

	{
	
		std::cout << "vetor Unique\n";

		odst::vector<odst::vector<int>> list={{1,2,3},{4,5},{2,2},{1,1,1},{4,4},{5,5,5},{5,5,5}};
		list.push_front({6,6});
		list.push_front({7});
		std::sort(list.begin(),list.end());
		list.erase(std::unique(list.begin(),list.end()),list.end());
	
		for(const auto &i:list)
			for(const auto &j:i)
				std::cout << j << std::endl;
		
	
	}
	
	{
		std::cout << "vetor arrange\n";
		odst::svector<int,32> list={6,1,2,3,7,8,4,5};
		
		odst::sort(list,0,list.size(),odst::_min<int>);
	
		
		for(const auto i:list)
			std::cout << i << std::endl;
	
	}
 	return 0;
}
