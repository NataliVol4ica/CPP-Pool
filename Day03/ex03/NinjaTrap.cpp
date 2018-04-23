#include "NinjaTrap.hpp"
#include <time.h>

/* ====== CANONICAL ====== */

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	*this = NinjaTrap("Unnamed NinjaTrap");
	this->type = "NJ4P-SP";
	born(this->type);
}

NinjaTrap::NinjaTrap(string name) : ClapTrap(name)
{
	this->type = "NJ4P-SP";
	this->hitPoints = NinjaTrap::defaults[HP].value;
	this->hitPoints_max = NinjaTrap::defaults[HPMAX].value;
	this->energyPoints = NinjaTrap::defaults[ENERP].value;
	this->energyPoints_max = NinjaTrap::defaults[EMERPMAX].value;
	this->level = NinjaTrap::defaults[LVL].value;
	this->meleeAttackDamage = NinjaTrap::defaults[MELEE].value;
	this->rangedAttackDamage = NinjaTrap::defaults[RANGED].value;
	this->armorDamageReduction = NinjaTrap::defaults[ARM].value;
	born(this->type);
}

NinjaTrap::NinjaTrap(NinjaTrap const &ref)
{
	*this = ref;
	this->type = "NJ4P-SP";
	born(this->type);
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &ref)
{
	this->name = ref.getName();
	this->hitPoints = ref.getHP();
	this->hitPoints_max = ref.getHPMAX();
	this->energyPoints = ref.getENERP();
	this->energyPoints_max = ref.getENERPMAX();
	this->level = ref.getLVL();
	this->meleeAttackDamage = ref.getMELEE();
	this->rangedAttackDamage = ref.getRANGED();
	this->armorDamageReduction = ref.getARM();
	return *this;
}

NinjaTrap::~NinjaTrap(void)
{
	cout << "R.I.P." << this->type << " <"<<this->name<<"> :("<<endl;
}

/* ====== GET SET ====== */

//are in parent class

/* ====== ATTACKS ====== */

int		NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	if (this->energyPoints < 25)
	{
		cout <<this->type<<" <"<<this->name<<"> is missing energy for super attack!"<<endl;
		return 0;
	}
	cout << NinjaTrap::type << " <"<<this->name<<"> is going to kill <"<<target.getName()<<">!"<<endl;
	target.takeDamage(10000);
	return 0;
}

int		NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	if (this->energyPoints < 25)
	{
		cout <<this->type<<" <"<<this->name<<"> is missing energy for super attack!"<<endl;
		return 0;
	}
	cout << NinjaTrap::type << " <"<<this->name<<"> is going to kill <"<<target.getName()<<">!"<<endl;
	target.takeDamage(10000);
	return 0;
}

int		NinjaTrap::ninjaShoebox(FragTrap &target)
{
	if (this->energyPoints < 25)
	{
		cout <<this->type<<" <"<<this->name<<"> is missing energy for super attack!"<<endl;
		return 0;
	}
	cout << NinjaTrap::type << " <"<<this->name<<"> is going to kill <"<<target.getName()<<">!"<<endl;
	target.takeDamage(10000);
	return 0;
}

/* ====== CONSTS ====== */

const t_data NinjaTrap::defaults[] =
{
	{"Hit points", 60},
	{"Max hit points", 60},
	{"Energy points", 120},
	{"Max energy points ", 120},
	{"Level ", 1},
	{"Melee attack damage", 60},
	{"Ranged attack damage", 5},
	{"Armor damage reduction", 0}
};
