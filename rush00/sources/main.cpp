
#include <ncurses.h>
#include <iostream>
#include <unistd.h>

#include <ncurses.h>
#include "Bullet.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"
#include "EnemyController.class.hpp"
#include "MovableController.class.hpp"


WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);


void ft_move_start(int *star_pos_y, int  *star_pos_x, const char* star ) {
	mvprintw(*star_pos_x, *star_pos_y, " ");
	*star_pos_x += 1;
	mvprintw(*star_pos_x, *star_pos_y, star);
}

void ft_handle_press_key(Player &p, WINDOW *my_win) {

	int ch=getch();

    if (ch == 27) {
        destroy_win(my_win);
        exit(0);
    }

	p.handleKey(ch);

	refresh();
	timeout(1);

}


void ft_print_borders() {
    int i =  0;

    while (i < COLS) {
        mvprintw( 0, i, "-");
        mvprintw( LINES - 1, i, "-");
        i++;
    }

    i = 0;

    while (i < LINES) {
        const char*  b = "|";
        mvprintw( i, 0, b );
        mvprintw( i, COLS - 1, "|" );
        i++;
    }

    mvprintw( 0, 0, "┌" );
    mvprintw( 0, COLS - 1, "┐" );
    mvprintw( LINES - 1, 0, "└" );
    mvprintw( LINES - 1, COLS - 1, "┘" );



    refresh();
}


void    ft_display_menu(WINDOW * my_win) {
    clear();
    ft_print_borders();

    mvprintw(LINES / 2 - 3 ,  COLS / 2 - 10, "Press 'Any' key to play");
    mvprintw(LINES / 2 - 1 ,  COLS / 2 - 10, "Press 'ESQ' key to exit");


    int ch = getch();



    if (ch == 27) {
        destroy_win(my_win);
        exit(0);

    }
    clear();

}


int main()
{
    setlocale(LC_ALL, "");
//	Creating ncurses window
	WINDOW *my_win;
	int startx, starty, width, height;
	int usleep (useconds_t usec);
	keypad(stdscr, true);
	halfdelay(100);
	nodelay(stdscr,true);

    initscr();

	cbreak();


	height = LINES;
	width = COLS;
	starty = (0);
	startx = (0);


	refresh();
	my_win = create_newwin(height, width, starty, startx);
	noecho();
	refresh();
    raw();
	curs_set(0);

	keypad(stdscr,true);

	start_color();

	init_color(COLOR_MAGENTA, 1000, 650, 360);
	init_color(COLOR_BLUE, 0, 1000, 1000);
	init_color(COLOR_YELLOW, 300, 300, 300);
    init_color(COLOR_RED, 1000, 200, 0);


	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);


	ft_display_menu(my_win);



    ft_print_borders();
    mvprintw( 0, COLS - 13, " ESC exit " );


//	Start game settings;
	Player p1 = Player("Player1", 1, COLS - 5, 1, LINES - 4);

	EnemyController ec1 = EnemyController();

	p1.setEnemyController(&ec1);
    MovableController mc;

	char ch[5];

    system("afplay bg_music.mp3 &");

	while (1) try {
		ft_handle_press_key(p1, my_win);

		p1.moveBullets();

		p1.setLives(p1.getLives() - ec1.move_all());
		p1.updatePlayerInfo();

        mc.move_all();
		ch[0] = mvinch(p1.getX(), p1.getY()) & A_CHARTEXT;
		ch[1] = mvinch(p1.getX() + 1, p1.getY()) & A_CHARTEXT;
		ch[2] = mvinch(p1.getX() + 1, p1.getY() + 1) & A_CHARTEXT;
		ch[3] = mvinch(p1.getX() + 1, p1.getY() + 2) & A_CHARTEXT;
		ch[4] = mvinch(p1.getX() + 2, p1.getY()) & A_CHARTEXT;


		if (ch[0] != '\\' || ch[3] != '=' || ch[4] != '/') {
			//if (ch[0] == '@'  || ch[3] == '@' || ch[4] == '@') {
			//	p1.setLives(p1.getLives() - 1);
			attron(COLOR_PAIR(1));

			mvprintw( p1.getX(), p1.getY(), "\\");
			mvprintw( p1.getX() + 1, p1.getY(), "]");
			mvprintw( p1.getX() + 1, p1.getY() + 1, "=");
			mvprintw( p1.getX() + 1, p1.getY() + 2, "-");
			mvprintw( p1.getX() + 2, p1.getY(), "/");
			attroff(COLOR_PAIR(1));

			p1.updatePlayerInfo();
			if (p1.getLives() == 0) {

                clear();
                destroy_win(my_win);
                return (0);
            }
		}
		refresh();
	}
	catch (std::exception& e){}


}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
    system("kill $(pgrep afplay) > /dev/null 2>&1");
}


