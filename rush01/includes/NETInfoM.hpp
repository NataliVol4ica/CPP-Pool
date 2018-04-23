// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NETInfoM.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 11:49:58 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 15:51:45 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NETINFOM_HPP
# define NETINFOM_HPP

# include <iostream>
# include "IMonitorModule.hpp"

class NETInfoM : public IMonitorModule {
	std::string const			name;
	Point2						size;
	std::vector<std::string>	info;
public:
	NETInfoM(void);
	NETInfoM(NETInfoM const & ref);

	NETInfoM &							operator=(NETInfoM const & ref);
	std::string const &					getName(void) const;
	std::vector<std::string> const &	getInfo(void);
	Point2 const &						getSize(void) const;
	void								updateInfo(void);

	virtual ~NETInfoM(void);
};

#endif
