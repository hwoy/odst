#include <iostream>
#include <odst.h>
#include <random>
#include <chrono>

#define BASE 16
#define RANG_MIN 1
#define RANG_MAX 10000000

typedef odst::svector<unsigned int, 32> base_t;

static void
dec2base(unsigned int num, unsigned int base, base_t& list)
{
    unsigned int i;
    i = num;
    do
        list.push_front(i % base);
    while (i /= base);
}

static void
show(unsigned int num, unsigned int base, const base_t& list)
{

    std::cout << num << " = ";

    for (auto& i : list) {
        if (base == 16 && i > 9)
            std::cout << static_cast<char>('A' + i - 10);
        else
            std::cout << i;
        std::cout << " ";
    }

    std::cout << '\n';
}

int main(void)
{
    unsigned int i, j;
    base_t list;

    std::mt19937 gen(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    std::uniform_int_distribution<> dis(RANG_MIN, RANG_MAX);

    for (j = 0; j < 10; j++) {
        i = dis(gen);
        dec2base(i, BASE, list);
        show(i, BASE, list);
        list.clear();
    }

    return 0;
}
