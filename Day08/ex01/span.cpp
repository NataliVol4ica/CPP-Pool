#include "span.hpp"

/* COPLIEN */

Span::Span() : max_size(0){}
Span::Span(unsigned int N) : max_size(N)  
{
	cout <<"Created Span instance of size ["<<N<<"]"<<endl;
}
Span::Span(Span const &ref) : max_size(ref.getMaxSize())
{
	*this = ref;
}

Span &Span::operator=(Span const &ref)
{
	this->max_size = ref.getMaxSize();
	this->theList = ref.getTheList();
	return *this;
}

Span::~Span(){}

/* GET SET */

unsigned int	Span::getMaxSize(void) const	{return this->max_size;}
std::list<int>	Span::getTheList(void)const		{return this->theList;}

/* EXCEPTION */

// OutOfRange

Span::OutOfRangeException::OutOfRangeException(){}

Span::OutOfRangeException::OutOfRangeException(OutOfRangeException const &ref)
{
	*this = ref;
}

Span::OutOfRangeException &Span::OutOfRangeException::operator=(OutOfRangeException const &ref)
{
	exception::operator=(ref);
	return *this;
}

Span::OutOfRangeException::~OutOfRangeException() throw() {}

const char* Span::OutOfRangeException::what() const throw()
{
	return "Cannot add new members because they do not fid container size limits.";
}

// Span Calc Error

Span::IncorrectContainerSizeException::IncorrectContainerSizeException(){}

Span::IncorrectContainerSizeException::IncorrectContainerSizeException(IncorrectContainerSizeException const &ref)
{
	*this = ref;
}

Span::IncorrectContainerSizeException &Span::IncorrectContainerSizeException::operator=(IncorrectContainerSizeException const &ref)
{
	exception::operator=(ref);
	return *this;
}

Span::IncorrectContainerSizeException::~IncorrectContainerSizeException() throw() {}

const char* Span::IncorrectContainerSizeException::what() const throw()
{
	return "Cannot calculate the span. There are not enough numbers stored.";
}

/* FUNCTIONS */

void	Span::addNumber(int number)
{
	if (theList.size() == max_size)
		throw OutOfRangeException();
	theList.push_back(number);
}


int		Span::shortestSpan(void)
{
	if (theList.size() < 2)
		throw IncorrectContainerSizeException();

	int ans = abs(*theList.begin() - *(++theList.begin()));
	std::list<int>::iterator i, j, until = theList.end();
	for (i = theList.begin(); i != until; ++i)
		for (j = i; j != until; ++j)
		{
			if (i == j)
				continue;
			ans = min(ans, abs(*i - *j));
		}
	return ans;
}

int		Span::longestSpan(void)
{
	if (theList.size() < 2)
		throw IncorrectContainerSizeException();

	int ans = abs(*theList.begin() - *(++theList.begin()));
	std::list<int>::iterator i, j, until = theList.end();
	for (i = theList.begin(); i != until; ++i)
		for (j = i; j != until; ++j)
		{
			if (i == j)
				continue;
			ans = max(ans, abs(*i - *j));
		}
	return ans;
}
