#ifndef DEC_HPP
# define DEC_HPP

#include "Op.hpp"

class Dec : public Op
{
public:
	Dec(void);
	~Dec(void);

	void	execute(Mindopen *prog);
	Op *createcmd(void);

private:
	Dec(Dec const &ref);
	Dec &operator=(Dec const &ref);

};

#endif

