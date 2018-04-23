#include "ScavTrap.hpp"
#include <time.h>

ScavTrap::func	ScavTrap::attacks[] = 
{
	&ScavTrap::meleeAttack,
	&ScavTrap::rangedAttack,
	&ScavTrap::chal2,
	&ScavTrap::chal3,
	&ScavTrap::chal4
};

/* ====== CANONICAL ====== */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	*this = ScavTrap("Unnamed ScavTrap");
	this->type = "SL4P-SP";
	born(this->type);
}

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
	this->type = "SL4P-SP";
	this->hitPoints = ScavTrap::defaults[HP].value;
	this->hitPoints_max = ScavTrap::defaults[HPMAX].value;
	this->energyPoints = ScavTrap::defaults[ENERP].value;
	this->energyPoints_max = ScavTrap::defaults[EMERPMAX].value;
	this->level = ScavTrap::defaults[LVL].value;
	this->meleeAttackDamage = ScavTrap::defaults[MELEE].value;
	this->rangedAttackDamage = ScavTrap::defaults[RANGED].value;
	this->armorDamageReduction = ScavTrap::defaults[ARM].value;
	born(this->type);
}

ScavTrap::ScavTrap(ScavTrap const &ref)
{
	*this = ref;
	this->type = "SL4P-SP";
	born(this->type);
}

ScavTrap &ScavTrap::operator=(ScavTrap const &ref)
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

ScavTrap::~ScavTrap(void)
{
	cout << "R.I.P." << this->type << " <"<<this->name<<"> :("<<endl;
}

/* ====== GET SET ====== */

//are in parent class

/* ====== ATTACKS ====== */

int		ScavTrap::chal2(string const &target)
{
	cout << ScavTrap::type << " <"<<this->name<<"> funnychallenged2 target <"<<target<<">!"<<endl;
	return 0;
}

int		ScavTrap::chal3(string const &target)
{
	cout << ScavTrap::type << " <"<<this->name<<"> funnychallenged3 target <"<<target<<">!"<<endl;
	return 0;
}

int		ScavTrap::chal4(string const &target)
{
	cout << ScavTrap::type << " <"<<this->name<<"> funnychallenged4 target <"<<target<<">!"<<endl;
	return 0;
}

int		ScavTrap::challengeNewcomer(string const &target)
{
	int	index;

	if (this->energyPoints < 25)
	{
		cout <<this->type<<" <"<<this->name<<"> is missing energy for rand attack!"<<endl;
		return 0;
	}
	srand(time(NULL));
	index = arc4random_uniform(5);
	cout << "Randomly chose attack #"<<index<<endl;
	this->spendEnergy(25);
	return (this->*attacks[index])(target);
}


/* ====== CONSTS ====== */

const t_data ScavTrap::defaults[] =
{
	{"Hit points", 100},
	{"Max hit points", 100},
	{"Energy points", 50},
	{"Max energy points ", 50},
	{"Level ", 1},
	{"Melee attack damage", 20},
	{"Ranged attack damage", 15},
	{"Armor damage reduction", 3}
};
