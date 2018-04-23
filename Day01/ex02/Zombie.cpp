#include "Zombie.hpp"

Zombie::Zombie(string name, string type)
{
	this->name = name;
	this->type = type;
	cout << "A newborn zombie! Meet " << name << " <3" << endl;
}

void	Zombie::announce(void)
{
	string s = "<" + this->name + " (" + this->type + ")> Braiiiiiiinnnssss...";
	cout << s <<endl;
}

Zombie::~Zombie(void){}

