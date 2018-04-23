#include "mutantstack.hpp"

int		main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	cout << mstack.top() << endl;
	mstack.pop();
	cout << mstack.size() << endl;
	mstack.push(3);
	mstack.push(10);
	mstack.push(737);
	//[...]
	mstack.push(0);
	cout <<"iterator"<<endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		cout << *it << endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

