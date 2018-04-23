
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	Bureaucrat br("b1", 5);
	ShrubberyCreationForm SCF("scf_file.txt");
	br.signForm(SCF);
	SCF.execute(br);
	try
	{
		Bureaucrat br2 ("br2", 144);
		ShrubberyCreationForm SCF2("./folder/file");
		br2.signForm(SCF2);
		br2.executeForm(SCF2);
	}
	catch (exception &e)
	{
		cout <<"Error! "<<e.what()<<endl;
	}
	try
	{
		Bureaucrat br2 ("br2", 144);
		ShrubberyCreationForm SCF2("./folder/file");
		br2.executeForm(SCF2);
	}
	catch (exception &e)
	{
		cout <<"Error! "<<e.what()<<endl;
	}
	RobotomyRequestForm RRF("some robo target");
	br.signForm(RRF);
	br.executeForm(RRF);
	PresidentialPardonForm PPF("some presidental target");
	br.signForm(PPF);
	br.executeForm(PPF);
}
