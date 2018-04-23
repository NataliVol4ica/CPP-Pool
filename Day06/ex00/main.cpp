
#include <iostream>
#include <climits>
#include <ctype.h>
#include <math.h>
#include <limits>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define getline std::getline
#define exception std::exception

#define T_CHAR 1
#define T_INT 2
#define T_FLOAT 3
#define T_DOUBLE 4

/* ============== INPUT RECOGNITION ============== */

bool	is_char(string s)
{
	if (s.length() != 1)
		return false;
	if (s[0] >= 'a' && s[0] <= 'z')
		return true;
	if (s[0] >= 'A' && s[0] <= 'Z')
		return true;
	return false;
}

bool	is_integer(string s)
{
	size_t i;
	size_t start;

	start = s[0] == '-' ? 1 : 0;
	for (i = start; i < s.length(); i++)
		if (!isdigit(s[i]))
			break;
	if (i != s.length())
		return false;
	return true;
}

bool	is_float(string s)
{
	size_t i;
	size_t start;

	if (s == "-inff" || s == "+inff" || s == "nanf")
		return true;
	start = s[0] == '-' ? 1 : 0;
	for (i = start; i < s.length(); i++)
		if (!isdigit(s[i]))
			break;
	if (s[i] != '.')
		return false;
	start = i + 1;
	for (i = start; i < s.length(); i++)
		if (!isdigit(s[i]))
			break;
	if (s[i] != 'f')
		return false;
	i++;
	if (i != s.length())
		return false;
	return true;
}

bool	is_double(string s)
{
	size_t i;
	size_t start;

	if (s == "-inf" || s == "+inf" || s == "nan")
		return true;
	start = s[0] == '-' ? 1 : 0;
	for (i = start; i < s.length(); i++)
		if (!isdigit(s[i]))
			break;
	if (s[i] != '.')
		return false;
	start = i + 1;
	for (i = start; i < s.length(); i++)
		if (!isdigit(s[i]))
			break;
	if (i != s.length())
		return false;
	return true;
}

int		recognize_input(string s)
{
	if (is_char(s))
		return T_CHAR;
	if (is_integer(s))
		return T_INT;
	if (is_float(s))
		return T_FLOAT;
	if (is_double(s))
		return T_DOUBLE;
	return 0;
}

/* ============== SMALL PRINTERS ============== */

void	print_char(char c)
{
	if (isprint(c))
		cout << c<< endl;
	else
		cout <<"Non displayable"<<endl;
}

void	print_float(float f)
{
	float temp;
	float frac = modf(f, &temp);
	if (isinf(f) && f > 0.0f) cout<<"+";
	cout<<f;
	if (frac == 0.0f && !isinf(f))
		cout<<".0";
	cout<<"f"<<endl;

}

void	print_double(double d)
{
	double temp;
	double frac = modf(d, &temp);
	if (isinf(d) && d > 0.0f) cout<<"+";
	cout<<d;
	if (frac == 0.0f && !isinf(d))
		cout<<".0";
	cout<<endl;
}

/* ============== MANDATORY PARSERS ============== */

void	parse_char(string str)
{
	char c = static_cast<char>(str[0]);
	cout <<"char: "<<c<<endl;
	int i = static_cast<int>(c);
	cout <<"int: "<<i<<endl;
	float f = static_cast<float>(c);
	cout <<"float: ";
	print_float(f);
	double d = static_cast<double>(c);
	cout<<"double: ";
	print_double(d);
}

void	parse_int(string str)
{
	int i = std::stoi(str);
	cout<<"char: ";
	if (i > static_cast<int>(CHAR_MAX) || i < static_cast<int>(CHAR_MIN))
		cout<<"impossible"<<endl;
	else
		print_char(static_cast<char>(i));
	cout <<"int "<<i<<endl;
	float f = static_cast<float>(i);
	cout << "float :";
	print_float(f);
	double d = static_cast<double>(i);
	cout<<"double: ";
	print_double(d);
}

void	parse_float(string str)
{
	float f = std::stof(str);
	cout<<"char: ";
	if (f > static_cast<float>(CHAR_MAX) || f < static_cast<float>(CHAR_MIN) || isnan(f))
		cout<<"impossible"<<endl;
	else
		print_char(static_cast<char>(f));
	cout <<"int: ";
	if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN) || isnan(f))
		cout<<"impossible"<<endl;
	else
	{
		int i = static_cast<int>(f);
		cout<<i<<endl;
	}
	cout <<"float: ";
	print_float(f);
	double d = static_cast<double>(f);
	cout<<"double: ";
	print_double(d);
}

void	parse_double(string str)
{
	double d = std::stod(str);
	cout<<"char: ";
	if (d > static_cast<double>(CHAR_MAX) || d < static_cast<double>(CHAR_MIN) || isnan(d))
		cout<<"impossible"<<endl;
	else
		print_char(static_cast<char>(d));
	cout <<"int: ";
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN) || isnan(d))
		cout<<"impossible"<<endl;
	else
	{
		int i = static_cast<int>(d);
		cout<<i<<endl;
	}
	cout <<"float: ";
	if ((d > 0 && d > static_cast<double>(std::numeric_limits<float>::max())) ||
		(d < 0 && -d > static_cast<double>(std::numeric_limits<float>::max())))
		cout<<"impossible "<<endl;
	else
	{
		float f = static_cast<float>(d);
		print_float(f);
	}
	cout<<"double: ";
	print_double(d);
}

/* ============== MAIN ============== */

int		main(int ac, char **av)
{
	int type;
	string str;

	if (ac != 2)
	{
		cout << "Usage: /convert [expression]"<<endl;
		return 0;
	}
	//cout<<"float max "<<std::numeric_limits<float>::max()<<endl;
	str = static_cast<string>(av[1]);
	type = recognize_input(str);
	switch(type)
	{
		case T_CHAR:
			parse_char(str);
			break;
		case T_INT:
			parse_int(str);
			break;
		case T_FLOAT:
			parse_float(str);
			break;
		case T_DOUBLE:
			parse_double(str);
			break;
		default:
			cout <<"Undefined input type."<<endl;
	}
	return 0;
}
