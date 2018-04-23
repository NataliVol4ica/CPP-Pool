
#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &ref);
	~PresidentialPardonForm();
	
	PresidentialPardonForm &operator=(PresidentialPardonForm const &ref);

	string		getTarget(void)const;
	void		execute(Bureaucrat const &executor) const;

private:
	string				target;
	static const string name;
	static const int	signGrade;
	static const int	execGrade;
};

#endif