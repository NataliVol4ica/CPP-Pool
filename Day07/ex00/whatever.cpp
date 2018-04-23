#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define exception std::exception

template <typename T>

T	const	&max(T const &x, T const &y)
{
	return x >= y ? x : y;
}
template <typename T>

T	const	&min(T const &x, T const &y)
{
	return x <= y ? x : y;
}
template <typename T>

void	swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

int		main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	cout << "a = " << a << ", b = " << b << endl;
	cout << "min( a, b ) = " << ::min( a, b ) << endl;
	cout << "max( a, b ) = " << ::max( a, b ) << endl;
	string c = "chaine1";
	string d = "chaine2";
	::swap(c, d);
	cout << "c = " << c << ", d = " << d << endl;
	cout << "min( c, d ) = " << ::min( c, d ) << endl;
	cout << "max( c, d ) = " << ::max( c, d ) << endl;
	return 0;
}
