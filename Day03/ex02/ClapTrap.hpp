#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "defines.hpp"

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(string const &name);
	~ClapTrap(void);

	ClapTrap &operator=(ClapTrap const &ref); 

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
	void	born(const string &type) const;
	int		rangedAttack(string const &target);
	int		meleeAttack(string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	spendEnergy(unsigned int amount);
	void	restoreEnergy(unsigned int amount);

protected:
	string	type;
	string	name;
	int 	hitPoints;
	int 	hitPoints_max;
	int		energyPoints;
	int		energyPoints_max;
	int		level;
	int		meleeAttackDamage;
	int		rangedAttackDamage;
	int		armorDamageReduction;
	enum Params{HP = 0, HPMAX, ENERP, EMERPMAX, LVL, MELEE, RANGED, ARM};

private:
	static string const mothertype;

};

#endif
