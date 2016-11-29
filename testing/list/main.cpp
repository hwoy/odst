#include <iostream>
#include <algorithm>
#include <odst.h>



int main()
{
	{
		std::cout << "List\n";
		odst::list<int> list={1,2,3,4,5};
		list.erase(std::remove_if(list.begin(),list.end(),[](int a)->bool{return a>=3;}),list.end());
	
		
		for(const auto i:list)
			std::cout << i << std::endl;
	
	}
 	return 0;
}
