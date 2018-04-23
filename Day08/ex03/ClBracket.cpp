#include "ClBracket.hpp"

ClBracket::ClBracket(int index): goTo(index) {}
ClBracket::~ClBracket(void) {}

void	ClBracket::execute(Mindopen *prog)
{
	if (prog->getIndexVal(prog->getIndex()
	prog->setindex(goTo);
}

Op *ClBracket::createcmd(void)
{
	return dynamic_cast<Op*>(new ClBracket(this->goTo));
}
