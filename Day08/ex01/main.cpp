#include "span.hpp"
#include <list>
#include <ctime>
#include <algorithm>

void	print_val(int val)
{
	cout<< val << " ";
}

int		main(void)
{
	/*Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	cout << sp.shortestSpan() << endl;
	cout << sp.longestSpan() << endl;*/

	srand(time(NULL));
	int size = arc4random_uniform(10000) + 10000;
	std::list<int> int_list;
	for (int i = 0; i < size; i++)
		int_list.push_back(arc4random_uniform(10000));
	cout <<"Generated container of size ["<<size<<"]:"<<endl;
	//for_each(int_list.begin(), int_list.end(), print_val);
	//cout <<endl;
	try {
		Span sp = Span(arc4random_uniform(10000) + 10000);
		sp.addNumber(7);
		sp.addNumber<std::list<int> >(int_list.begin(), int_list.end());
		cout << "Shortest span " << sp.shortestSpan() << endl;
		cout << "Longest span " << sp.longestSpan() << endl;
	}
	catch (exception &e)
	{
		cout <<e.what()<<endl;
	}
	return 0;
}
