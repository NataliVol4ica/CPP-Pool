
#include "EnemyController.class.hpp"

EnemyController::EnemyController() {
    this->last_created = (std::chrono::system_clock::now().time_since_epoch()).count();
}

EnemyController::EnemyController(EnemyController const &src) {
    this->enemy_list = src.getEnemyList();
}

EnemyController&   EnemyController::operator=(EnemyController const &src) {
    this->enemy_list = src.getEnemyList();
    return  (*this);
}

EnemyController::~EnemyController() {}


void EnemyController::create_ship() {

    t_enemies *enemy = new t_enemies;
    enemy->next = this->enemy_list;
    this->enemy_list = enemy;
}

t_enemies *EnemyController::getEnemyList(void) const {
    return this->enemy_list;
}

int EnemyController::move_all() {
    int current_time = (std::chrono::system_clock::now().time_since_epoch()).count();
    int ret;

    if ( this->last_created + 1000000 < current_time ) {

        this->last_created = current_time;
        this->create_ship();
    }
    t_enemies *list = this->enemy_list;
    t_enemies *prev = list;

    while (list) {
        if ((ret = list->enemy.move())) {
            if (list == this->enemy_list)
            {
                this->enemy_list = list->next;
                delete list;
            }
            else {
                prev->next = list->next;
                delete list;
            }
            return (ret == 1 ? 0 : 1);
        }

    prev = list;
    list = list->next;
    }
    return 0;
}

int EnemyController::check_collision(int x, int y) {

    t_enemies *list = this->enemy_list;
    t_enemies *prev = list;

    while (list) {

        if (list->enemy.is_this_you(x, y))
        {
            if (list->enemy.take_damage(1)) {

                if (list == this->enemy_list)
                {
                    this->enemy_list = list->next;
                    delete list;
                }
                else {
                    prev->next = list->next;
                    delete list;
                }
                return (0);
            }
        }
        prev = list;
        list = list->next;
    }

    return 0;
}
