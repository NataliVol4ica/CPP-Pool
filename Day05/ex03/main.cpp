
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	Intern i;
	i.makeForm("robotomy request", "t1");
	i.makeForm("presidental pardon", "t2");
	i.makeForm("shrubbery creation", "t3");
	try {
		i.makeForm("unexisting form", "t4");
	}catch (exception &e)
	{
		cout <<"Error. "<<e.what()<<endl;
	}
	return 0;
}
