// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSInfoM.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 16:36:10 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 22:11:11 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OSInfoM.hpp"
#include <vector>

OSInfoM::OSInfoM(void) : name("OSinfo") {
	this->updateInfo();
}

OSInfoM::OSInfoM(OSInfoM const & ref) : name(ref.getName()), size(ref.getSize()) { }

OSInfoM &							OSInfoM::operator=(OSInfoM const & ref) {
	(void)ref;
	return *this;
}

std::string const &					OSInfoM::getName(void) const { return name; }

std::vector<std::string> const &	OSInfoM::getInfo(void) {
	updateInfo();
	return info; }

Point2 const &						OSInfoM::getSize(void) const { return size; }

void								OSInfoM::updateInfo(void) {
	char		buff[1024];
	FILE*		stream = popen("sw_vers", "r");
	std::string	tmp;
	info.clear();
	size.y = 0;
	size.x = 0;
	for (int i = 0; !feof(stream); i++) {
		if ( fgets (buff , 1024 , stream) == NULL ) break;
		tmp = "\t";
		tmp += buff;
		tmp = tmp.substr(0, tmp.size() - 1);
		tmp.insert(i == 2 ? 6 : 8, " ");
		if(i == 2) tmp.insert(15, "\t");
		info.push_back(tmp);
		if (size.x < tmp.length()) size.x = tmp.length();
		size.y++;
	}
	pclose(stream);
}

OSInfoM::~OSInfoM(void) { }
