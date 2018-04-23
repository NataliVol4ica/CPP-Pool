#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "defines.hpp"

class Zombie
{
public:
	Zombie(string name, string type);
	~Zombie(void);
	void	announce(void);
private:
	string name;
	string type;
};

#endif
