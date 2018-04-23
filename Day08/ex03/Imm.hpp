#ifndef IMM_HPP
# define IMM_HPP

#include "Op.hpp"

class Imm : public Op
{
public:
	Imm(void);
	~Imm(void);

	void	execute(Mindopen *prog);
	Op *createcmd(void);

private:
	Imm(Imm const &ref);
	Imm &operator=(Imm const &ref);

};

#endif

