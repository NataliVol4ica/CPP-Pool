#include "Dec.hpp"

Dec::Dec(void) {}
Dec::~Dec(void) {}

void	Dec::execute(Mindopen *prog)
{
	prog->setArrVal(prog->getArrVal(prog->getIndex()) - 1);
}

Op *Dec::createcmd(void)
{
	return dynamic_cast<Op*>(new Dec());
}
