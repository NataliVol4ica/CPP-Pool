
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &ref);
	~RobotomyRequestForm();
	
	RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);

	string		getTarget(void)const;
	void		execute(Bureaucrat const &executor) const;

private:
	string				target;
	static const string name;
	static const int	signGrade;
	static const int	execGrade;
};
#endif
