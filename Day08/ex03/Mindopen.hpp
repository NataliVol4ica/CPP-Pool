#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

#include "defines.hpp"
#include "Op.hpp"
#include <queue>

#define ARRSIZE 30000

class Op;

class Mindopen
{
public:
	Mindopen(void);
	Mindopen(unsigned int size);
	~Mindopen();

	char*		getArr(void)const;
	char		getArrVal(unsigned int index);
	void		setArrVal(char value);
	unsigned int	getSize(void)const;	
	unsigned int	getIndex(void)const;
	void		setIndex(unsigned int index);

	void	addCommand(Op *newcmd);
	void	runProgram(void);

private:
	char 			*arr;
	unsigned int	size;
	unsigned int	index;

	Mindopen &operator=(Mindopen const &ref);
	Mindopen(Mindopen const &ref);
	std::queue<Op *> commands;
};

#endif
