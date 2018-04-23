#include "Fixed.class.hpp"

#include <iostream>
#include "defines.hpp"
#include <string>
#include <ctype.h>

void	inv_expr(void)
{
	cout << "Invalid expression"<<endl;
	exit (0);
}

int		count_ops(string str, char o1, char o2)
{
	int	ans = 0;
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == o1 || str[i] == o2)
			ans++;
	return ans;
}

size_t	count_right(string str, size_t i)
{
	size_t	r = i + 1;
	if (str[r] == '-' && str[r + 1] >= '0' && str[r + 1] <= '9')
		r++;
	while (r < str.length() && str[r] >= '0' && str[r] <= '9')
		r++;
	if (r != i + 1 && str[r] == '.')
	{
		r++;
		while (r < str.length() && str[r] >= '0' && str[r] <= '9')
			r++;
	}
	if (r == i + 1 && !(str[r] >= '0' && str[r] <= '9')) //if no digit met
		inv_expr();
	return r;
}

size_t	count_left(string str, size_t i)
{
	size_t	l = i - 1;
	while (l > 0 && str[l] >= '0' && str[l] <= '9')
		l--;
	if (l != i - 1 && str[l] == '.')
	{
		l--;
		while (l > 0 && str[l] >= '0' && str[l] <= '9')
			l--;
	}
	if (l == i - 1 && !(str[l] >= '0' && str[l] <= '9')) //if no digit met
		inv_expr();
	return l;
}

Fixed	do_op(Fixed &left, Fixed &right, char op)
{
	Fixed fans;
	switch(op){
		case '+':
		{
			fans = left + right;
			break;
		}
		case '-':
		{
			fans = left - right;
			break;
		}
		case '*':
		{
			fans = left * right;
			break;
		}
		case '/':
		{
			if (right == Fixed(0))
				inv_expr();
			fans = left / right;
			break;
		}
	}
	return fans;
}

string	eval_ops(string str, char o1, char o2)
{
	size_t	i;
	size_t	l, r;
	string	temp;
	string	s1, s2, s3;
	float	f1, f2;
	int		start;
	Fixed	fixed_ans;
	float 	float_ans;
	Fixed 	left, right;

	while (count_ops(str, o1, o2))
	{
		if (str[0] == '-' && o2 == '-' && count_ops(str, o1, o2) == 1)
			return str;	//check if it is just a <0 number
		start = str[0] == '-' ? 1 : 0;
		for (i = start; i < str.length(); i++)
			if (str[i] == o1 || str[i] == o2)
				break;
		//cout <<"found "<<str[i] <<" at "<<i<<endl;
		//RIGHT
		r = count_right(str, i);
		temp = str.substr(i + 1, str.length());
		f2 = std::stof(temp);
		s3 = str.substr(r, str.length());
		//LEFT
		l = count_left(str, i);
		//temp = str.substr(l, str.length());
		//cout << "first version of left str is "<<temp<<endl;
		if (str[l] == '-' && !(l > 0 && isdigit(str[l - 1])))
			l--;
		if (!(l == 0 && isdigit(str[l])))
			l++;
		temp = str.substr(l, str.length());
		//cout << "left str is "<<temp<<endl;
		f1 = std::stof(temp);
		s1 = str.substr(0, l);
		//DO OP
		left =  Fixed(f1);
		right = Fixed(f2);
		fixed_ans = do_op(left, right, str[i]);
		//result saving
		float_ans = fixed_ans.toFloat();
		s2 = std::to_string(float_ans);
		str = s1 + s2 + s3;
	}
	return str;
}

string	eval_str(string str)
{
	str = eval_ops(str, '*', '/');
	str = eval_ops(str, '+', '-');
	return str;
}

int		count_bracket_pairs(string str)
{
	int total = 0, closing = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			total++;
			continue;
		}
		if (str[i] != ')')
			continue;
		total--;
		closing++;
		if (total < 0)
			return -1;
	}
	if (total != 0)
		return -1;
	return closing;
}

void	check_trash(string str)
{
	int i = 0;
	if (str[0] == '-')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		i++;
		while (isdigit(str[i]))
			i++;
		if ((size_t)i != str.length())
			inv_expr();
	}
}

string	remove_tabs(char *av)
{
	string str = av;

	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\v'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\f'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
	return str;
}

void	algo(int ac, char **av)
{
	int		pairs;
	string 	str;
	string 	s1, s2, s3;
	int		prev;
	size_t	i;

	if (ac != 2)
	{
		cout << "Invalid number of arguments."<<endl;
		exit (0);
	}
	str = remove_tabs(av[1]);
	pairs = count_bracket_pairs(str);
	if (pairs < 0)
	{
		cout << "invalid brackets"<<endl;
		exit (0);
	}
	while (pairs)
	{
		pairs--;
		for (i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
				prev = i;
			else if (str[i] == ')')
				break;
		}
		s1 = str.substr(0, prev);
		s2 = str.substr(prev + 1, i - prev - 1);
		s3 = str.substr(i + 1, str.length() - i - 1);
		str = s1 + eval_str(s2) + s3;
		//cout << "str " <<str<<endl;
		//cout <<"in brackets "<<s2<<endl;
	}
	str = eval_str(str);
	check_trash(str);
	//convert and print ans
	try
	{
		Fixed ans(std::stof(str));
		cout << ans << endl;
	}
	catch (std::exception& e)
	{
		inv_expr();
	}
}

int		main(int ac, char **av)
{
	try {algo(ac, av);}
	catch (std::exception &e)
	{
		cout << "Unexpected error... But not a segfault anyway c(:";
		cout << " Probably the input is invalid." <<endl;
	}
	return 0;
}