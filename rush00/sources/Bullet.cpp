#include "Bullet.hpp"


Bullet::Bullet() {}

Bullet::Bullet(int x, int y, int dmg, int speed, EnemyController *ptr) {

    this->dmg = dmg;
    this->pos_x = x;
    this->pos_y = y;
    this->last_time_moved = (std::chrono::system_clock::now().time_since_epoch()).count();
    this->speed = speed;
    this->enemyController = ptr;
}

Bullet & Bullet::operator=(Bullet const & src) {

    this->dmg = src.getDmg();
    this->pos_x = src.getX();
    this->pos_y = src.getY();
    this->last_time_moved = src.getLastTimeMoved();
    this->speed = src.getSpeed();
    this->enemyController = src.getEnemyController();

    this->dmg = src.getDmg();

    return *this;
}

Bullet::~Bullet() {
}

int Bullet::move() {
    char ch2 = mvinch(this->pos_x, this->pos_y) & A_CHARTEXT;

    if (ch2 == '@') {
        mvprintw( this->pos_x, this->pos_y, " ");
        this->enemyController->check_collision(this->pos_x, this->pos_y);
        return (1);
    } int current_time = (std::chrono::system_clock::now().time_since_epoch()).count();

    if ( this->last_time_moved + this->speed < current_time ) {
        mvprintw( this->pos_x, this->pos_y, " ");
        this->last_time_moved = current_time;
        this->pos_y += 1;

        if (this->pos_y == COLS - 2) {
            return (-1);
        }

		char ch = mvinch(this->pos_x, this->pos_y) & A_CHARTEXT;

		if (ch == '@') {
            this->enemyController->check_collision(this->pos_x, this->pos_y);
			return (1);
		}


        attron(COLOR_PAIR(4));
        mvprintw( this->pos_x, this->pos_y, "+");
        attroff(COLOR_PAIR(4));

    }

    return 0;
}
//
int     Bullet::getDmg(void) const                { return (this->dmg); }
int     Bullet::getX(void) const                  { return (this->pos_x); }
int     Bullet::getY(void) const                  { return (this->pos_y); }
int     Bullet::getSpeed(void) const              { return (this->speed); }
int     Bullet::getLastTimeMoved(void) const      { return (this->last_time_moved); }
EnemyController*     Bullet::getEnemyController(void) const  { return (this->enemyController); }

t_bullets::s_bullets(int x, int y, int dmg, int speed, EnemyController *ptr)
{
    this->bullet = Bullet(x, y, dmg, speed, ptr);
    this->next = NULL;
}