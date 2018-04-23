#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define exception std::exception
//#define list std::list
//#define map std::map
//#define vector std::vector

template <typename T>
typename T::iterator	easyfind(T shota, int tofind)
{
	typename T::iterator i;
	typename T::iterator until = shota.end();
	for (i = shota.begin(); i != until; ++i)
		if (*i == tofind)
			return i;
	throw std::out_of_range("You lost. Looser.");
	return until;
}

#endif
