
#ifndef FORM_HPP
# define FORM_HPP

#include "defines.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	/* EXCEPTIONS */
	class GradeTooHighException : public exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &ref);
		~GradeTooHighException() throw();
		GradeTooHighException &operator=(GradeTooHighException const &ref);
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &ref);
		~GradeTooLowException() throw();
		GradeTooLowException &operator=(GradeTooLowException const &ref);
		virtual const char* what() const throw();
	};
	/* CLASS */
	Form();
	Form(string const &n, int sign, int exec);
	Form(Form const &ref);
	~Form();

	Form &operator=(Form const &ref);

	int		getSignGrade(void) const;
	int		getExecGrade(void) const;
	bool	getIsSigned(void) const;
	string	getName(void) const;
	void	beSigned(Bureaucrat const &ref);

private:
	const string 	name;
	bool			isSigned;
	const int		signGrade;
	const int		execGrade;
};

std::ostream &operator<<(std::ostream &o, Form const &ref);

#endif
