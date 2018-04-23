#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include "defines.hpp"
#include <stack>
#include <list>
#include <iterator>

template <typename T>
class MutantStack// : public std::stack<T>
{
public:

	typedef T container_type;
	typedef typename std::list<T>::size_type size_type;
	typedef typename std::list<T>::iterator			iterator;
	typedef typename std::list<T>::const_iterator	const_iterator;

	/* CONSTRUCTORS */

	MutantStack(void) {}
	MutantStack(MutantStack const &ref) {*this = ref;}

	/* OPERATORS OVERLOAD */

	MutantStack &operator=(MutantStack const &ref) {this->data = ref.getData();}
	operator std::stack<T>(void)
	{
		std::stack<T> ret;

		typename std::list<T>::iterator it, until = this->data.begin();
		for (it = this->data.end(); it != until; --it)
			ret.push(*it);
		return ret;
	}

	/* ITERATORS */

	typename std::list<T>::iterator	begin(void){
		return this->data.begin();
	}
	typename std::list<T>::iterator	end(void){
		return this->data.end();
	}
	typename std::list<const T>::const_iterator	begin(void)const
	{
		return const_cast<typename std::list<const T>::const_iterator>(this->data.begin());
	}
	typename std::list<const T>::const_iterator	end(void)const
	{
		return const_cast<typename std::list<const T>::const_iterator>(this->data.end());
	}

	/* GET SET */

	std::list<T>	getData(void) const { return this->data; }

	/* ELEMENT ACCESS */

	T const &top(void) const
	{
		return data.back();
	}

	/* CAPACITY */

	bool	empty(void) const
	{
		if (this->data.size() == 0)
			return true;
		return false;
	}
	
	unsigned int 	size(void)const 
	{
		return this->data.size();
	}

	/* MODIFIERS */

	void	push(T const &ref)
	{
		data.push_back(ref);
	}

	void	pop(void)
	{
		if (this->size() > 0)
			this->data.erase(--this->end());
	}

private:
	std::list<T> 	data;
};



#endif
