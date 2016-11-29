#include <iostream>
#include <algorithm>
#include <odst.h>



int main()
{
	{
		std::cout << "List\n";
		odst::svector<int,32> list={1,2,3,4,5};
		list.erase(std::remove_if(list.begin(),list.end(),[](int a)->bool{return a>1 && a<5;}),list.end());
	
		
		for(const auto i:list)
			std::cout << i << std::endl;
	
	}
 	return 0;
}
