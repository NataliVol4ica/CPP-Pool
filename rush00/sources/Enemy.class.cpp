#include "Enemy.class.hpp"
#include "Bullet.hpp"
#include <cmath>

Enemy::t_enemy Enemy::movements[] =
{
    {10, 50000, 1, &Enemy::move_straight},
    {20, 200000, 2, &Enemy::move_diagonal},
    {25, 100000, 1, &Enemy::move_sinus}
};

Enemy::Enemy()
{
    this->pos_y = COLS - 2;
    this->pos_x = (rand() % (LINES - 3)) + 1;
    this->last_movement = (std::chrono::system_clock::now().time_since_epoch()).count();
    this->type = arc4random_uniform(100);
    define_pathFunc();
    attron(COLOR_PAIR(this->hp));
    mvprintw( this->pos_x, this->pos_y, "@");
    attroff(COLOR_PAIR(this->hp));

}

Enemy::Enemy(int type)
{
    this->pos_y = 200;
    this->pos_x = 10;
    this->last_movement = (std::chrono::system_clock::now().time_since_epoch()).count();
    this->type = type;
    define_pathFunc();
    attron(COLOR_PAIR(this->hp));
    mvprintw( this->pos_x, this->pos_y, "@");
    attroff(COLOR_PAIR(this->hp));
}

Enemy::Enemy(Enemy const &ref)
{
    *this = ref;
}

Enemy::~Enemy() {}

Enemy &Enemy::operator=(Enemy const &ref)
{
    this->type = ref.getType();
    this->damage = ref.getDamage();
    this->speed = ref.getSpeed();
    this->hp = ref.getHP();
    this->pos_y = ref.getY();
    this->pos_x = ref.getX();
    this->moveFunc = ref.getFunc();
    return *this;
}

/* GETSET */

int				Enemy::getType(void) const {return this->type;}
int				Enemy::getDamage(void) const {return this->damage;}
int				Enemy::getHP(void) const {return this->hp;}


Enemy::pathFunc	Enemy::getFunc(void) const {return this->moveFunc;}

/* HP */
bool    Enemy::is_this_you(int x, int y)
{
    if (this->pos_x == x && this->pos_y == y)
        return (true);
    return false;
}

bool     Enemy::take_damage(int damage)
{
    //erase old icon

    mvprintw( this->pos_x, this->pos_y, " ");
    this->hp -= damage;
    if (this->hp <= 0)
        return true;
    //draw new icon with different color
    attron(COLOR_PAIR(this->hp + 1));
    mvprintw( this->pos_x, this->pos_y, "@");
    attroff(COLOR_PAIR(this->hp + 1));

    return false;
}

/* MOVEMENT */

void	Enemy::define_pathFunc(void)
{
    if (this->type < 60)
        this->type = 0;
    else if (this->type < 80)
        this->type = 1;
    else this->type = 2;
    if (this->type == 1)
    {
        if (this->pos_x < 6) this->pos_x = 6;
        if (this->pos_x > LINES - 6) this->pos_x = LINES - 6;
    }
    else if (this->type == 2)
    {
        if (this->pos_x < 8) this->pos_x = 8;
        if (this->pos_x > LINES - 8) this->pos_x = LINES - 8;
    }
    this->moveFunc = Enemy::movements[this->type].func;
    this->damage = Enemy::movements[this->type].damage;
    this->speed = Enemy::movements[this->type].speed;
    this->hp = Enemy::movements[this->type].hp;
    this->sign = -1;
    this->sinx = this->pos_x;
}


int Enemy::move() {
    char ch = mvinch(this->pos_x, this->pos_y) & A_CHARTEXT;
    if (ch == '=' || ch == '\\' || ch == '/' || ch == ']' || ch == '-')
        return 2;
    if (time_to_move()) {
        mvprintw( this->pos_x, this->pos_y, " ");
        (this->*moveFunc)();
        if (this->pos_y <= 2)
        {
//            mvprintw( this->pos_x, this->pos_y, " ");
            return 1;
        }
        ch = mvinch(this->pos_x, this->pos_y) & A_CHARTEXT;
        if (ch == '=' || ch == '\\' || ch == '/' || ch == ']' || ch == '-') {
            return 2;

    }
    }
    attron(COLOR_PAIR(this->hp + 1));
    mvprintw( this->pos_x, this->pos_y, "@");
    attroff(COLOR_PAIR(this->hp + 1));
    return 0;
}


void	Enemy::move_straight(void)
{
    this->pos_y -= 1;

}

void	Enemy::move_diagonal(void)
{
    this->pos_y -= 1;
    this->pos_x -= this->sign * (this->pos_y % 2);
    if (this->pos_x <= 5) {
        this->sign = -this->sign;
        this->pos_x = 6;}
    else if (this->pos_x >= LINES - 5){
        this->sign = -this->sign;
        this->pos_x = LINES - 6;
    }
}

void	Enemy::move_sinus(void)
{
    float ssin;

    this->pos_y -= 1;
    ssin = sin((float)(this->pos_y) / 5);
    //cout << ssin;
    this->pos_x = this->sinx + (float)((float)6 * (float)ssin);
}
