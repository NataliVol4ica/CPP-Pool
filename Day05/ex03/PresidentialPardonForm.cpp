#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(PresidentialPardonForm::name, PresidentialPardonForm::signGrade, PresidentialPardonForm::execGrade)
{
	this->target = "unnamed";
}

PresidentialPardonForm::PresidentialPardonForm(string const &target) : Form(PresidentialPardonForm::name, PresidentialPardonForm::signGrade, PresidentialPardonForm::execGrade)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref) : Form(PresidentialPardonForm::name, PresidentialPardonForm::signGrade, PresidentialPardonForm::execGrade)
{
	*this = ref;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
	Form::operator=(ref);
	this->target = ref.getTarget();
	return *this;
}

string		PresidentialPardonForm::getTarget(void)const {return this->target;}

const string	PresidentialPardonForm::name = "PresidentialPardonForm";
const int		PresidentialPardonForm::signGrade = 25;
const int		PresidentialPardonForm::execGrade = 5;

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > this->execGrade)
		throw (Form::GradeTooLowException());
	cout << this->target<<" has been pardoned by Zaphod Beeblebrox."<<endl;
}
