// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NETInfoM.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 11:53:56 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 21:59:12 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>
#include <ctime>
#include "NETInfoM.hpp"

NETInfoM::NETInfoM(void) : name("NET Info") {
	this->updateInfo();
}

NETInfoM::NETInfoM(NETInfoM const & ref)
	: name(ref.getName()), size(ref.getSize()) { }

NETInfoM &							NETInfoM::operator=(NETInfoM const & ref) {
	(void)ref;
	return *this;
}

std::string const &					NETInfoM::getName(void) const { return name; }

std::vector<std::string> const &	NETInfoM::getInfo(void) {
	static time_t	t = time(NULL);
	if (t <= time(NULL) - 1) {
		updateInfo();
		t = time(NULL);
	}
	return info;
}

Point2 const &						NETInfoM::getSize(void) const { return size; }

void								NETInfoM::updateInfo(void) {
	size.y = 0;
	size.x = 0;
	info.clear();
	static u_int64_t	lasti = 0;
	static u_int64_t	lasto = 0;
	int mib[] = {
        CTL_NET,
        PF_ROUTE,
        0,
        0,
        NET_RT_IFLIST2,
        0
    };
	size_t	len;
	sysctl(mib, 6, NULL, &len, NULL, 0);
	char	*buf = new char[len];
	sysctl(mib, 6, buf, &len, NULL, 0);
	char	*next = NULL;
	u_int64_t totalibytes = 0;
    u_int64_t totalobytes = 0;
	for (next = buf; next < buf + len; ) {
        struct if_msghdr *ifm = reinterpret_cast<struct if_msghdr*>(next);
        next += ifm->ifm_msglen;
        if (ifm->ifm_type == RTM_IFINFO2) {
            struct if_msghdr2 *if2m = reinterpret_cast<struct if_msghdr2*>(ifm);
            totalibytes += if2m->ifm_data.ifi_ibytes;
            totalobytes += if2m->ifm_data.ifi_obytes;
        }
    }
	std::string	tmp = "\tTrafic IN:  \t";
	tmp += std::to_string((totalibytes - lasti) / 1024);
	tmp += " KB/s";
	info.push_back(tmp);
	size.y++;
	if (size.x < tmp.length()) size.x = tmp.length();
	tmp = "\tTrafic OUT:\t";
	tmp += std::to_string((totalobytes - lasto) / 1024);
	tmp += " KB/s";
	info.push_back(tmp);
	size.y++;
	if (size.x < tmp.length()) size.x = tmp.length();
	lasti = totalibytes;
	lasto = totalobytes;
	delete[] buf;
}

NETInfoM::~NETInfoM(void) { }
