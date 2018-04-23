#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap ft("example");
	ScavTrap targ("target");

	targ.takeDamage(ft.rangedAttack("target"));
	targ.takeDamage(ft.vaulthunter_dot_exe("target"));
	ft.takeDamage(targ.challengeNewcomer("example"));
	targ.beRepaired(20);
	return 0;
}
