#include "Mindopen.hpp"

Mindopen::Mindopen(void)
{
	this->size = ARRSIZE;
	this->index = 0;
	this->arr = new char[size];
	for (unsigned int i = 0; i < size; i++)
		this->arr[i] = 0;
}
Mindopen::Mindopen(unsigned int size)
{
	this->size = size;
	this->index = 0;
	this->arr = new char[size];
	for (unsigned int i = 0; i < size; i++)
		this->arr[i] = 0;
}

Mindopen::~Mindopen() {}

char*			Mindopen::getArr(void)const {return this->arr;}
char			Mindopen::getArrVal(unsigned int index) {return this->arr[index];}
void			Mindopen::setArrVal(char value) {this->arr[this->index] = value;}
unsigned int	Mindopen::getSize(void)const {return this->size;}
unsigned int	Mindopen::getIndex(void)const {return this->index;}
void			Mindopen::setIndex(unsigned int index) {this->index = index;}

void			Mindopen::addCommand(Op *newcmd)
{
	this->commands.push(newcmd);
}

void			Mindopen::runProgram(void)
{
	while (!this->commands.empty())
	{
		this->commands.front()->execute(this);
		this->commands.pop();
	}
}
