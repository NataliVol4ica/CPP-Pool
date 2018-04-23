#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

#include "defines.hpp"
#include "EnemyController.class.hpp"
#include "Bullet.hpp"

class Player
{
public:
	Player();
	Player(const string &name, int bu, int bd, int bl, int br);
	Player(Player const &ref);
	~Player();
	
	Player &operator=(Player const &ref);

/* GET SET */

	string	getName(void)const;
	int 	getIndex(void)const;
	int 	getHP(void)const;
	t_bullets* 	getBullList(void) const;
	int		getX(void) const;
	int		getY(void) const;
	int 	getLives(void) const;
	void		setLives(int amount);
    const char * getIcon(void) const;

	void	handleKey(int key);
	int	moveBullets();

	void	setEnemyController(EnemyController *ptr);
	void	updatePlayerInfo();


private:
	string	name;
	int		index;
	int		hp;
	int		moveKeys[5];
	int		borders[4];
	int		score;
	int		lives;
    const char *icon;
	int		x, y;
	static int players; // num of players
	t_bullets *bull_list;
	int last_time_shootet;
	int shooting_speed;
	EnemyController *enemyController;

	void	bind_keys(void);
	void	set_startPos(void);
	void	move(int x, int y);
	void	shoot();
	void	attacked(int amount);

};

#endif