
#include "ZombieHorde.hpp"
#include <time.h>
#include <exception>

ZombieHorde::ZombieHorde(int n)
{
	try	{
		this->zombies = new Zombie[n];
	}
	catch (std::exception& e)
	{
		cout << "Standart exception: " << e.what() << endl;
		exit (0);
	}
	this->numofzombies = n;
	//for (int i = 0; i < n; i++)
	//	randomChump(&this->zombies[i]);
}

void	ZombieHorde::setZombieType(string type)
{
	this->type = type;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->numofzombies; i++)
		this->zombies[i].announce();
	//cout << this->numofzombies<<endl;
}

Zombie*	ZombieHorde::newZombie(string name)
{
	Zombie *z = new Zombie(name, this->type);
	return (z);
}

void	ZombieHorde::randomChump(Zombie *z)
{
	int len;
	string name = "";

	len = arc4random_uniform(12) + 5;
	name += (char)(arc4random_uniform(26) + 'A');
	for (int i = 1; i < len; i++)
		name += (char)(arc4random_uniform(26) + 'a');
	z->setz(name, "unknown species");
}

ZombieHorde::~ZombieHorde(void)
{
	delete[] this->zombies;
	cout << "everybody destroyed"<<endl;
}
