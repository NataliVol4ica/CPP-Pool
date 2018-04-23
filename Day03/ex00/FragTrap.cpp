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

FragTrap::FragTrap(void)
{
	*this = FragTrap("Unnamed FragTrap");
}

FragTrap::FragTrap(string name)
{
	this->name = name;
	this->hitPoints = FragTrap::defaults[HP].value;
	this->hitPoints_max = FragTrap::defaults[HPMAX].value;
	this->energyPoints = FragTrap::defaults[ENERP].value;
	this->energyPoints_max = FragTrap::defaults[EMERPMAX].value;
	this->level = FragTrap::defaults[LVL].value;
	this->meleeAttackDamage = FragTrap::defaults[MELEE].value;
	this->rangedAttackDamage = FragTrap::defaults[RANGED].value;
	this->armorDamageReduction = FragTrap::defaults[ARM].value;
	cout << this->type << " <"<<this->name<<"> was born!"<<endl;
}

FragTrap::FragTrap(FragTrap const &ref)
{
	*this = ref;
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

string	FragTrap::getName(void) const			{return this->name;}
int		FragTrap::getHP(void) const				{return this->hitPoints;}
int		FragTrap::getHPMAX(void) const			{return this->hitPoints_max;}
int		FragTrap::getENERP(void) const			{return this->energyPoints;}
int		FragTrap::getENERPMAX(void) const		{return this->energyPoints_max;}
int		FragTrap::getLVL(void) const 			{return this->level;}
int		FragTrap::getMELEE(void) const 			{return this->meleeAttackDamage;}
int		FragTrap::getRANGED(void) const 		{return this->rangedAttackDamage;}
int		FragTrap::getARM(void) const 			{return this->armorDamageReduction;}

void	FragTrap::setName(string const val) 	{this->name = val;}
void	FragTrap::setHP(int const val) 			{this->hitPoints = val;}
void	FragTrap::setHPMAX(int const val) 		{this->hitPoints_max = val;}
void	FragTrap::setENERP(int const val) 		{this->energyPoints = val;}
void	FragTrap::setENERPMAX(int const val) 	{this->energyPoints_max = val;}
void	FragTrap::setLVL(int const val) 		{this->level = val;}
void	FragTrap::setMELEE(int const val) 		{this->meleeAttackDamage = val;}
void	FragTrap::setRANGED(int const val) 		{this->rangedAttackDamage = val;}
void	FragTrap::setARM(int const val) 		{this->armorDamageReduction = val;}

/* ====== ATTACKS ====== */

int		FragTrap::rangedAttack(string const &target)
{
	cout << FragTrap::type << " <"<<this->name<<"> attacks <"<<target;
	cout <<"> at range, causing <"<<this->rangedAttackDamage<<"> points of damage!"<<endl;
	return this->rangedAttackDamage;
}

int		FragTrap::meleeAttack(string const &target)
{
	cout << FragTrap::type << " <"<<this->name<<"> attacks <"<<target;
	cout <<"> at melee, causing <"<<this->meleeAttackDamage<<"> points of damage!"<<endl;
	return this->meleeAttackDamage;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if ((unsigned int)this->armorDamageReduction >= amount)
	{
		cout << FragTrap::type << " <"<<this->name<<"> was under the attack and did not take any damage!"<<endl;
		return ;
	}
	this->hitPoints = this->hitPoints - (amount - this->armorDamageReduction);
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	cout << FragTrap::type << " <"<<this->name<<"> was under the attack and took <"<<amount - this->armorDamageReduction<<"> damage! Now he is <"<<this->hitPoints<<"> HP!"<<endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	if (this->hitPoints > this->hitPoints_max)
		this->hitPoints = this->hitPoints_max;
	cout << FragTrap::type  << " <"<<this->name<<"> healed for <"<<amount<<"> and now is <"<<this->hitPoints<<"> HP!"<<endl;
}

void	FragTrap::spendEnergy(unsigned int amount)
{
	this->energyPoints = max(this->energyPoints - amount, 0);
	cout << FragTrap::type << " <"<<this->name<<"> spent <"<<amount<<"> energy!"<<endl;
}

void	FragTrap::restoreEnergy(unsigned int amount)
{
	this->energyPoints = min(this->energyPoints + (int)amount, this->energyPoints_max);
	cout << FragTrap::type << " <"<<this->name<<"> spent <"<<amount<<"> energy!"<<endl;
}
//SL4P-SP
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

const string FragTrap::type = "FR4G-TP";

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
