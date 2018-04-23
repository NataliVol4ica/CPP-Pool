#include "Ipp.hpp"

Ipp::Ipp(void) {}
Ipp::~Ipp(void) {}

void	Ipp::execute(Mindopen *prog)
{
	prog->setIndex(prog->getIndex() + 1);
}

Op *Ipp::createcmd(void)
{
	return dynamic_cast<Op*>(new Ipp());
}
