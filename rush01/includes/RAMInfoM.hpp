// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAMInfoM.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 11:49:58 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 11:52:50 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAMINFOM_HPP
# define RAMINFOM_HPP

# include <iostream>
# include "IMonitorModule.hpp"

class RAMInfoM : public IMonitorModule {
	std::string const			name;
	Point2						size;
	std::vector<std::string>	info;
public:
	RAMInfoM(void);
	RAMInfoM(RAMInfoM const & ref);

	RAMInfoM &							operator=(RAMInfoM const & ref);
	std::string const &					getName(void) const;
	std::vector<std::string> const &	getInfo(void);
	Point2 const &						getSize(void) const;
	void								updateInfo(void);

	virtual ~RAMInfoM(void);
};

#endif
