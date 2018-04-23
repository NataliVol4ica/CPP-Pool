#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	Intern i;
	Bureaucrat b1("signBur", 100);
	Bureaucrat b2("execBur", 50);
	OfficeBlock ob;
	ob.setIntern(&i);
	ob.setBuSign(&b1);
	ob.setBuExec(&b2);
	ob.doBureaucracy("shrubbery creation", "test_file");
	cout<<"============"<<endl;
	try
	{
		Bureaucrat b1("signBur", 100);
		Bureaucrat b2("execBur", 50);
		OfficeBlock ob;
		ob.setIntern(&i);
		ob.setBuExec(&b2);
		ob.doBureaucracy("shrubbery creation", "test_file");
	}
	catch (exception &e) {cout <<e.what()<<endl;}
	cout<<"============"<<endl;
	try
	{
		Bureaucrat b1("signBur", 150);
		Bureaucrat b2("execBur", 50);
		OfficeBlock ob;
		ob.setIntern(&i);
		ob.setBuSign(&b1);
		ob.setBuExec(&b2);
		ob.doBureaucracy("shrubbery creation", "kek");
	}
	catch (exception &e) {cout <<e.what()<<endl;}
	cout<<"============"<<endl;
	return 0;
}
