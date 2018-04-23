#include "Zombie.hpp"

Zombie::Zombie(string name, string type)
{
	this->setz(name, type);
}

Zombie::Zombie(void)
{
	//this->type = "undefined species";
	//this->name = "noname";
	

	int len;
	string name = "";

	len = arc4random_uniform(12) + 5;
	name += (char)(arc4random_uniform(26) + 'A');
	for (int i = 1; i < len; i++)
		name += (char)(arc4random_uniform(26) + 'a');
	setz(name, "undefined species");
	
}

void	Zombie::setz(string name, string type)
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

