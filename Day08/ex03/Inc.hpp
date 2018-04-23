#ifndef INC_HPP
# define INC_HPP

#include "Op.hpp"

class Inc : public Op
{
public:
	Inc(void);
	~Inc(void);

	void	execute(Mindopen *prog);
	Op *createcmd(void);

private:
	Inc(Inc const &ref);
	Inc &operator=(Inc const &ref);

};

#endif

