
#include <iostream>
#include <ctime>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define getline std::getline
#define exception std::exception

class Base
{
public:
	virtual ~Base(){};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *generate(void)
{
	int random = arc4random_uniform(3);
	if (random == 0)
	{
		cout << "created A"<<endl;
		return static_cast<Base*>(new A());
	}
	if (random == 1)
	{
		cout << "created B"<<endl;
		return static_cast<Base*>(new B());
	}
	cout << "created C"<<endl;
	return static_cast<Base*>(new C());
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		cout<<"A"<<endl;
	if (dynamic_cast<B*>(p))
		cout<<"B"<<endl;
	if (dynamic_cast<C*>(p))
		cout<<"C"<<endl;
}

void identify_from_reference(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		cout<<"A"<<endl;
	}
	catch (exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		cout<<"B"<<endl;
	}
	catch (exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		cout<<"C"<<endl;
	}
	catch (exception &e) {}
}

int	main(void)
{
	Base *ptr = generate();
	cout << "identification from pointer   : ";
	identify_from_pointer(ptr);
	cout << "identification from reference : ";
	identify_from_reference(*ptr);
	return 0;
}
