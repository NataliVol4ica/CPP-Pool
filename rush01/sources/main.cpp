#include <iostream>

int		sh_main(void);
int		ncur_main(void);
int		gtk_main(int ac, char **av);

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (static_cast<std::string>(av[1]) == "-g")
			gtk_main(ac, av);
		else if(static_cast<std::string>(av[1]) == "-n")
		{
			ncur_main();
		}
		else
		{
			std::cout << "usage: ./ft_gkrellm [flag] [-silly]"<<std::endl;
			std::cout << "    flags:"<<std::endl;
			std::cout << "\t-n for ncurses"<<std::endl;
			std::cout << "\t-g for graphical"<<std::endl;
			std::cout << "    -silly"<<std::endl;
			std::cout << "\tdoes stupid stuff for -g flag"<<std::endl;
		}
		return 0;
	}
	sh_main();
	return 0;
}
