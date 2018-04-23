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

ScavTrap::ScavTrap(void)
{
	*this = ScavTrap("Unnamed ScavTrap");
}

ScavTrap::ScavTrap(string name)
{
	this->name = name;
	this->hitPoints = ScavTrap::defaults[HP].value;
	this->hitPoints_max = ScavTrap::defaults[HPMAX].value;
	this->energyPoints = ScavTrap::defaults[ENERP].value;
	this->energyPoints_max = ScavTrap::defaults[EMERPMAX].value;
	this->level = ScavTrap::defaults[LVL].value;
	this->meleeAttackDamage = ScavTrap::defaults[MELEE].value;
	this->rangedAttackDamage = ScavTrap::defaults[RANGED].value;
	this->armorDamageReduction = ScavTrap::defaults[ARM].value;
	cout << this->type << " <"<<this->name<<"> was born!"<<endl;
}

ScavTrap::ScavTrap(ScavTrap const &ref)
{
	*this = ref;
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

string	ScavTrap::getName(void) const			{return this->name;}
int		ScavTrap::getHP(void) const				{return this->hitPoints;}
int		ScavTrap::getHPMAX(void) const			{return this->hitPoints_max;}
int		ScavTrap::getENERP(void) const			{return this->energyPoints;}
int		ScavTrap::getENERPMAX(void) const		{return this->energyPoints_max;}
int		ScavTrap::getLVL(void) const 			{return this->level;}
int		ScavTrap::getMELEE(void) const 			{return this->meleeAttackDamage;}
int		ScavTrap::getRANGED(void) const 		{return this->rangedAttackDamage;}
int		ScavTrap::getARM(void) const 			{return this->armorDamageReduction;}

void	ScavTrap::setName(string const val) 	{this->name = val;}
void	ScavTrap::setHP(int const val) 			{this->hitPoints = val;}
void	ScavTrap::setHPMAX(int const val) 		{this->hitPoints_max = val;}
void	ScavTrap::setENERP(int const val) 		{this->energyPoints = val;}
void	ScavTrap::setENERPMAX(int const val) 	{this->energyPoints_max = val;}
void	ScavTrap::setLVL(int const val) 		{this->level = val;}
void	ScavTrap::setMELEE(int const val) 		{this->meleeAttackDamage = val;}
void	ScavTrap::setRANGED(int const val) 		{this->rangedAttackDamage = val;}
void	ScavTrap::setARM(int const val) 		{this->armorDamageReduction = val;}

/* ====== ATTACKS ====== */

int		ScavTrap::rangedAttack(string const &target)
{
	cout << ScavTrap::type << " <"<<this->name<<"> attacks <"<<target;
	cout <<"> at range, causing <"<<this->rangedAttackDamage<<"> points of damage!"<<endl;
	return this->rangedAttackDamage;
}

int		ScavTrap::meleeAttack(string const &target)
{
	cout << ScavTrap::type << " <"<<this->name<<"> attacks <"<<target;
	cout <<"> at melee, causing <"<<this->meleeAttackDamage<<"> points of damage!"<<endl;
	return this->meleeAttackDamage;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if ((unsigned int)this->armorDamageReduction >= amount)
	{
		cout << ScavTrap::type << " <"<<this->name<<"> was under the attack and did not take any damage!"<<endl;
		return ;
	}
	this->hitPoints = this->hitPoints - (amount - this->armorDamageReduction);
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	cout << ScavTrap::type << " <"<<this->name<<"> was under the attack and took <"<<amount - this->armorDamageReduction<<"> damage! Now he is <"<<this->hitPoints<<"> HP!"<<endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	if (this->hitPoints > this->hitPoints_max)
		this->hitPoints = this->hitPoints_max;
	cout << ScavTrap::type  << " <"<<this->name<<"> healed for <"<<amount<<"> and now is <"<<this->hitPoints<<"> HP!"<<endl;
}

void	ScavTrap::spendEnergy(unsigned int amount)
{
	this->energyPoints = max(this->energyPoints - amount, 0);
	cout << ScavTrap::type << " <"<<this->name<<"> spent <"<<amount<<"> energy!"<<endl;
}

void	ScavTrap::restoreEnergy(unsigned int amount)
{
	this->energyPoints = min(this->energyPoints + (int)amount, this->energyPoints_max);
	cout << ScavTrap::type << " <"<<this->name<<"> spent <"<<amount<<"> energy!"<<endl;
}

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

const string ScavTrap::type = "SL4P-SP";

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
