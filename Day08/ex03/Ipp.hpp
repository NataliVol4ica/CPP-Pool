#ifndef IPP_HPP
# define IPP_HPP

#include "Op.hpp"

class Ipp : public Op
{
public:
	Ipp(void);
	~Ipp(void);

	void	execute(Mindopen *prog);
	Op *createcmd(void);

private:
	Ipp(Ipp const &ref);
	Ipp &operator=(Ipp const &ref);

};

#endif

