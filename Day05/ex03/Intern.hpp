
#ifndef INTERN_HPP
# define INTERN_HPP

#include "defines.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	/* EXCEPTIONS */
	class UnknownFormException : public exception
	{
	public:
		UnknownFormException();
		UnknownFormException(UnknownFormException const &ref);
		~UnknownFormException() throw();
		UnknownFormException &operator=(UnknownFormException const &ref);
		virtual const char* what() const throw();
	};
	
	/* CLASS */
	Intern();
	Intern(Intern const &ref);
	~Intern();

	Intern &operator=(Intern const &ref);

	Form *makeForm(string type, string target);

private:
};

std::ostream &operator<<(std::ostream &o, Intern const &ref);

#endif
