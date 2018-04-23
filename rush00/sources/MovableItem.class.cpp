#include "MovableItem.class.hpp"

MovableItem::MovableItem()
{
    this->speed = (arc4random_uniform(3) + 1) * 20000;
    this->last_movement = (std::chrono::system_clock::now().time_since_epoch()).count();
    this->pos_y = COLS - 3;
    this->pos_x = (rand() % (LINES - 3)) + 1;
   // mvprintw(this->pos_x, this->pos_y, "★");
}

MovableItem::MovableItem(MovableItem const &ref)
{
    *this = ref;
}

MovableItem::~MovableItem() {}

MovableItem &MovableItem::operator=(MovableItem const &ref)
{
    this->speed = ref.getSpeed();
    return *this;
}

/* GETSET */

int MovableItem::getSpeed(void) const {return this->speed;}
int MovableItem::getX(void) const {return this->pos_x;}
int MovableItem::getY(void) const {return this->pos_y;}

int MovableItem::move() {
    int ch;
    if (time_to_move())
    {
        ch = mvinch(this->pos_x, this->pos_y) & A_CHARTEXT;
        //if (ch == L'★')
        //getchar of a cur pos. if not a star || ' ' do nothing
            mvprintw( this->pos_x, this->pos_y, "  ");
        this->pos_y -= 1;
        if (this->pos_y <= 2)
            return 1;
        //getchar of a cur pos. if not a space do nothing
        ch = mvinch(this->pos_x, this->pos_y) & A_CHARTEXT;
        if (ch == ' ') {
            attron(COLOR_PAIR(5));
            mvprintw( this->pos_x, this->pos_y, "★");
            attroff(COLOR_PAIR(5));
        }
    }
    return 0;
}

bool    MovableItem::time_to_move(void)
{
    int current_time = (std::chrono::system_clock::now().time_since_epoch()).count();

    if (this->last_movement + this->speed < current_time)
    {
        this->last_movement = current_time;
        return true;
    }
    return false;
}
