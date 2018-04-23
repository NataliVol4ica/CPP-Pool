
#include "phonebook.class.hpp"

void Contact::set_contact(t_read *data)
{
	this->_num_of_contacts++;
	this->index = this->_num_of_contacts;
	this->fname = data->fname;
	this->lname = data->lname;
	this->nickname = data->nickname;
	this->login = data->login;
	this->padress = data->padress;
	this->email = data->email;
	this->pnumber = data->pnumber;
	this->bday = data->bday;
	this->meal = data->meal;
	this->ucolor = data->ucolor;
	this->secret = data->secret;
	cout << "Mmmm, very interesting... Alright, adding this contact to our spam database.. Done! ^_^"<<endl;
}

Contact::Contact(void)
{

}

void	Contact::print_prec(string s)
{
	if (s.length() <= 10)
	{
		cout << std::setw(10) << s;
		return ;
	}
	for (int i = 0; i < 9; i++)
		cout<<s[i];
	cout<<".";
}

void	Contact::print_short(void)
{
	cout << std::setw(3) << this->index <<"|";
	print_prec(this->fname);
	cout << "|";
	print_prec(this->lname);
	cout << "|";
	print_prec(this->nickname);
}

void	Contact::print_long(void)
{
	cout << this->fname << endl;
	cout << this->lname << endl;
	cout << this->nickname << endl;
	cout << this->login  << endl;
	cout << this->padress  << endl;
	cout << this->email << endl;
	cout << this->pnumber  << endl;
	cout << this->bday << endl;
	cout << this->meal << endl;
	cout << this->ucolor << endl;
	cout << this->secret << endl;
}

Contact::~Contact(void)
{ 
	this->_num_of_contacts--;
}

int Contact::gettotal(void)
{
	return Contact::_num_of_contacts;
}

int		Contact::_num_of_contacts = 0;