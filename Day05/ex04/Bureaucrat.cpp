#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {}
Bureaucrat::Bureaucrat(string const &n, int grade) : name(n) {
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &ref) : name ("Unnamed") {*this = ref;}

Bureaucrat::~Bureaucrat() {}

int		Bureaucrat::getGrade(void) const {return this->grade;}
string	Bureaucrat::getName(void) const {return this->name;}

void	Bureaucrat::incGrade(void)
{
	if (this->grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade--;
}
void	Bureaucrat::decGrade(void)
{
	if (this->grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade++;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ref)
{
	this->grade= ref.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &ref)
{
	o << ref.getName() <<", bureaucrat grade "<<ref.getGrade();
	return o;
}

/* EXCEPTIONS */

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException const &ref) {*this = ref;}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &ref)
{
	exception::operator=(ref);
	return *this;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high.";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const &ref) {*this = ref;}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &ref)
{
	exception::operator=(ref);
	return *this;
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low.";
}

/* OTHER FUNCS */

void	Bureaucrat::signForm(Form &ref)
{
	try
	{
		ref.beSigned(*this);
		cout << this->name <<" signs form "<<ref.getName()<<endl;
	}
	catch(exception &e)
	{
		cout << this->name <<" cannot sign form "<<ref.getName()<<" besause "<<e.what()<<endl;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		cout << this->name <<" executed form "<<form.getName()<<endl;
	}
	catch(exception &e)
	{
		cout << this->name <<" cannot execute form "<<form.getName()<<" besause "<<e.what()<<endl;
	}
}
