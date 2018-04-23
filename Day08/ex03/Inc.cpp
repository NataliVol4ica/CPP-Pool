#include "Inc.hpp"

Inc::Inc(void) {}
Inc::~Inc(void) {}

void	Inc::execute(Mindopen *prog)
{
	prog->setArrVal(prog->getArrVal(prog->getIndex()) + 1);
}

Op *Inc::createcmd(void)
{
	return dynamic_cast<Op*>(new Inc());
}
