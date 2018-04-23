#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock()
{
	this->intern = NULL;
	this->buSign = NULL;
	this->buExec = NULL;
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *buSign, Bureaucrat *buExec)
{
	this->intern = intern;
	this->buSign = buSign;
	this->buExec = buExec;
}

OfficeBlock::~OfficeBlock() {}

void	OfficeBlock::setIntern(Intern *ref) {this->intern = ref;}
void	OfficeBlock::setBuSign(Bureaucrat *ref) {this->buSign = ref;}
void	OfficeBlock::setBuExec(Bureaucrat *ref) {this->buExec = ref;}

Intern*		OfficeBlock::getIntern(void) const	{return this->intern;}
Bureaucrat*	OfficeBlock::getBuSign(void) const	{return this->buSign;}
Bureaucrat*	OfficeBlock::getBuExec(void) const	{return this->buExec;}

void	OfficeBlock::doBureaucracy(string form, string target)
{
	Form *f;
	if (!this->intern)
		throw InternMissingException();
	if (!this->buSign)
		throw SigningBureaucratMissingException();
	if (!this->buExec)
		throw ExecutingBureaucratMissingException();
	f = intern->makeForm(form, target);
	buSign->signForm(*f);
	buExec->executeForm(*f);
}

/* EXCEPTIONS */

OfficeBlock::InternMissingException::InternMissingException() {}
OfficeBlock::InternMissingException::InternMissingException(OfficeBlock::InternMissingException const &ref) {*this = ref;}
OfficeBlock::InternMissingException::~InternMissingException() throw() {}
OfficeBlock::InternMissingException &OfficeBlock::InternMissingException::operator=(OfficeBlock::InternMissingException const &ref)
{
	exception::operator=(ref);
	return *this;
}
const char* OfficeBlock::InternMissingException::what() const throw()
{
	return "The intern is missing.";
}

OfficeBlock::SigningBureaucratMissingException::SigningBureaucratMissingException() {}
OfficeBlock::SigningBureaucratMissingException::SigningBureaucratMissingException(OfficeBlock::SigningBureaucratMissingException const &ref) {*this = ref;}
OfficeBlock::SigningBureaucratMissingException::~SigningBureaucratMissingException() throw() {}
OfficeBlock::SigningBureaucratMissingException &OfficeBlock::SigningBureaucratMissingException::operator=(OfficeBlock::SigningBureaucratMissingException const &ref)
{
	exception::operator=(ref);
	return *this;
}
const char* OfficeBlock::SigningBureaucratMissingException::what() const throw()
{
	return "The signing bureaucrat is missing.";
}

OfficeBlock::ExecutingBureaucratMissingException::ExecutingBureaucratMissingException() {}
OfficeBlock::ExecutingBureaucratMissingException::ExecutingBureaucratMissingException(OfficeBlock::ExecutingBureaucratMissingException const &ref) {*this = ref;}
OfficeBlock::ExecutingBureaucratMissingException::~ExecutingBureaucratMissingException() throw() {}
OfficeBlock::ExecutingBureaucratMissingException &OfficeBlock::ExecutingBureaucratMissingException::operator=(OfficeBlock::ExecutingBureaucratMissingException const &ref)
{
	exception::operator=(ref);
	return *this;
}
const char* OfficeBlock::ExecutingBureaucratMissingException::what() const throw()
{
	return "The executing bureaucrat is missing.";
}

/* PRIVATE */
/*
OfficeBlock::OfficeBlock(OfficeBlock const &ref)
{
	*this = ref;
}

OfficeBlock &OfficeBlock::operator=(OfficeBlock const &ref)
{
	this->intern = ref.getIntern();
	this->buSign = ref.getBuSign();
	this->buExec = ref.getBuExec();
	return *this;
}
*/