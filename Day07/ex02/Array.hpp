#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <ctime>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define exception std::exception

template <typename T>
class Array
{
public:
	Array<T>(void) : length(0)
	{
		this->array = new T[0];
	}
	Array<T>(unsigned int l) : length(l)
	{
		this->array = new T[this->length];
		for (unsigned int i = 0; i < this->length; i++)
			this->array[i] = 0;
	}
	Array<T>(Array<T> const &arr) : length(arr.size())
	{
		this->array = new T[this->length];
		for (unsigned int i = 0; i < this->length; i++)
			this->array[i] = arr[i];
	}
	~Array<T>(void)
	{
		delete(this->array);
	}
	unsigned int	size(void) const
	{
		return this->length;
	}
	/* OPERATORS */
	Array<T> &operator=(Array<T> const &ref)
	{
		if (this->length != ref.size())
		{
			delete[] this->array;
			this->length = ref.size();
			this->array = new T[this->length];
		}
		for (unsigned int i = 0; i < this->length; i++)
			this->array[i] = ref[i];
		return *this;
	}
	T &operator[](unsigned int const index) const
	{
		if (index >= this->length)
			throw std::out_of_range("Error: Index is out of range.");
		return this->array[index];
	}
private:
	T *array;
	unsigned int length;
};

#endif
