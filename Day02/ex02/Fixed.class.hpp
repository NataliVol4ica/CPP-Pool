#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include "defines.hpp"
#include <cmath>
class Fixed
{
public:

/* Constructors */
	Fixed(void);
	Fixed(Fixed const &a);
	Fixed(int const a);
	Fixed(float const a);
	~Fixed(void);

/* GetSet */
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

/* Unary Operators */
	Fixed  &operator=(Fixed const & inp);
	Fixed  &operator+=(Fixed const & inp);
	Fixed  &operator-=(Fixed const & inp);
	Fixed  &operator*=(Fixed const & inp);
	Fixed  &operator/=(Fixed const & inp);

/* Binary Operators */
	Fixed	operator+(Fixed const & inp) const;
	Fixed	operator-(Fixed const & inp) const;
	Fixed	operator*(Fixed const & inp) const;
	Fixed	operator/(Fixed const & inp) const;
	
	bool	operator>(Fixed const & inp) const;
	bool	operator<(Fixed const & inp) const;
	bool	operator>=(Fixed const & inp) const;
	bool	operator<=(Fixed const & inp) const;

/* Incrementors*/
	Fixed	&operator++(void);
	Fixed	&operator++(int);
	Fixed	&operator--(void);
	Fixed	&operator--(int);

/* Converters */
	float	toFloat(void) const;
	int		toInt(void) const;

/* Custom */
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static Fixed const	&min(Fixed const &a, Fixed const &b);
	static Fixed const	&max(Fixed const &a, Fixed const &b);

private:
	int 	raw;
	static const int bits = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const &num);

#endif
