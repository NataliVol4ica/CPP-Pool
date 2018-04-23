// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 14:18:49 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 21:52:26 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include <iostream>
# include <string>

class IMonitorDisplay {
public:
	virtual void	displayAll() = 0; //run
	virtual ~IMonitorDisplay() = 0;
};

#endif
