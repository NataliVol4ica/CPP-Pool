#include "Player.class.hpp"
#include "Bullet.hpp"

#include <string>

Player::Player(void)
{
	*this = Player("Unnamed player", 0, 0, 0, 0);
	this->index = Player::players - 1;
	bind_keys();
	set_startPos();
	this->bull_list = NULL;
}

Player::Player(const string &name, int bu, int bd, int bl, int br)
{
	this->index = Player::players++;
	this->name = name;
	this->hp = 100;
	this->borders[UP] = bu;
	this->borders[DOWN] = bd;
	this->borders[LEFT] = bl;
	this->borders[RIGHT] = br;
	bind_keys();
	set_startPos();
	this->last_time_shootet = (std::chrono::system_clock::now().time_since_epoch()).count();
	this->shooting_speed = 200000;
	this->bull_list = NULL;
	this->score = 0;
	this->lives = 3;
}

Player::Player(Player const &ref)
{
	*this = ref;
	this->index = Player::players++;
//	this->enemyController
	bind_keys();
	set_startPos();
	this->bull_list = NULL;
}
Player::~Player() {
}
	
Player &Player::operator=(Player const &ref)
{
	this->name = ref.getName();
	this->hp = ref.getHP();
	this->bull_list = ref.getBullList();
	return *this;
}

void	Player::set_startPos(void)
{

	mvprintw( 0, 1, " Player 0 | HP 100 | Lives 3 | SCORE 0 ");

//	this->icon  = "";




	this->x = (this->borders[LEFT] + this->borders[RIGHT]) / 2;
//	this->y = (this->borders[UP] + this->borders[DOWN]) / 2;

		this->y = 10;



	if (players == 1) {
        attron(COLOR_PAIR(1));

        mvprintw( this->x, this->y, "\\");
		mvprintw( this->x + 1, this->y, "]=-");
		mvprintw( this->x + 2, this->y, "/");
        attroff(COLOR_PAIR(1));

    }

}

void	Player::bind_keys(void)
{
	if (this->index == 0)
	{
		this->moveKeys[UP] = KEY_UP;
		this->moveKeys[DOWN] = KEY_DOWN;
		this->moveKeys[LEFT] = KEY_LEFT;
		this->moveKeys[RIGHT] = KEY_RIGHT;
		this->moveKeys[SHOOT] = 32;
	}
	else if (this->index == 1)
	{
		this->moveKeys[UP] = 6;
		this->moveKeys[DOWN] = 7;
		this->moveKeys[LEFT] = 8;
		this->moveKeys[RIGHT] = 9;
		this->moveKeys[SHOOT] = 10;
	}
}

void	Player::handleKey(int key)
{

//	for (int i = 0; i < 4; i++)
//		cout << this->moveKeys[i];

	if ( key == this->moveKeys[UP])
		move(-1, 0);
	else if (key == this->moveKeys[DOWN])
		move(1, 0);
	else if (key == this->moveKeys[LEFT]) {
		move(0, -1);
	}
	else if (key == this->moveKeys[RIGHT])
		move(0, 1);
	else if (key == this->moveKeys[SHOOT]) {
		this->shoot();
	}
}

void	Player::move(int x, int y)
{
	//set erase signal to the field

	mvprintw( this->x, this->y, " ");
	mvprintw( this->x + 1, this->y, "   ");
	mvprintw( this->x + 2, this->y, " ");

	this->x = max(this->borders[LEFT], min(this->x + x, this->borders[RIGHT]));
	this->y = max(this->borders[UP], min(this->y + y, this->borders[DOWN]));

	int ch = mvinch(this->x, this->y) & A_CHARTEXT;

	if  (ch != ' ' && ch != '+') {
		if (ch == '=') {
			this->attacked(10);
		}
	}


    attron(COLOR_PAIR(1));
	mvprintw( this->x, this->y, "\\");
	mvprintw( this->x + 1, this->y, "]=-");
	mvprintw( this->x + 2, this->y, "/");
    attroff(COLOR_PAIR(1));

	//set draw  signal to the field
}

void	Player::attacked(int amount)
{
	int new_hp = this->hp - amount;

	if (new_hp <= 0) {
		new_hp = 0;
//		this->die();
		return;
	}
	this->hp = new_hp;

	const string s = (std::to_string(this->hp));

	const char * c = s.c_str();

	mvprintw( 0, 16, " ");
	mvprintw( 0, 16, c);
}

void	Player::shoot() {
	int current_time = (std::chrono::system_clock::now().time_since_epoch()).count();

	if ( this->last_time_shootet + this->shooting_speed < current_time ) {

		t_bullets* bull = new t_bullets(this->x + 1, this->y + 3, 1, 20000, this->enemyController);

		bull->next = this->bull_list;

		this->bull_list = bull;
        
        system("afplay lazer.mp3 &");


		this->last_time_shootet = current_time;
	}


}

void	Player::updatePlayerInfo() {

	mvprintw( 0, 1, " Player %d | HP %d | Lives %d | SCORE %d ", this->index, this->hp, this->lives, this->score);
}

int		Player::moveBullets() {

	int ret = 0, temp;
	t_bullets *list = this->bull_list;
	t_bullets *prev = list;
	while (list) {


		if ((temp = list->bullet.move())){
			if (list == this->bull_list)
			{
				this->bull_list = list->next;
				delete list;
			}
			else {
				prev->next = list->next;
				delete list;
			}
		}
		if (temp != -1) {
			ret += temp;
		}
		prev = list;
		list = list->next;
	}
	this->score = this->score + ret;
	this->updatePlayerInfo();
	return ret;
}

/* ========== GET SET =========== */

string	Player::getName(void)const {return this->name;}
int 	Player::getIndex(void)const {return this->index;}
int 	Player::getHP(void)const {return this->hp;}
int		Player::getX(void) const {return this->x;}
int		Player::getY(void) const {return this->y;}
int		Player::getLives(void) const {return this->lives;}
const char *	Player::getIcon(void) const {return this->icon;}

void		Player::setLives(int amount) { this->lives = amount; }

t_bullets* 	Player::getBullList(void)const {return this->bull_list;}

void	Player::setEnemyController(EnemyController *ptr) {
	this->enemyController = ptr;
}

int Player::players = 0;