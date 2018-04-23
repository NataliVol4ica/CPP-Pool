
#include "Bureaucrat.hpp"

int		main(void)
{
	try {Bureaucrat b("test", 0);}
	catch(exception &e) { cout << "1. " << e.what() << endl;}
	try {Bureaucrat b("test", 151);}
	catch(exception &e) { cout << "2. " << e.what() << endl;}
	try {
		Bureaucrat b("test", 1);
		b.decGrade();
		b.incGrade();
		b.incGrade();
	}
	catch(exception &e) { cout << "3. " << e.what() << endl;}
	try {
		Bureaucrat b("test", 150);
		b.incGrade();
		b.decGrade();
		b.decGrade();
	}
	catch(exception &e) { cout << "4. " << e.what() << endl;}
	Bureaucrat br("BureaucratName", 50);
	cout<<br<<endl;
	Bureaucrat br2;
	cout<<br2<<endl;
	return 0;
}
