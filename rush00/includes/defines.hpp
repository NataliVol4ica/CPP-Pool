
#ifndef DEFINES_H
# define DEFINES_H

#include <iostream>
#include <iomanip>
#include <ncurses.h>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define getline std::getline
#define max(x, y) x < y ? y : x
#define min(x, y) x > y ? y : x

enum keys {UP = 0, DOWN, LEFT, RIGHT, SHOOT};


#endif

