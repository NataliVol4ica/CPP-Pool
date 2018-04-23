
#include "ZombieEvent.hpp"
#include <time.h>

ZombieEvent::ZombieEvent(void)
{
	this->type = "undefined species";
}

void	ZombieEvent::setZombieType(string type)
{
	this->type = type;
}

Zombie*	ZombieEvent::newZombie(string name)
{
	Zombie *z = new Zombie(name, this->type);
	return (z);
}

Zombie*	ZombieEvent::randomChump(void)
{
	int len;
	string name = "";

	srand(time(NULL));
	len = rand () % 12 + 5;
	name += (char)(rand() % 26 + 'A');
	for (int i = 1; i < len; i++)
		name += (char)(rand() % 26 + 'a');
	return newZombie(name);
}

ZombieEvent::~ZombieEvent(void){}
