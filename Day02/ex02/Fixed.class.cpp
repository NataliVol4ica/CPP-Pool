#include "Fixed.class.hpp"

/* ====================== MAIN ====================== */
Fixed::Fixed(void)
{
	this->raw = 0;
}

Fixed::Fixed(Fixed const &a)
{
	*this = a;
}

Fixed::Fixed(int const a)
{
	this->raw = a * (1 << this->bits);
}

Fixed::Fixed(float const a)
{
	this->raw = roundf(a * (1 << this->bits));
}

int		Fixed::getRawBits(void) const
{
	return (this->raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}
Fixed::~Fixed(void) {}

/* ====================== OTHER ====================== */

float	Fixed::toFloat(void) const
{
	return (float(this->raw) / (1 << this->bits));
}

int		Fixed::toInt(void) const
{
	return (this->raw / (1 << this->bits));
}

/* ====================== UNARY OPERATORS ====================== */

Fixed &Fixed::operator=(Fixed const & inp)
{
	this->raw = inp.raw;
	return *this;
}

Fixed &Fixed::operator+=(Fixed const & inp)
{
	this->raw += inp.raw;
	return *this;
}

Fixed &Fixed::operator-=(Fixed const & inp)
{
	this->raw -= inp.raw;
	return *this;
}

Fixed &Fixed::operator*=(Fixed const & inp)
{
	this->raw *= inp.raw;
	return *this;
}

Fixed &Fixed::operator/=(Fixed const & inp)
{
	this->raw /= inp.raw;
	return *this;
}

/* ====================== BINATY OPERATORS ====================== */

Fixed	Fixed::operator+(Fixed const & inp) const
{
	return (Fixed(this->toFloat() + inp.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & inp) const
{
	return (Fixed(this->toFloat() - inp.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & inp) const
{
	return (Fixed(this->toFloat() * inp.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & inp) const
{
	return (Fixed(this->toFloat() / inp.toFloat()));
}

bool	Fixed::operator>(Fixed const & inp) const
{
	if (this->raw > inp.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const & inp) const
{
	if (this->raw < inp.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const & inp) const
{
	if (this->raw >= inp.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const & inp) const
{
	if (this->raw <= inp.getRawBits())
		return true;
	return false;
}

/* ====================== INCREMENTORS  ====================== */

Fixed &Fixed::operator++(void)
{
	this->raw++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->raw--;
	return *this;
}

Fixed &Fixed::operator++(int)
{
	Fixed *ret = new Fixed(*this);
	this->raw++;
	return *ret;
}

Fixed &Fixed::operator--(int)
{
	Fixed *ret = new Fixed(*this);
	this->raw--;
	return *ret;
}

/* ====================== MIN MAX  ====================== */

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

/* ====================== WHATEVER ====================== */

std::ostream & operator<<(std::ostream &o, Fixed const &num)
{
	o << num.toFloat();
	return o;
}
