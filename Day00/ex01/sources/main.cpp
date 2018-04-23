
#include "defines.hpp"
#include "phonebook.class.hpp"

#define MAX_CONTACTS 8

string names[3] = {"ADD", "SEARCH", "EXIT"};

void	reopen_stdin(void)
{
	cout << "\n[!] Unexpected end of input stream... Stop cheating, you bastard! D:<" << endl;
	freopen(NULL, "rw", stdin);
	cin.clear();
}

int		read_contact(Contact *contacts)
{
	t_read	data;
	int ind;

	cout << "Enter first name or die: ";
	if (!(getline(cin, data.fname))) return 0;
	cout << "Enter last name or die: ";
	if (!(getline(cin, data.lname))) return 0;
	cout << "Enter nickname or die: ";
	if (!(getline(cin, data.nickname))) return 0;
	cout << "Enter login or die: ";
	if (!(getline(cin, data.login))) return 0;
	cout << "Enter postal adress or die: ";
	if (!(getline(cin, data.padress))) return 0;
	cout << "Enter email or die: ";
	if (!(getline(cin, data.email))) return 0;
	cout << "Enter phone number or die: ";
	if (!(getline(cin, data.pnumber))) return 0;
	cout << "Enter birthday date or die: ";
	if (!(getline(cin, data.bday))) return 0;
	cout << "Enter favorite meal or die: ";
	if (!(getline(cin, data.meal))) return 0;
	cout << "Enter underwear color or die: ";
	if (!(getline(cin, data.ucolor))) return 0;
	cout << "Enter darkest secret AND die of shame: ";
	if (!(getline(cin, data.secret))) return 0;
	ind = Contact::gettotal();
	contacts[ind].set_contact(&data);
	return 1;
}

int		main(void)
{
	string	cmd;
	int		cmd_ind;
	//int 	nofcont = 0;
	Contact contacts[8];

	do
	{
		cout<<"Ready to read your command, master!\n> ";
		if (!getline(cin, cmd))
		{
			reopen_stdin();
			cout << "[!] Restarted... Dont you dare fail this time.\n> ";
			if (!getline(cin, cmd))
			{
				cout << endl << "[!] You don't know when to stop, do you?";
				cout << "Never call me back. Farewell." << endl;
				return (0);
			}
		}
		cmd_ind = 3;
		for (int i = 0; i < 3; i++)
			if (cmd == names[i])
				cmd_ind = i;
		switch (cmd_ind)
		{
			case 0:
			{
				if (Contact::gettotal() >= MAX_CONTACTS)
				{
					cout << "[!] Sorry but the phonebook is busy right now. ";
					cout << "Please call back later." << endl;
					cout << "[!!!] Your opinion is very important for us <3"<<endl;
					break;
				}
				if (!read_contact(contacts))
				{
					cout << endl << "[!] The contact won't be saved." << endl;
					cout << "[!] Sorry but you are dick." << endl;
					freopen(NULL, "rw", stdin);
					cin.clear();
				}
				break;
			}
			case 1:
			{
				int index;
				cout << "Aaaalright. Wait a sec.. Gonna let you know everything about... Whom? " << endl;
				cout << "IND| firstname|  lastname|nickname" << endl;
				for (int i = 0 ; i < Contact::gettotal(); i++)
					contacts[i].print_short();
				cout << endl << "> ";
				if (!(cin >> index))
				{
					cout << "[!] Are you stupid? this is not a number." << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
				freopen(NULL, "rw", stdin);
				if (!(index > 0 && index <= Contact::gettotal()))
				{
					cout << "[!] There is no such contact. And I'm out of abuse ideas."<<endl;
					break;
				}
				contacts[index - 1].print_long();
				break;
			}
			case 2:
			{
				cout << "I will miss you... Come back soon! :'(" << endl;
				return 0;
				break;
			}
			default:
			{
				cout << "[!] Have you no idea what you are doing?" << endl;
				cout << "[!] Stop loosing my respect and read the subject first, please..." << endl;
				break;
			}
		}
	} while (true);
	return (0);
}
