#include "Mindopen.hpp"
#include "Ipp.hpp" //>
#include "Imm.hpp" //<
#include "Inc.hpp" //+
#include "Dec.hpp" //-
#include "Print.hpp"//.

#include <fstream>

int		main(int ac, char **av)
{
	if (ac != 2){
		cout <<"Usage: ./a.out SourceFile"<<endl;
		return 0;
	}
	try{
		//reagind
		ifstream inp (av[1]);
		string 	input = "";
		string	temp;

		while (!inp.eof())
		{
			getline(inp, temp);
			input += temp;
		}

		//parsing
		unsigned int 	index = 0;
		Mindopen mo;
		Mindopen silly;
		do
		{
			switch(input[index])
			{
				case '>':
				{
					index++;
					Ipp temp;
					mo.addCommand(temp.createcmd());
					temp.execute(&silly);
					break;
				}
				case '<':
				{
					index++;
					Imm temp;
					mo.addCommand(temp.createcmd());
					temp.execute(&silly);
					break;
				}
				case '+':
				{
					index++;
					Inc temp;
					mo.addCommand(temp.createcmd());
					temp.execute(&silly);
					break;
				}
				case '-':
				{
					index++;
					Dec temp;
					mo.addCommand(temp.createcmd());
					temp.execute(&silly);
					break;
				}
				case '.':
				{
					index++;
					Print temp;
					mo.addCommand(temp.createcmd());
					break;
				}
				case '[':
				{
					cout <<index<<" [ \""<<input<<"\" "<<endl;
					if (silly.getArrVal(silly.getIndex()) != 0)
					{
						cout <<"Ok "<<(int)silly.getArrVal(silly.getIndex())<<endl;
						index++;
						break;
					}
					int counter = 0;
					do
					{
						if (input[index] == '[')
							counter++;
						else if (input[index] == ']')
							counter--;
						index++;
					}
					while (counter);
					break;
				}
				case ']':
				{
					cout <<index<<" ] \""<<input<<"\" "<<endl;
					if (silly.getArrVal(silly.getIndex()) == 0)
					{
						cout <<"Ok "<<(int)silly.getArrVal(silly.getIndex())<<endl;
						index++;
						break;
					}
					int counter = 0;
					do
					{
						if (input[index] == '[')
							counter--;
						else if (input[index] == ']')
							counter++;
						index--;
					}
					while (counter);
					break;
				}
				default:
				{
					break;
				}
			}
		} while (index < input.length());
		inp.close();
		//mo.runProgram();
	}
	catch (exception &e)
	{
		cout <<e.what()<<endl;
	}
}