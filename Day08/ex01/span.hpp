#ifndef SPAN_HPP
# define SPAN_HPP

#include "defines.hpp"
#include <list>

class Span
{
public:
	class OutOfRangeException : public exception
	{
	public:
		OutOfRangeException();
		OutOfRangeException(OutOfRangeException const &ref);
		OutOfRangeException &operator=(OutOfRangeException const &ref);
		~OutOfRangeException() throw();
		virtual const char* what() const throw();
	};
	class IncorrectContainerSizeException : public exception
	{
	public:
		IncorrectContainerSizeException();
		IncorrectContainerSizeException(IncorrectContainerSizeException const &ref);
		IncorrectContainerSizeException &operator=(IncorrectContainerSizeException const &ref);
		~IncorrectContainerSizeException() throw();
		virtual const char* what() const throw();
	};
	Span(unsigned int N);
	Span(Span const &ref);
	Span &operator=(Span const &ref);
	~Span();

	unsigned int	getMaxSize(void) const;
	std::list<int>	getTheList(void)const;

	void	addNumber(int number);
	template <typename T>
	void	addNumber(typename T::iterator from, typename T::iterator until)
	{
		int len = 0;
		typename T::iterator f = from;
		while (f != until)
		{
			len++;
			if (len + theList.size() > max_size)
				throw OutOfRangeException();
			++f;
		}
		while (from != until)
		{
			theList.push_back(*from);
			++from;
		}
	}
	int		shortestSpan(void);
	int		longestSpan(void);

private:
	unsigned int max_size;
	std::list<int> theList;
	Span();
};

template <typename T>
T	const	&max(T const &x, T const &y)
{
	return x >= y ? x : y;
}

template <typename T>
T	const	&min(T const &x, T const &y)
{
	return x <= y ? x : y;
}

template <typename T>
T	const	&abs(T const &x)
{
	return x < 0 ? -x : x;
}

#endif
