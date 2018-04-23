// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSInfoM.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 16:31:53 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/14 22:17:09 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OSINFOM_HPP
# define OSINFOM_HPP

# include <sys/utsname.h>
# include <iostream>
# include "IMonitorModule.hpp"

class OSInfoM : public IMonitorModule {
	std::string const			name;
	Point2						size;
	std::vector<std::string>	info;
public:
	OSInfoM(void);
	OSInfoM(OSInfoM const & ref);

	OSInfoM &							operator=(OSInfoM const & ref);
	std::string const &					getName(void) const;
	std::vector<std::string> const &	getInfo(void);
	Point2 const &						getSize(void) const;
	void								updateInfo(void);

	virtual ~OSInfoM(void);
};

#endif
