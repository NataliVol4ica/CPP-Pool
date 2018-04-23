#ifndef OP_HPP
# define OP_HPP

#include "defines.hpp"
#include "Mindopen.hpp"

class Mindopen;

class Op
{
public:
	Op(void);
	~Op(void);
	virtual void execute(Mindopen *prog) = 0;
	virtual Op *createcmd(void) = 0;
protected:
	Op(Op const &ref);
	Op &operator=(Op const &ref);
};

#endif
