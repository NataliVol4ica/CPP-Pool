#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "defines.hpp"

//;

class ScavTrap
{
public:
	ScavTrap(void);
	ScavTrap(string name);
	ScavTrap(ScavTrap const &ref);
	~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &ref); 

/* GET SET... */
	string	getName(void) const;
	int		getHP(void) const;
	int		getHPMAX(void) const;
	int		getENERP(void) const;
	int		getENERPMAX(void) const;
	int		getLVL(void) const;
	int		getMELEE(void) const;
	int		getRANGED(void) const;
	int		getARM(void) const;

	void	setName(string const val);
	void	setHP(int const val);
	void	setHPMAX(int const val);
	void	setENERP(int const val);
	void	setENERPMAX(int const val);
	void	setLVL(int const val);
	void	setMELEE(int const val);
	void	setRANGED(int const val);
	void	setARM(int const val);

/* OTHER FUNCS */
	int		rangedAttack(string const &target);
	int		meleeAttack(string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	spendEnergy(unsigned int amount);
	void	restoreEnergy(unsigned int amount);
	int		chal2(string const &target);
	int		chal3(string const &target);
	int		chal4(string const &target);

	int		challengeNewcomer(string const &target);

private:
	static string const	type;
	string	name;
	int 	hitPoints;
	int 	hitPoints_max;
	int		energyPoints;
	int		energyPoints_max;
	int		level;
	int		meleeAttackDamage;
	int		rangedAttackDamage;
	int		armorDamageReduction;

	typedef int	(ScavTrap::*func)(string const &);
	
	static func attacks[];
	static const t_data defaults[];
	enum Params{HP = 0, HPMAX, ENERP, EMERPMAX, LVL, MELEE, RANGED, ARM};
};

#endif
