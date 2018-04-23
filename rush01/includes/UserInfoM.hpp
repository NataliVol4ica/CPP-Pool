// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInfoM.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 15:21:00 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/14 22:17:57 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef USERINFOM_HPP
# define USERINFOM_HPP

# include <unistd.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include "IMonitorModule.hpp"
#include <iostream>

class UserInfoM : public IMonitorModule {
	std::string const			name;
	struct Point2				size;
	std::vector<std::string>	info;
public:
	UserInfoM(void);
	UserInfoM(UserInfoM const & ref);

	UserInfoM &							operator=(UserInfoM const & ref);
	std::string const &					getName(void) const;
	std::vector<std::string> const &	getInfo(void);
	Point2 const &						getSize(void) const;
	void								updateInfo(void);

	virtual ~UserInfoM(void);
};

#endif
