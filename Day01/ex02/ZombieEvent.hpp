#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "defines.hpp"
#include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent(void);
	~ZombieEvent(void);
	void	setZombieType(string type);
	Zombie* newZombie(string name);
	Zombie*	randomChump(void);

private:
	string type;
};

#endif
