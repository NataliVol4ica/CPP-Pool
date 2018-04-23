// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInfoM.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 15:31:52 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 14:41:02 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UserInfoM.hpp"

UserInfoM::UserInfoM(void) : name("User Info") {
	this->updateInfo();
}

UserInfoM::UserInfoM(UserInfoM const & ref) : name(ref.getName()), size(ref.getSize()) { }

UserInfoM &	UserInfoM::operator=(UserInfoM const & ref) {
	(void)ref;
	return *this;
}

std::string const &					UserInfoM::getName(void) const { return name; }

std::vector<std::string> const &	UserInfoM::getInfo(void) { return info; }

Point2 const &						UserInfoM::getSize(void) const { return size; }

void								UserInfoM::updateInfo(void) {
	char			hostname[1024];
	struct passwd	*pw;
	uid_t			uid;
	std::string		tmp;
	gethostname(hostname, 1024);
	uid = getuid();
	pw = getpwuid(uid);
	tmp = "\t";
	tmp += pw->pw_name;
	tmp += "@";
	tmp += hostname;
	size.x = tmp.length();
	size.y = 1;
	info.push_back(tmp);
}

UserInfoM::~UserInfoM(void) { }
