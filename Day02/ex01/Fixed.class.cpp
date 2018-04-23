#include "Fixed.class.hpp"

Fixed::Fixed(void)
{
	this->raw = 0;
	cout << "Default constructor called"<<endl;
}

Fixed::Fixed(Fixed const &a)
{
	cout <<"Copy constructor called"<<endl;
	*this = a;
}

Fixed::Fixed(int const a)
{
	this->raw = a * (1 << this->bits);
	cout <<"Int constructor called"<<endl;
}

Fixed::Fixed(float const a)
{
	this->raw = roundf(a * (1 << this->bits));
	cout <<"Float constructor called"<<endl;
}

int		Fixed::getRawBits(void) const
{
	//cout << "getRawBits called"<<endl;
	return (this->raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

Fixed & Fixed::operator=(Fixed const & inp)
{
	cout<<"Assignation operator called"<<endl;
	this->raw = inp.raw;
	return *this;
}

Fixed::~Fixed(void)
{
	cout <<"Destructor called"<<endl;
}


float	Fixed::toFloat(void) const
{
	return (float(this->raw) / (1 << this->bits));
}

int		Fixed::toInt(void) const
{
	return (this->raw / (1 << this->bits));
}

std::ostream & operator<<(std::ostream &o, Fixed const &num)
{
	o << num.toFloat();
	return o;
}
