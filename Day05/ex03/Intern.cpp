#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(Intern const &ref)
{
	*this = ref;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &ref)
{
	(void)ref;
	return *this;
}

/* EXCEPTIONS */

Intern::UnknownFormException::UnknownFormException() {}
Intern::UnknownFormException::UnknownFormException(Intern::UnknownFormException const &ref) {*this = ref;}
Intern::UnknownFormException::~UnknownFormException() throw() {}
Intern::UnknownFormException &Intern::UnknownFormException::operator=(Intern::UnknownFormException const &ref)
{
	exception::operator=(ref);
	return *this;
}
const char* Intern::UnknownFormException::what() const throw()
{
	return "There is no such form.";
}


Form	*Intern::makeForm(string type, string target)
{
	Form *f;
	if (type == "robotomy request")
		f = (Form*) new RobotomyRequestForm(target);
	else if (type == "presidental pardon")
		f = (Form*) new PresidentialPardonForm(target);
	else if (type == "shrubbery creation")
		f = (Form*) new ShrubberyCreationForm(target);
	else throw UnknownFormException();
	cout <<"Intern creates "<<*f<<endl;
	return f;
}