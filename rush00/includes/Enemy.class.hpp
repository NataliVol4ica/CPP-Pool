#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "defines.hpp"
#include "MovableItem.class.hpp"

class Enemy : public MovableItem
{
public:
	Enemy();
	Enemy(int type);
	Enemy(Enemy const &ref);
	~Enemy();

	Enemy &operator=(Enemy const &ref);

	typedef void (Enemy::*pathFunc)(void);
	typedef struct	s_enemy
	{
		int damage;
		int speed;
		int hp;
		pathFunc func;
	}				t_enemy;
	pathFunc moveFunc;

	int     move();

/* GETSET */
	int			getType(void) const;
	int			getDamage(void) const;
	int			getHP(void) const;
	pathFunc	getFunc(void) const;

	bool	is_this_you(int x, int y); //return true if yes
	bool	take_damage(int damage); //return true if died

private:
	int		type;
	int		damage;
	int		hp;
	int		sign;
	int		sinx;

	void	define_pathFunc(void);
//three movement funcs
	void	move_straight(void);
	void	move_diagonal(void);
	void	move_sinus(void);

	static t_enemy movements[];
};

#endif
/*
\
]=-
/
*/