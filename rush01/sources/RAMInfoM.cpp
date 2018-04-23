// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMInfoM.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 11:53:56 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 22:06:36 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <cmath>
#include "RAMInfoM.hpp"

RAMInfoM::RAMInfoM(void) : name("RAM Info") {
	this->updateInfo();
}

RAMInfoM::RAMInfoM(RAMInfoM const & ref)
	: name(ref.getName()), size(ref.getSize()) { }

RAMInfoM &							RAMInfoM::operator=(RAMInfoM const & ref) {
	(void)ref;
	return *this;
}

std::string const &					RAMInfoM::getName(void) const { return name; }

std::vector<std::string> const &	RAMInfoM::getInfo(void) {
	static int	timing = 0;
	if (timing == 50) {
		updateInfo();
		timing = 0;
	}
	else timing++;
	return info;
}

Point2 const &						RAMInfoM::getSize(void) const { return size; }

void								RAMInfoM::updateInfo(void) {
	size.y = 0;
	size.x = 0;
	info.clear();
	vm_size_t				page_size;
	mach_port_t				mach_port;
	mach_msg_type_number_t	count;
	vm_statistics64_data_t	vm_stats;
	std::string				tmp;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
										  reinterpret_cast<host_info64_t>(&vm_stats), &count))
	{
		long double free_memory = static_cast<int64_t>(vm_stats.free_count) * static_cast<int64_t>(page_size);
        long double used_memory = (static_cast<int64_t>(vm_stats.active_count) +
								   static_cast<int64_t>(vm_stats.inactive_count) +
								   static_cast<int64_t>(vm_stats.wire_count)) *  static_cast<int64_t>(page_size);

		tmp = "\tTotal memory: \t";
		tmp += std::to_string(static_cast<long>(free_memory + used_memory) / (1024 * 1024));
		tmp += " MBs";
		info.push_back(tmp);
		if (size.x < tmp.length()) size.x = tmp.length();
		size.y++;
        tmp = "\tFree memory: \t";
		tmp += std::to_string(static_cast<int>(free_memory / (1024.0 * 1024.0)));
		tmp += " MBs";
		info.push_back(tmp);
		if (size.x < tmp.length()) size.x = tmp.length();
		size.y++;
		tmp = "\tUsed memory:\t";
		tmp += std::to_string(static_cast<int>(used_memory / (1024.0 * 1024.0)));
		tmp += " MBs";
		info.push_back(tmp);
		if (size.x < tmp.length()) size.x = tmp.length();
		size.y++;
		tmp = "\tUsage:\t\t";
		tmp += std::to_string(static_cast<int>(std::round((used_memory / (used_memory + free_memory)) * 100)));
		tmp += "%";
		info.push_back(tmp);
		if (size.x < tmp.length()) size.x = tmp.length();
		size.y++;
    }
	else {
		tmp = "Error!";
		info.push_back(tmp);
		size.x = tmp.length();
		size.y++;
	}
}

RAMInfoM::~RAMInfoM(void) { }
