#include <algorithm>
#include <iostream>
#include <odst.h>

int main()
{
    {
        std::cout << "List Reverse\n";
        odst::list<int> list = { 1, 2, 3, 4, 5 };

        for (odst::Citerator_doublylinklist<odst::list<int>::node_t> i = list.rbegin().base(); i != list.rend(); --i)
            std::cout << *i << std::endl;
    }

    {
        std::cout << "List Remove\n";
        odst::list<int> list = { -1, 0, 1, 2, 3, 4, 5 };
        list.erase(std::remove_if(list.begin(), list.end(), [](int a) -> bool { return a >= 3; }), list.end());

        for (auto i : list)
            std::cout << i << std::endl;
    }

    return 0;
}
