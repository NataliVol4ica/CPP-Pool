#ifndef ENEMYCONTROLLER_CLASS_HPP
# define ENEMYCONTROLLER_CLASS_HPP


#include "defines.hpp"
#include "Enemy.class.hpp"
#include "MovableController.class.hpp"

typedef struct  s_enemies
{
    Enemy               enemy;
    struct s_enemies    *next;
}               t_enemies;

class EnemyController : public MovableController
{
public:
    EnemyController();
    EnemyController(EnemyController const & src);
    ~EnemyController();

    EnemyController &operator=(EnemyController const & src);

    int     move_all();
    int     check_collision(int x, int y);

    //get
    t_enemies *getEnemyList(void) const;

private:
    t_enemies *enemy_list;
    void    create_ship();
};


#endif