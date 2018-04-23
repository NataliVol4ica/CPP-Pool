#include "RobotomyRequestForm.hpp"
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : Form(RobotomyRequestForm::name, RobotomyRequestForm::signGrade, RobotomyRequestForm::execGrade)
{
	this->target = "unnamed";
}

RobotomyRequestForm::RobotomyRequestForm(string const &target) : Form(RobotomyRequestForm::name, RobotomyRequestForm::signGrade, RobotomyRequestForm::execGrade)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) : Form(RobotomyRequestForm::name, RobotomyRequestForm::signGrade, RobotomyRequestForm::execGrade)
{
	*this = ref;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	Form::operator=(ref);
	this->target = ref.getTarget();
	return *this;
}

string		RobotomyRequestForm::getTarget(void)const {return this->target;}

const string	RobotomyRequestForm::name = "RobotomyRequestForm";
const int		RobotomyRequestForm::signGrade = 72;
const int		RobotomyRequestForm::execGrade = 45;

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > this->execGrade)
		throw (Form::GradeTooLowException());
	cout <<"*Drilling noises"<<endl;
	srand(time(NULL));
	int r = arc4random_uniform(100);
	if (r < 50)
		cout << this->target<<"has been robotomized successfully."<<endl;
	else
		cout<<this->target<<" failed to be robotomized."<<endl;
}
