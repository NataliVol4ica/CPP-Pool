#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include "defines.hpp"

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &a);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed & operator=(Fixed const & inp);

private:
	int raw;
	static const int bits = 8;
};

#endif
