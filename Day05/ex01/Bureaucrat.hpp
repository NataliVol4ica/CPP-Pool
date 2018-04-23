
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "defines.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
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
	Bureaucrat();
	Bureaucrat(string const &n, int grade);
	Bureaucrat(Bureaucrat const &ref);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &ref);

	int		getGrade(void) const;
	string	getName(void) const;
	void	incGrade(void);
	void	decGrade(void);
	void	signForm(Form &ref);

private:
	const string 	name;
	int				grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &ref);

#endif
