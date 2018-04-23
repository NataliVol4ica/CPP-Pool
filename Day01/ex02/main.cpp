
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)
{
	ZombieEvent zi;
	Zombie *z = zi.randomChump();
	z->announce();
	system("leaks a.out");
	return 0;
}
