#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "defines.hpp"
#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int n);
	~ZombieHorde(void);
	void	setZombieType(string type);
	void	announce(void);
	Zombie* newZombie(string name);
	void	randomChump(Zombie *z);

private:
	string type;
	Zombie *zombies;
	int		numofzombies;
};

#endif
