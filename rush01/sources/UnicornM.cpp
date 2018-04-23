// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UnicornM.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 17:10:57 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 17:23:03 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UnicornM.hpp"

UnicornM::UnicornM(void) : name("Amazing Unicorn") {
	this->updateInfo();
}

UnicornM::UnicornM(UnicornM const & ref) : name(ref.getName()), size(ref.getSize()) { }

UnicornM &	UnicornM::operator=(UnicornM const & ref) {
	(void)ref;
	return *this;
}

std::string const &					UnicornM::getName(void) const { return name; }

std::vector<std::string> const &	UnicornM::getInfo(void) { return info; }

Point2 const &						UnicornM::getSize(void) const { return size; }

void								UnicornM::updateInfo(void) {
	info.clear();
	size.y = 9;
	size.x = 22;
	std::string		tmp;
	tmp = "\t                   n";
	info.push_back(tmp);
	tmp = "\t        |\\   |  or";
	info.push_back(tmp);
	tmp = "\t       _| \\-/ic";
	info.push_back(tmp);
	tmp = "\t      /    un";
	info.push_back(tmp);
	tmp = "\t    //    ~ + \\";
	info.push_back(tmp);
	tmp = "\t   //         |";
	info.push_back(tmp);
	tmp = "\t  //    \\      \\";
	info.push_back(tmp);
	tmp = "\t |||     | .  .|";
	info.push_back(tmp);
	tmp = "\t///     / \\___/";
	info.push_back(tmp);
}

UnicornM::~UnicornM(void) { }
