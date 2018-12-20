#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
using namespace std;

int main(int argc, char ** argv)
{
	int y = 0,x = 0;

	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	int a,b;
	getmaxyx(stdscr, yMax, xMax);

	//size
	WINDOW * playwin = newwin(25, 40, 0, 0);
	box(playwin, 0, 0);



	wmove(playwin, 12,39);
	wvline(playwin, ' ', 1);
	//wall
	wmove(playwin, 4, 4);//1
	wvline(playwin, 0, 10);

	wmove(playwin, 4,4); //2
	whline(playwin, 0, 5);

	wmove(playwin, 0, 9);//3
	wvline(playwin, 0, 5);

	wmove(playwin, 14, 9);//4
	wvline(playwin, 0, 10);

	wmove(playwin, 14, 9);//5
	whline(playwin, 0, 10);

	wmove(playwin, 14, 19);//6
	wvline(playwin, 0, 5);

	wmove(playwin, 19, 14);//7
	whline(playwin, 0, 5);

	wmove(playwin, 4, 14);//8
	wvline(playwin, 0, 5);

	wmove(playwin ,9, 14);//9
	whline(playwin, 0, 10);

	wmove(playwin, 9, 24);//10
	wvline(playwin, 0, 15);

	wmove(playwin, 14,24);//11
	whline(playwin, 0, 10);

	wmove(playwin, 4, 34);//12
	wvline(playwin, 0, 10);

	wmove(playwin, 4, 19);//13
	whline(playwin, 0, 5);

	wmove(playwin, 0,19);//14
	wvline(playwin, 0, 5);

	wmove(playwin, 1, 1);

	refresh();
	wrefresh(playwin);

	Player *p=new Player(playwin, 1, 1, 'a');
	
	while(p->getmv() != 'x')
	{
		getsyx(y,x);
		if(y == 12&& x == 39)
		{
			break;
		}

		p->display();
		wrefresh(playwin);
	};


	getch();
	endwin();

	return 0;
}
