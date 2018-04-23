#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

class OfficeBlock
{
public:
	/* EXCEPTIONS */
	class InternMissingException : public exception
	{
	public:
		InternMissingException();
		InternMissingException(InternMissingException const &ref);
		~InternMissingException() throw();
		InternMissingException &operator=(InternMissingException const &ref);
		virtual const char* what() const throw();
	};
	class SigningBureaucratMissingException : public exception
	{
	public:
		SigningBureaucratMissingException();
		SigningBureaucratMissingException(SigningBureaucratMissingException const &ref);
		~SigningBureaucratMissingException() throw();
		SigningBureaucratMissingException &operator=(SigningBureaucratMissingException const &ref);
		virtual const char* what() const throw();
	};
	class ExecutingBureaucratMissingException : public exception
	{
	public:
		ExecutingBureaucratMissingException();
		ExecutingBureaucratMissingException(ExecutingBureaucratMissingException const &ref);
		~ExecutingBureaucratMissingException() throw();
		ExecutingBureaucratMissingException &operator=(ExecutingBureaucratMissingException const &ref);
		virtual const char* what() const throw();
	};
	/* CLASS */
	OfficeBlock();
	OfficeBlock(Intern *intern, Bureaucrat *buSign, Bureaucrat *buExec);
	~OfficeBlock();

	void	setIntern(Intern *ref);
	void	setBuSign(Bureaucrat *ref);
	void	setBuExec(Bureaucrat *ref);

	Intern		*getIntern(void) const;
	Bureaucrat	*getBuSign(void) const;
	Bureaucrat	*getBuExec(void) const;

	void	doBureaucracy(string form, string target);

private:
	Intern 		*intern;
	Bureaucrat 	*buSign;
	Bureaucrat	*buExec;

//	OfficeBlock(OfficeBlock const &ref);
//	OfficeBlock &operator=(OfficeBlock const &ref);
};

#endif
