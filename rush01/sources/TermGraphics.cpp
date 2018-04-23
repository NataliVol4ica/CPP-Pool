// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TermGraphics.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 19:02:04 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 22:54:24 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TermGraphics.hpp"

TermGraphics::TermGraphics(void) {
	moduleInst.push_back(new UserInfoM());
	moduleInst.push_back(new OSInfoM());
	moduleInst.push_back(new TimeInfoM());
	moduleInst.push_back(new CPUInfoM());
	moduleInst.push_back(new RAMInfoM());
	moduleInst.push_back(new NETInfoM());
	moduleInst.push_back(new UnicornM());
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	getmaxyx(stdscr, _w_height, _w_width);
}

TermGraphics::TermGraphics(TermGraphics const & ref)
	: _w_height(ref._w_height), _w_width(ref._w_width) {
	for (std::size_t i = 0; i < ref.moduleInst.size(); i++)
		moduleInst.push_back(ref.moduleInst[i]);
}

TermGraphics &	TermGraphics::operator=(TermGraphics const & ref) {
	_w_height = ref._w_height;
	_w_width = ref._w_width;
	moduleInst.clear();
	for (std::size_t i = 0; i < ref.moduleInst.size(); i++)
		moduleInst.push_back(ref.moduleInst[i]);
	return *this;
}

void			TermGraphics::displayAll(void) {
	char key;
	bool* menu = new bool[moduleInst.size()]();
	while ((key = getch()) != 'q')
	{
		int stp = 0;
		clear();
		if (key - '0' > 0 && key - '0' <= static_cast<int>(moduleInst.size()))
			menu[key - '0' - 1] = !menu[key - '0' - 1];
		for (std::size_t i = 0; i < moduleInst.size(); i++)
			stp = drawModul(moduleInst[i], menu[i], stp);
		getmaxyx(stdscr, _w_height, _w_width);
	}
}

int				TermGraphics::drawModul(IMonitorModule* mod, bool isd, int stp)
{
	std::vector<std::string> info;

	info = mod->getInfo();

	if(!stp) {
		attron(COLOR_PAIR(4) | A_BOLD);
		mvprintw(stp++, 35, "FT_GKrelM");
		attroff(COLOR_PAIR(4) | A_BOLD);
		attron(COLOR_PAIR(3));
		mvprintw(stp++, 0, "|=======================|-------------------------------------------------------|");
		attroff(COLOR_PAIR(3));
	}
	for (size_t i = 0; i < info.size(); i++, stp++) {
		attron(COLOR_PAIR(3));
		mvprintw(stp, 0, "|");
		attroff(COLOR_PAIR(3));
		if(info.size() / 2 == i) {
			attron(COLOR_PAIR(2) | A_BOLD);
			mvprintw(stp, 3, "%s", mod->getName().c_str());
			attroff(COLOR_PAIR(2) | A_BOLD);
		}
		attron(COLOR_PAIR(3));
		mvprintw(stp, 24, "|");
		attroff(COLOR_PAIR(3));
		if (isd) {
			attron(COLOR_PAIR(1));
			mvprintw(stp, 25, "%s", info[i].c_str());
			attroff(COLOR_PAIR(1));
		}
		attron(COLOR_PAIR(3));
		mvprintw(stp, 80, "|");
		attroff(COLOR_PAIR(3));
	}
	attron(COLOR_PAIR(3));
	mvprintw(stp++, 0, "|=======================|-------------------------------------------------------|");
	attron(COLOR_PAIR(3));
	return stp;
}

TermGraphics::~TermGraphics(void){
	endwin();
}
