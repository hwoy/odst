#include <iostream>
#include <string>
#include <odst.h>


int main()
{
	{
		odst::set<odst::set<int>> set1={{1,2,3},{4}};
		odst::set<odst::set<int>> set2={{1,2,3},{4}};

		set1.add({1,2,3});
		
		std::cout << "======set1======\n";
		std::cout << set1 << std::endl;
			
		std::cout << "======set2======\n";
		std::cout << set2 << std::endl;
		
		std::cout << std::string("set1 ") + ((set1==set2)?"=":"!=") + " set2" << std::endl;
	}
	
	{
		odst::set<std::string> set1={"Hwoy","View"};
		odst::set<std::string> set2={"Kung","Ruam"};
		
		std::cout << "======set1======\n";
		std::cout << set1 << std::endl;
			
		std::cout << "======set2======\n";
		std::cout << set2 << std::endl;
		
		std::cout << std::string("set1 ") + ((set1==set2)?"=":"!=") + " set2" << std::endl;
	}
 	return 0;
}
