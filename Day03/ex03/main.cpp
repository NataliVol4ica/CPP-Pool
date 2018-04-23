#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main(void)
{
	FragTrap ft("example");
	ScavTrap targ("target");
	NinjaTrap nin("KILLEMALL");

	targ.takeDamage(ft.rangedAttack("target"));
	targ.takeDamage(ft.vaulthunter_dot_exe("target"));
	ft.takeDamage(targ.challengeNewcomer("example"));
	ft.takeDamage(targ.challengeNewcomer("example"));
	targ.beRepaired(20);
	nin.ninjaShoebox(targ);
	nin.ninjaShoebox(ft);
	return 0;
}
