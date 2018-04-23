#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "defines.hpp"

//;

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(string name);
	FragTrap(FragTrap const &ref);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &ref); 

int		rangedAttack(string const &target);
int		meleeAttack(string const &target);

/* OTHER FUNCS */
	int		att2(string const &target);
	int		att3(string const &target);
	int		att4(string const &target);

	int		vaulthunter_dot_exe(string const &target);

	typedef int	(FragTrap::*func)(string const &);
	static func attacks[];
	static const t_data defaults[];
};

#endif
