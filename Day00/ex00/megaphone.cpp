
#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a') + 'A';
	return c;
}

int		main(int ac, char **av)
{
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	else
	{
		for (int i = 1; i < ac; i++)
			for (size_t j = 0; j < strlen(av[i]); j++)
				cout<<to_upper(av[i][j]);
		cout << endl;
	}
	return (0);
}
