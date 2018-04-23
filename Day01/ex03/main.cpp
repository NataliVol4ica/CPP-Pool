
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int	main(void)
{
	srand(time(NULL));
	ZombieHorde *zi = new ZombieHorde(4);
	zi->announce();
	delete(zi);
	//system("leaks a.out");
	return 0;
}
