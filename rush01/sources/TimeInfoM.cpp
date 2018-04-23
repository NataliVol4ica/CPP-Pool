// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeInfoM.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 18:45:58 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 14:41:42 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TimeInfoM.hpp"

TimeInfoM::TimeInfoM(void) : name("Time Info") {
	this->updateInfo();
}

TimeInfoM::TimeInfoM(TimeInfoM const & ref)
	: name(ref.getName()), size(ref.getSize()) { }

TimeInfoM &							TimeInfoM::operator=(TimeInfoM const & ref) {
	(void)ref;
	return *this;
}

std::string const &					TimeInfoM::getName(void) const { return name; }

std::vector<std::string> const &	TimeInfoM::getInfo(void) {
	this->updateInfo();
	return info;
}

Point2 const &						TimeInfoM::getSize(void) const { return size; }

void								TimeInfoM::updateInfo(void) {
	size.y = 1;
	size.x = 26;
	info.clear();
	time_t		cur = time(nullptr);
	std::string	tmp = "\t";
	tmp += ctime(&cur);
	info.push_back(tmp.substr(0, tmp.size() - 1));
}

TimeInfoM::~TimeInfoM(void) { }
