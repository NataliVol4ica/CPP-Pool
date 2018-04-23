#include "defines.hpp"

int main(void)
{
	string s = "HI THIS IS BRAIN";
	string *sptr = &s;
	string &sref = s;

	cout << "ptr "<< *sptr << " ref "<< sref << endl;
	return 0;
}
