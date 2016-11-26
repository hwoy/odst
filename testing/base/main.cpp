#include <cstdlib>
#include <iostream>
#include <odst.h>

#define BASE 16
#define RANG_MIN 1
#define RANG_MAX 10000000

typedef odst::Cvector<unsigned int>
  vector_t;

static void
dec2base(unsigned int num, unsigned int base, vector_t& list)
{
  unsigned int i;
  i = num;
  do
    list.push_front(i % base);
  while (i /= base);
}

static void
show(unsigned int num, unsigned int base, const vector_t& list)
{

  std::cout << num << " = ";

  for (auto& i : list) {
    if(base==16 && i>9) std::cout << static_cast<char>('A'+i-10);
	else std::cout << i;
	std::cout << " ";
  }

  std::cout << '\n';
}
unsigned int random(unsigned int min,unsigned int max)
{
	return rand()%(max-min+1)+min;
}

int main(void)
{
  unsigned int i, j;
  vector_t list;

  std::srand(time(nullptr));

  for (j = 0; j < 10; j++) {
    i = random(RANG_MIN,RANG_MAX);
    dec2base(i, BASE, list);
    show(i, BASE ,list);
    list.clear();
  }

  return 0;
}
