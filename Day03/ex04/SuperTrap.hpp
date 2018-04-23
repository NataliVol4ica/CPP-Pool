#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "ClapTrap.hpp"
#include "defines.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap(void);
	SuperTrap(string name);
	SuperTrap(SuperTrap const &ref);
	~SuperTrap(void);

	SuperTrap &operator=(SuperTrap const &ref); 

/* OTHER FUNCS */

private:
	static const t_data defaults[];
};

#endif
