#include "SuperTrap.hpp"
#include <time.h>

/* ====== CANONICAL ====== */

SuperTrap::SuperTrap(void) : ClapTrap(), NinjaTrap(), FragTrap()
{
	*this = SuperTrap("Unnamed SuperTrap");
	this->type = "SU4P-SP";
	born(this->type);
}

SuperTrap::SuperTrap(string name) : ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
	this->type = "SU4P-SP";
	this->hitPoints = SuperTrap::defaults[HP].value;
	this->hitPoints_max = SuperTrap::defaults[HPMAX].value;
	this->energyPoints = SuperTrap::defaults[ENERP].value;
	this->energyPoints_max = SuperTrap::defaults[EMERPMAX].value;
	this->level = SuperTrap::defaults[LVL].value;
	this->meleeAttackDamage = SuperTrap::defaults[MELEE].value;
	this->rangedAttackDamage = SuperTrap::defaults[RANGED].value;
	this->armorDamageReduction = SuperTrap::defaults[ARM].value;
	born(this->type);
}

SuperTrap::SuperTrap(SuperTrap const &ref)
{
	*this = ref;
	this->type = "SU4P-SP";
	born(this->type);
}

SuperTrap &SuperTrap::operator=(SuperTrap const &ref)
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

SuperTrap::~SuperTrap(void)
{
	cout << "R.I.P." << this->type << " <"<<this->name<<"> :("<<endl;
}

/* ====== GET SET ====== */

//are in parent class

/* ====== ATTACKS ====== */

/* ====== CONSTS ====== */

const t_data SuperTrap::defaults[] =
{
	{"Hit points", FragTrap::defaults[HP].value},
	{"Max hit points", FragTrap::defaults[HPMAX].value},
	{"Energy points", NinjaTrap::defaults[ENERP].value},
	{"Max energy points ", NinjaTrap::defaults[EMERPMAX].value},
	{"Level ", 1},
	{"Melee attack damage",  NinjaTrap::defaults[MELEE].value},
	{"Ranged attack damage", FragTrap::defaults[RANGED].value},
	{"Armor damage reduction", FragTrap::defaults[ARM].value}
};
