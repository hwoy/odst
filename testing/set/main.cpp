#include <iostream>
#include <string>
#include <odst.h>


int main()
{
	{
		odst::set<odst::set<int>> set1={{1,2,3},{4}};
		odst::set<odst::set<int>> set2={{1,2,3},{4}};
		
		std::cout << "======set1======\n";
		for(const auto i:set1)
			for(const auto j:i)
				std::cout << j << std::endl;
			
		std::cout << "======set2======\n";
		for(const auto i:set2)
			for(const auto j:i)
				std::cout << j << std::endl;
		
		std::cout << std::string("set1 ") + ((set1==set2)?"=":"!=") + " set2" << std::endl;
	}
	
	{
		odst::set<std::string> set1={"Hwoy","View"};
		odst::set<std::string> set2={"Kung","Ruam"};
		
		std::cout << "======set1======\n";
		for(const auto i:set1)
			std::cout << i << std::endl;
			
		std::cout << "======set2======\n";
		for(const auto i:set2)
			std::cout << i << std::endl;
		
		std::cout << std::string("set1 ") + ((set1==set2)?"=":"!=") + " set2" << std::endl;
	}
 	return 0;
}
