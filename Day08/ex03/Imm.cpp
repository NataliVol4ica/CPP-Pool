#include "Imm.hpp"

Imm::Imm(void) {}
Imm::~Imm(void) {}

void	Imm::execute(Mindopen *prog)
{
	prog->setIndex(prog->getIndex() - 1);
}

Op *Imm::createcmd(void)
{
	return dynamic_cast<Op*>(new Imm());
}
