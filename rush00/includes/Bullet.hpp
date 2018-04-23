#ifndef BULLET_H
# define BULLET_H

#include <iostream>
#include <ncurses.h>

#include "EnemyController.class.hpp"

class Bullet {
private:
    int dmg;
    int pos_x;
    int pos_y;
    int speed;
    int last_time_moved;
    EnemyController *enemyController;

protected:

public:
    Bullet();
    Bullet(int x, int y, int dmg, int speed, EnemyController *ptr);
    ~Bullet();

    Bullet &operator=(Bullet const & src);

    int move();

    //get
    int getDmg(void) const;
    int getX(void) const;
    int getY(void) const;
    int getSpeed(void) const;
    int getLastTimeMoved(void) const;
    EnemyController* getEnemyController(void) const;
};



typedef struct s_bullets {
    Bullet bullet;
    struct s_bullets *next;
    s_bullets (int x, int y, int dmg, int speed, EnemyController *ptr);
} t_bullets;



#endif