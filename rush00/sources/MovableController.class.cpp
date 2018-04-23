
#include "MovableController.class.hpp"

MovableController::MovableController() {
    this->last_created = (std::chrono::system_clock::now().time_since_epoch()).count();
    this->movable_list = NULL;
    this->delta = ((arc4random_uniform(20) + 5) * 10000);
}

MovableController::MovableController(MovableController const &src) {
    *this = src;
}

MovableController&   MovableController::operator=(MovableController const &src)
{
    this->movable_list = src.getMovableList();
    return  (*this);
}

MovableController::~MovableController() {}


void MovableController::create_movable() {
    t_movables *movable = new t_movables;
    movable->next = this->movable_list;
    this->movable_list = movable;
}

t_movables *MovableController::getMovableList(void) const {return this->movable_list;}

int  MovableController::move_all() {
    int current_time = (std::chrono::system_clock::now().time_since_epoch()).count();

    //cout<<this->delta;
    if ( this->last_created + this->delta < current_time ) {

        this->last_created = current_time;
        this->create_movable();
        this->delta = ((arc4random_uniform(20) + 5) * 10000);
    }

    t_movables *list = this->movable_list;
    t_movables *prev = list;

    while (list) {
        if (list->movable.move()) {
            if (list == this->movable_list)
            {
                this->movable_list = list->next;
                delete list;
            }
            else {
                prev->next = list->next;
                delete list;
            }
            return (0);
        }

    prev = list;
    list = list->next;
    }

    return 0;
}
