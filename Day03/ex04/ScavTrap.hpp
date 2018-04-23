#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "defines.hpp"

//;

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(string name);
	ScavTrap(ScavTrap const &ref);
	~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &ref); 

/* OTHER FUNCS */
	int		chal2(string const &target);
	int		chal3(string const &target);
	int		chal4(string const &target);

	int		challengeNewcomer(string const &target);

private:
	typedef int	(ScavTrap::*func)(string const &);
	
	static func attacks[];
	static const t_data defaults[];
};

#endif
