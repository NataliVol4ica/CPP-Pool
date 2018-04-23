#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include "defines.hpp"
#include <cmath>
class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &a);
	Fixed(int const a);
	Fixed(float const a);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed & operator=(Fixed const & inp);

	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int raw;
	static const int bits = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const &num);

#endif
