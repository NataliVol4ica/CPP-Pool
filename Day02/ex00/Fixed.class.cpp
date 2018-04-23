#include "Fixed.class.hpp"

Fixed::Fixed(void)
{
	this->raw = 0;
	cout << "Default constructor called"<<endl;
}

Fixed::Fixed(Fixed const &a)
{
	this->raw = a.getRawBits();
	cout <<"Copy constructor called"<<endl;
}

int		Fixed::getRawBits(void) const
{
	cout << "getRawBits called"<<endl;
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
