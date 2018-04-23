#include "Print.hpp"

Print::Print(void) {}
Print::~Print(void) {}

void	Print::execute(Mindopen *prog)
{
	cout<<(prog->getArrVal(prog->getIndex()));
}

Op *Print::createcmd(void)
{
	return dynamic_cast<Op*>(new Print());
}
