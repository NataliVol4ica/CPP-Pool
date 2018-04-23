#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "defines.hpp"

//;

class FragTrap
{
public:
	FragTrap(void);
	FragTrap(string name);
	FragTrap(FragTrap const &ref);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &ref); 

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
	int		att2(string const &target);
	int		att3(string const &target);
	int		att4(string const &target);

	int		vaulthunter_dot_exe(string const &target);

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

	typedef int	(FragTrap::*func)(string const &);
	
	static func attacks[];
	static const t_data defaults[];
	enum Params{HP = 0, HPMAX, ENERP, EMERPMAX, LVL, MELEE, RANGED, ARM};
};

#endif
