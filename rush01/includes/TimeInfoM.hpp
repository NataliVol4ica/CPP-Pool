// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TimeInfoM.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 18:51:47 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/14 22:17:31 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIMEINFOM_HPP
# define TIMEINFOM_HPP

# include <iostream>
# include <ctime>
# include "IMonitorModule.hpp"

class TimeInfoM : public IMonitorModule {
	std::string const			name;
	Point2						size;
	std::vector<std::string>	info;
public:
	TimeInfoM(void);
	TimeInfoM(TimeInfoM const & ref);

	TimeInfoM &							operator=(TimeInfoM const & ref);
	std::string const &					getName(void) const;
	std::vector<std::string> const &	getInfo(void);
	Point2 const &						getSize(void) const;
	void								updateInfo(void);

	virtual ~TimeInfoM(void);
};

#endif
