// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPUInfoM.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 20:15:43 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/14 22:19:06 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CPUINFOM_HPP
# define CPUINFOM_HPP

# include <iostream>
# include "IMonitorModule.hpp"

class CPUInfoM : public IMonitorModule {
	std::string const			name;
	Point2						size;
	std::vector<std::string>	info;
public:
	CPUInfoM(void);
	CPUInfoM(CPUInfoM const & ref);

	CPUInfoM &							operator=(CPUInfoM const & ref);
	std::string const &					getName(void) const;
	std::vector<std::string> const &	getInfo(void);
	Point2 const &						getSize(void) const;
	void								updateInfo(void);

	virtual ~CPUInfoM(void);
};

#endif
