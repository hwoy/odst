#include <iostream>
#include <string>
#include <algorithm>
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
	
	{
		odst::set<odst::set<int>> set1={{1,2,3},{4},{5,6},{5,6},{7}};
		std::cout << "======set1======\n";
		std::cout << set1 << std::endl;
			
		set1.erase(std::remove(set1.begin(),set1.end(),odst::set<int>{5,6}),set1.end());
		std::cout << "======set1 erase======\n";
		std::cout << set1 << std::endl;

	}
	

	std::cout << "======union======\n";
	std::cout << (odst::set<int>{1,2,3} | odst::set<int>{1,4,2,5,6}) << std::endl;
	
	std::cout << "======intersect======\n";
	std::cout << (odst::set<int>{1,2,3} & odst::set<int>{1,4,2,5,6}) << std::endl;
	
	std::cout << "======sub======\n";
	std::cout << (odst::set<int>{1,2,3} - odst::set<int>{1,4,2,5,6}) << std::endl;
	
	{
		odst::set<int> set1={1,2,3,4,5,6};
		set1|={1,5,8};
		std::cout << "======union======\n";
		std::cout << set1 << std::endl;		
	}
	
	{
		odst::set<int> set1={1,2,3,4,5,6};
		set1&={1,5,8};
		std::cout << "======intersect======\n";
		std::cout << set1 << std::endl;		
	}
	
	{
		odst::set<int> set1={1,2,3,4,5,6};
		set1-={1,5,8};
		std::cout << "======sub======\n";
		std::cout << set1 << std::endl;		
	}
	
	{
		odst::set<int> set1={6,1,2,3,4,5,6},set2={3,2,3};
		std::cout << "====== < ======\n";
		std::cout << std::boolalpha << (set1<set2) << std::endl;		
	}

	{
		odst::set<int> set1={6,1,2,3,4,5,6},set2={3,2,3,0,0};
		std::cout << "====== < ======\n";
		std::cout << std::boolalpha << (set1<set2) << std::endl;		
	}

 	return 0;
}
