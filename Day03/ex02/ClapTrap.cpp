#include "ClapTrap.hpp"
#include <time.h>

/* ====== CANONICAL ====== */

void	ClapTrap::born(const string &type) const
{
	cout << type << " <"<<this->name<<"> was born!"<<endl;
}

ClapTrap::ClapTrap(void) 
{
	this->name = ("Unnamed ClapTrap");
	this->born(this->mothertype);
}

ClapTrap::ClapTrap(string const &name)
{
	this->name = name;
	this->born(this->mothertype);
}

ClapTrap::~ClapTrap(void)
{
	cout << "R.I.P." << ClapTrap::mothertype << " <"<<this->name<<"> :("<<endl;
}

/* ====== GET SET ====== */

string	ClapTrap::getName(void) const			{return this->name;}
int		ClapTrap::getHP(void) const				{return this->hitPoints;}
int		ClapTrap::getHPMAX(void) const			{return this->hitPoints_max;}
int		ClapTrap::getENERP(void) const			{return this->energyPoints;}
int		ClapTrap::getENERPMAX(void) const		{return this->energyPoints_max;}
int		ClapTrap::getLVL(void) const 			{return this->level;}
int		ClapTrap::getMELEE(void) const 			{return this->meleeAttackDamage;}
int		ClapTrap::getRANGED(void) const 		{return this->rangedAttackDamage;}
int		ClapTrap::getARM(void) const 			{return this->armorDamageReduction;}

void	ClapTrap::setName(string const val) 	{this->name = val;}
void	ClapTrap::setHP(int const val) 			{this->hitPoints = val;}
void	ClapTrap::setHPMAX(int const val) 		{this->hitPoints_max = val;}
void	ClapTrap::setENERP(int const val) 		{this->energyPoints = val;}
void	ClapTrap::setENERPMAX(int const val) 	{this->energyPoints_max = val;}
void	ClapTrap::setLVL(int const val) 		{this->level = val;}
void	ClapTrap::setMELEE(int const val) 		{this->meleeAttackDamage = val;}
void	ClapTrap::setRANGED(int const val) 		{this->rangedAttackDamage = val;}
void	ClapTrap::setARM(int const val) 		{this->armorDamageReduction = val;}

/* ====== ATTACKS ====== */

int		ClapTrap::rangedAttack(string const &target)
{
	cout << this->type << " <"<<this->name<<"> attacks <"<<target;
	cout <<"> at range, causing <"<<this->rangedAttackDamage<<"> points of damage!"<<endl;
	return this->rangedAttackDamage;
}

int		ClapTrap::meleeAttack(string const &target)
{
	cout << this->type << " <"<<this->name<<"> attacks <"<<target;
	cout <<"> at melee, causing <"<<this->meleeAttackDamage<<"> points of damage!"<<endl;
	return this->meleeAttackDamage;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((unsigned int)this->armorDamageReduction >= amount)
	{
		cout << this->type << " <"<<this->name<<"> was under the attack and did not take any damage!"<<endl;
		return ;
	}
	this->hitPoints = this->hitPoints - (amount - this->armorDamageReduction);
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	cout << this->type << " <"<<this->name<<"> was under the attack and took <"<<amount - this->armorDamageReduction<<"> damage! Now he is <"<<this->hitPoints<<"> HP!"<<endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	if (this->hitPoints > this->hitPoints_max)
		this->hitPoints = this->hitPoints_max;
	cout << this->type  << " <"<<this->name<<"> healed for <"<<amount<<"> and now is <"<<this->hitPoints<<"> HP!"<<endl;
}

void	ClapTrap::spendEnergy(unsigned int amount)
{
	this->energyPoints = max(this->energyPoints - amount, 0);
	cout << this->type << " <"<<this->name<<"> spent <"<<amount<<"> energy!"<<endl;
}

void	ClapTrap::restoreEnergy(unsigned int amount)
{
	this->energyPoints = min(this->energyPoints + (int)amount, this->energyPoints_max);
	cout << this->type << " <"<<this->name<<"> spent <"<<amount<<"> energy!"<<endl;
}

/* ====== CONSTS ====== */

const string ClapTrap::mothertype = "CL4P-TP";

