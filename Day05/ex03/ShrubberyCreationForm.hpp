
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &ref);
	~ShrubberyCreationForm();
	
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ref);

	string		getTarget(void)const;
	void		execute(Bureaucrat const &executor) const;

private:
	string				target;
	static const string name;
	static const int	signGrade;
	static const int	execGrade;
};

#endif
