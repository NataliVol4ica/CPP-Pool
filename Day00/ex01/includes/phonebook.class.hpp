
#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "defines.hpp"

class Contact{
public:

	Contact(void);
	void	set_contact(t_read *data);
	void	print_short(void);
	void	print_long(void);
	static int gettotal(void);
	~Contact(void);

private:
	int	index;
	string fname, lname;
	string nickname, login;
	string padress, email;
	string pnumber;
	string bday;
	string meal;
	string ucolor;
	string secret;
	static int	_num_of_contacts;

	void	print_prec(string line);
};

#endif
