#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main(void)
{
	FragTrap frag("frag");
	NinjaTrap ninja("ninja");
	SuperTrap super ("super");

	ninja.takeDamage(frag.rangedAttack("ninja"));
	frag.takeDamage(ninja.meleeAttack("frag"));
	
	ninja.takeDamage(super.att2("ninja"));
	frag.takeDamage(super.att3("frag"));

	super.ninjaShoebox(ninja);
	super.ninjaShoebox(frag);
	return 0;
}
