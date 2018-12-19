#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
using namespace std;

int main(int argc, char ** argv)
{
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	//size
	WINDOW * playwin = newwin(10, 25, 0, 0);
	box(playwin, 0, '-');


	//wall
	wmove(playwin, 1, 5);
	wvline(playwin, '*', 7);

	wmove(playwin, 3, 9);
	wvline(playwin, '*', 7);

	wmove(playwin, 1, 13);
	wvline(playwin, '*', 7);

	wmove(playwin, 1, 18);
	wvline(playwin, '*', 3);

	wmove(playwin, 4, 18);
	whline(playwin, '*', 6);

	wmove(playwin, 6, 18);
	wvline(playwin, '*', 4);

	wmove(playwin ,6, 18);
	whline(playwin, '*', 6);



	refresh();
	wrefresh(playwin);

	Player *p=new Player(playwin, 1, 1, 'a');
	while(p->getmv() != 'x')
	{
		p->display();
		wrefresh(playwin);
	}

	getch();
	endwin();

	return 0;
}

