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

	WINDOW * playwin = newwin(20, 50, (yMax/2)-10, 10);
	box(playwin, 0, 0);
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

