
#include <iostream>
#include "easyfind.hpp"
#include <list>
#include <ctime>
#include <algorithm>

void	print_val(int val)
{
	cout<< val << " ";
}

template <typename T>
void	lottery (T container)
{
	try {
		int a = arc4random_uniform(100);
		cout <<"Generated container:"<<endl;
		for_each(container.begin(), container.end(), print_val);
		cout<<endl;
		cout <<"Looking for "<<a<<endl;
		easyfind(container, a);
		cout<<">>> Congrats! You won nothing! <<<"<<endl;
	}
	catch (exception &e)
	{
		cout << e.what()<<endl;
	}
}

int		main(void)
{
	system("clear a.out");
	cout <<"/ =========== LET THE LOTTERY BEGIN! =========== \\"<<endl;
	srand(time(NULL));
	int size = arc4random_uniform(15) + 5;
	std::list<int> int_list;
	for (int i = 0; i < size; i++)
		int_list.push_back(arc4random_uniform(100));
	lottery(int_list);
	return 0;
}
