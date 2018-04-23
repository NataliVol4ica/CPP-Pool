
#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	try {
		Bureaucrat b1("b1", 10);
		Form f1("f1", 10, 10);
		b1.signForm(f1);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	try {
		Bureaucrat b2("b2", 100);
		Form f2("f2", 10, 10);
		b2.signForm(f2);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
