#include "FragTrap.hpp"

int		main(void)
{
	FragTrap ft("example");
	FragTrap targ("target");
	ft.rangedAttack("target");
	targ.takeDamage(ft.rangedAttack("target"));
	targ.takeDamage(ft.meleeAttack("target"));
	targ.takeDamage(ft.vaulthunter_dot_exe("target"));
	targ.takeDamage(ft.vaulthunter_dot_exe("target"));
	targ.takeDamage(ft.vaulthunter_dot_exe("target"));
	targ.takeDamage(ft.vaulthunter_dot_exe("target"));
	targ.takeDamage(ft.vaulthunter_dot_exe("target"));
	targ.takeDamage(ft.vaulthunter_dot_exe("target"));
	return 0;
}
