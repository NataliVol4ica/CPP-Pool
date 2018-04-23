#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form(ShrubberyCreationForm::name, ShrubberyCreationForm::signGrade, ShrubberyCreationForm::execGrade)
{
	this->target = "unnamed";
}

ShrubberyCreationForm::ShrubberyCreationForm(string const &target) : Form(ShrubberyCreationForm::name, ShrubberyCreationForm::signGrade, ShrubberyCreationForm::execGrade)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref) : Form(ShrubberyCreationForm::name, ShrubberyCreationForm::signGrade, ShrubberyCreationForm::execGrade)
{
	*this = ref;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
	Form::operator=(ref);
	this->target = ref.getTarget();
	return *this;
}

string		ShrubberyCreationForm::getTarget(void)const {return this->target;}

const string	ShrubberyCreationForm::name = "ShrubberyCreationForm";
const int		ShrubberyCreationForm::signGrade = 145;
const int		ShrubberyCreationForm::execGrade = 137;

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > this->execGrade)
		throw (Form::GradeTooLowException());
	std::fstream file;
	file.open(this->target, std::fstream::out);
	file << "    &&&"<<endl;
	file << "   &&&/&"<<endl;
	file << " &\\/&|&&&&"<<endl;
	file << "&&&\\&|&/&&&"<<endl;
	file << " &&&\\|/&&&"<<endl;
	file << "  & }}{  &"<<endl;
	file << "    }{{"<<endl;
	file.close();
}
