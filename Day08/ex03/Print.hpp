#ifndef PRINT_HPP
# define PRINT_HPP

#include "Op.hpp"

class Print : public Op
{
public:
	Print(void);
	~Print(void);

	void	execute(Mindopen *prog);
	Op *createcmd(void);

private:
	Print(Print const &ref);
	Print &operator=(Print const &ref);

};

#endif
