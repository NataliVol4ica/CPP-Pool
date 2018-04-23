#include "Form.hpp"

Form::Form() : name("Unnamed Form"), signGrade(1), execGrade(1) {this->isSigned = false;}
Form::Form(string const &n, int sign, int exec) : name(n), signGrade(sign), execGrade(exec) {
	if (sign < 1 || exec < 1)
		throw (Form::GradeTooHighException());
	else if (sign > 150 || exec > 150)
		throw (Form::GradeTooLowException());
	this->isSigned = false;
}
Form::Form(Form const &ref) : name ("Unnamed"), signGrade(ref.getSignGrade()), execGrade(ref.getExecGrade())
{
	this->isSigned = ref.getIsSigned();
}

Form::~Form() {}

int		Form::getSignGrade(void) const {return this->signGrade;}
int		Form::getExecGrade(void) const {return this->execGrade;}
bool	Form::getIsSigned(void) const {return this->isSigned;}
string	Form::getName(void) const {return this->name;}

Form &Form::operator=(Form const &ref)
{
	this->isSigned= ref.getIsSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &ref)
{
	o << ref.getName() <<", sign grade "<<ref.getSignGrade()<<" , exec grade "<<ref.getExecGrade()<<", isSigned "<<ref.getIsSigned();
	return o;
}

/* EXCEPTIONS */

Form::GradeTooHighException::GradeTooHighException() {}
Form::GradeTooHighException::GradeTooHighException(Form::GradeTooHighException const &ref) {*this = ref;}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
Form::GradeTooHighException &Form::GradeTooHighException::operator=(Form::GradeTooHighException const &ref)
{
	exception::operator=(ref);
	return *this;
}
const char* Form::GradeTooHighException::what() const throw()
{
	return "The grade is too high.";
}

Form::GradeTooLowException::GradeTooLowException() {}
Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const &ref) {*this = ref;}
Form::GradeTooLowException::~GradeTooLowException() throw() {}
Form::GradeTooLowException &Form::GradeTooLowException::operator=(Form::GradeTooLowException const &ref)
{
	exception::operator=(ref);
	return *this;
}
const char* Form::GradeTooLowException::what() const throw()
{
	return "The grade is too low.";
}

void	Form::beSigned(Bureaucrat const &ref)
{
	if (this->isSigned) {cout << *this << " is already signed!"<<endl; return;}
	if (ref.getGrade() > this->signGrade)
		throw (GradeTooLowException());
	this->isSigned = true;
}
