#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "defines.hpp"

class Zombie
{
public:
	Zombie(void);
	Zombie(string name, string type);
	~Zombie(void);
	void	announce(void);
	void	setz(string name, string type);
private:
	string name;
	string type;
};

#endif
