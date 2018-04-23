
#ifndef DEFINES_H
# define DEFINES_H

#include <iostream>
#include <iomanip>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define getline std::getline

typedef struct s_read
{
	string fname, lname;
	string nickname, login;
	string padress, email;
	string pnumber;
	string bday;
	string meal;
	string ucolor;
	string secret;
}				t_read;

#endif
