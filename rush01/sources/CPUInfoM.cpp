// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUInfoM.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 20:50:28 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 14:47:20 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sys/types.h>
#include <sys/sysctl.h>
#include "CPUInfoM.hpp"

CPUInfoM::CPUInfoM(void) : name("CPU Info") {
	this->updateInfo();
}

CPUInfoM::CPUInfoM(CPUInfoM const & ref)
	: name(ref.getName()), size(ref.getSize()) { }

CPUInfoM &							CPUInfoM::operator=(CPUInfoM const & ref) {
	(void)ref;
	return *this;
}

std::string const &					CPUInfoM::getName(void) const { return name; }

std::vector<std::string> const &	CPUInfoM::getInfo(void) {
	static int	timing = 0;
	if (timing == 50) {
		updateInfo();
		timing = 0;
	}
	else timing++;
	return info;
}

Point2 const &						CPUInfoM::getSize(void) const { return size; }

void								CPUInfoM::updateInfo(void) {
	size.y = 0;
	size.x = 0;
	info.clear();
	int		tmp_int;
	//long	tmp_long;
	char	tmp_str[1024];
	std::size_t	len = sizeof(tmp_str);
	sysctlbyname("machdep.cpu.brand_string", tmp_str, &len, NULL, 0);
	std::string	tmp = "\t";
	tmp += tmp_str;
	info.push_back(tmp);
	if (size.x < tmp.length()) size.x = tmp.length();
	size.y++;

	len = sizeof(tmp_int);
	sysctlbyname("machdep.cpu.core_count", &tmp_int, &len, NULL, 0);
	tmp = "\tCores: ";
	tmp += std::to_string(tmp_int);
	info.push_back(tmp);
	if (size.x < tmp.length()) size.x = tmp.length();
	size.y++;


	FILE*		stream = popen("top -l 1 | head -n 10 | grep CPU | cut -d' ' -f 2-", "r");
	while (!feof(stream)) {
		if ( fgets (tmp_str , 1024 , stream) == NULL ) break;
		tmp = "\t";
		tmp += tmp_str;
		tmp = tmp.substr(0, tmp.size() - 1);
		info.push_back(tmp);
		if (size.x < tmp.length()) size.x = tmp.length();
		size.y++;
	}
	pclose(stream);
}

CPUInfoM::~CPUInfoM(void) { }
