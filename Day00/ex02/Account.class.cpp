#include "Account.class.hpp"
#include <time.h>
#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

void	print_time(void)
{
	char timestr[20];
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(timestr, 20, "[%Y%m%d_%H%I%S] ", timeinfo);
	cout << timestr;
}

void	Account::makeDeposit( int deposit )
{
	print_time();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	cout << "deposit:"<<deposit<<";";
	cout << "amount:" << this->_amount << ";";
	cout << "nb_deposits:" << this->_nbDeposits << endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	print_time();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	if (this->_amount < withdrawal)
	{
		cout<<"withdrawal:refused"<<endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	cout << "withrdawal:"<<withdrawal<<";";
	cout << "amount:" << this->_amount << ";";
	cout << "_nbWithdrawals:" << this->_nbWithdrawals << endl;
	return true;
}

void	Account::displayAccountsInfos(void)
{
	print_time();
	cout << "accounts:" << Account::_nbAccounts << ";";
	cout << "total:" << Account::_totalAmount << ";";
	cout << "deposits:" << Account::_totalNbDeposits << ";";
	cout << "withdrawals:" << Account::_totalNbWithdrawals << endl;
}

int		Account::checkAmount( void ) const
{
	//this->numofcalls++;
	
	//add
	//mutable int		numofcalls;
	//to class vars

	//cout << this->numofcalls<<endl;
	//add 
	//std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::checkAmount ) );
	//to tests.cpp
	
	//return this->numofcalls;
	return 0;
}

void	Account::displayStatus(void) const
{
	print_time();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";";
	cout << "deposits:" << this->_nbDeposits << ";";
	cout << "withdrawals:" << this->_nbWithdrawals <<endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->numofcalls = 0;
	print_time();
	Account::_totalAmount += initial_deposit;
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";created" << endl;
}

Account::~Account(void)
{
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";closed" << endl;
}

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
