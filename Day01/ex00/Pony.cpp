#include "Pony.hpp"

Pony::Pony(string name, int type)
{
	this->name = name;
	this->type = type;
	cout << "A pony of type " << type << " was born and its name is " << name << endl;
}

string Pony::getname(void) const
{
	return this->name;
}

Pony::~Pony(void)
{
	cout << "Pony " << this->name << " is dying. Horray! " << endl;
}
