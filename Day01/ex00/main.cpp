#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony *heap = new Pony("Heapony", 0);
	cout <<"Main confirms Pony " << heap->getname() << " was born. Gonna die anyway. " << endl;
	delete (heap);
}

void ponyOnTheStack()
{
	Pony stack("Stackpony", 0);
	cout <<"Main confirms Pony " << stack.getname() << " was born. Gonna die anyway. " << endl;
}

int	main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	system("leaks a.out");
	return (0);
}
