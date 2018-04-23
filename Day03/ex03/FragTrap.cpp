#include "FragTrap.hpp"
#include <time.h>

FragTrap::func	FragTrap::attacks[] = 
{
	&FragTrap::meleeAttack,
	&FragTrap::rangedAttack,
	&FragTrap::att2,
	&FragTrap::att3,
	&FragTrap::att4
};

/* ====== CANONICAL ====== */

FragTrap::FragTrap(void) : ClapTrap()
{
	*this = FragTrap("Unnamed FragTrap");
	this->type = "FR4G-TP";
	born(this->type);
}

FragTrap::FragTrap(string name) : ClapTrap(name)
{
	this->type = "FR4G-TP";
	this->hitPoints = FragTrap::defaults[HP].value;
	this->hitPoints_max = FragTrap::defaults[HPMAX].value;
	this->energyPoints = FragTrap::defaults[ENERP].value;
	this->energyPoints_max = FragTrap::defaults[EMERPMAX].value;
	this->level = FragTrap::defaults[LVL].value;
	this->meleeAttackDamage = FragTrap::defaults[MELEE].value;
	this->rangedAttackDamage = FragTrap::defaults[RANGED].value;
	this->armorDamageReduction = FragTrap::defaults[ARM].value;
	born(this->type);
}

FragTrap::FragTrap(FragTrap const &ref)
{
	*this = ref;
	this->type = "FR4G-TP";
	born(this->type);
}

FragTrap &FragTrap::operator=(FragTrap const &ref)
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

FragTrap::~FragTrap(void)
{
	cout << "R.I.P." << this->type << " <"<<this->name<<"> :("<<endl;
}

/* ====== GET SET ====== */

//are in parent class

/* ====== ATTACKS ====== */

int		FragTrap::att2(string const &target)
{
	cout << FragTrap::type << " <"<<this->name<<"> funnycomment2 attacked target <"<<target<<">!"<<endl;
	return 0;
}

int		FragTrap::att3(string const &target)
{
	cout << FragTrap::type << " <"<<this->name<<"> funnycomment3 attacked target <"<<target<<">!"<<endl;
	return 0;
}

int		FragTrap::att4(string const &target)
{
	cout << FragTrap::type << " <"<<this->name<<"> funnycomment4 attacked target <"<<target<<">!"<<endl;
	return 0;
}

int		FragTrap::vaulthunter_dot_exe(string const &target)
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

const t_data FragTrap::defaults[] =
{
	{"Hit points", 100},
	{"Max hit points", 100},
	{"Energy points", 100},
	{"Max energy points ", 100},
	{"Level ", 1},
	{"Melee attack damage", 30},
	{"Ranged attack damage", 20},
	{"Armor damage reduction", 5}
};
