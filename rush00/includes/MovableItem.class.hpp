#ifndef MOVABLEITEM_CLASS_HPP
# define MOVABLEITEM_CLASS_HPP

#include "defines.hpp"

class MovableItem
{
public:
	MovableItem();
	MovableItem(MovableItem const &ref);
	~MovableItem();

	MovableItem &operator=(MovableItem const &ref);

	int     move();
	bool    time_to_move(void); //true if time to move

	int		getSpeed(void) const;
	int 	getX(void) const;
	int 	getY(void) const;

protected:
	int		speed;
	int 	last_movement;
	int 	pos_x;
	int 	pos_y;
};

#endif
