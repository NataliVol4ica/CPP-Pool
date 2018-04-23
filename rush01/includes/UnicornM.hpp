// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UnicornM.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 17:20:32 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 17:20:34 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef UNICORNM_HPP
# define UNICORNM_HPP

# include <unistd.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include "IMonitorModule.hpp"
#include <iostream>

class UnicornM : public IMonitorModule {
	std::string const			name;
	struct Point2				size;
	std::vector<std::string>	info;
public:
	UnicornM(void);
	UnicornM(UnicornM const & ref);

	UnicornM &							operator=(UnicornM const & ref);
	std::string const &					getName(void) const;
	std::vector<std::string> const &	getInfo(void);
	Point2 const &						getSize(void) const;
	void								updateInfo(void);

	virtual ~UnicornM(void);
};

#endif
