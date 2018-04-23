// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TermGraphics.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 18:59:09 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 21:21:26 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TERMGRAPHICS_HPP
# define TERMGRAPHICS_HPP

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include "UserInfoM.hpp"
# include "OSInfoM.hpp"
# include "TimeInfoM.hpp"
# include "CPUInfoM.hpp"
# include "RAMInfoM.hpp"
# include "NETInfoM.hpp"
# include "UnicornM.hpp"

# include <iostream>
# include <string>
# include <vector>
# include <ncurses.h>

class TermGraphics : public IMonitorDisplay {
	int		_w_height;
	int		_w_width;
	std::vector<IMonitorModule*> moduleInst;
public:
	TermGraphics(void);
	TermGraphics(TermGraphics const & ref);
	TermGraphics &	operator=(TermGraphics const & ref);
	void			displayAll(void);
	int				drawModul(IMonitorModule* mod, bool isd, int stp);
	virtual ~TermGraphics(void);
};

#endif
