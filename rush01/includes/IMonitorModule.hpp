// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 13:45:53 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/14 22:16:09 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
#include <iostream>
#include <vector>

struct Point2 {
	std::size_t	x;
	std::size_t	y;
};

class IMonitorModule {
public:
	virtual std::string const &					getName(void) const = 0;
	virtual std::vector<std::string> const &	getInfo(void) = 0;
	virtual Point2 const &						getSize(void) const = 0;
};

#endif
