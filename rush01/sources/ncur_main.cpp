// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ncur_main.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/15 21:12:48 by ahrytsen          #+#    #+#             //
//   Updated: 2018/04/15 21:21:06 by ahrytsen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TermGraphics.hpp"

int		ncur_main(void)
{
	TermGraphics *ncurDraw = new TermGraphics();
	ncurDraw->displayAll();
	delete ncurDraw;
	return 0;
}
