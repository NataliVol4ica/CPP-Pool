#include "Fixed.class.hpp"

#include <iostream>
#include "defines.hpp"

int		main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << b << endl;
	cout << Fixed::max( a, b ) << endl;
	//system ("leaks a.out");
	return 0;
}