#ifndef MOVABLECONTROLLER_CLASS_HPP
# define MOVABLECONTROLLER_CLASS_HPP


#include "defines.hpp"
#include "MovableItem.class.hpp"

typedef struct  s_movables
{
    MovableItem         movable;
    struct s_movables   *next;
}               t_movables;

class MovableController
{
public:
    MovableController();
    MovableController(MovableController const & src);
    ~MovableController();

    MovableController &operator=(MovableController const & src);

    int     move_all();

    //get
    t_movables *getMovableList(void) const;

private:
    t_movables  *movable_list;
    void        create_movable();

protected:
    int     last_created;
    int     delta;

};


#endif