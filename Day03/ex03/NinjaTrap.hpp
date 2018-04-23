#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "defines.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(string name);
	NinjaTrap(NinjaTrap const &ref);
	~NinjaTrap(void);

	NinjaTrap &operator=(NinjaTrap const &ref); 

/* OTHER FUNCS */

	int		ninjaShoebox(NinjaTrap &target);
	int		ninjaShoebox(ScavTrap &target);
	int		ninjaShoebox(FragTrap &target);

private:
	static const t_data defaults[];
};

#endif
