
#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>
#include <iomanip>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define getline std::getline

class Pony
{
public:
	Pony(string name, int type);
	~Pony(void);
	string getname(void) const;

private:
	string	name;
	int 	type;
};

#endif
