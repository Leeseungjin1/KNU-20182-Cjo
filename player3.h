#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
	public :
		Player (WINDOW * win, int y, int x, char c);

		void mvup();
		void mvdown();
		void mvleft();
		void mvright();
		int getmv();
		void display();

	private:
		int xLoc, yLoc, xMax, yMax;
		char character;
		WINDOW * curwin;
};

Player::Player(WINDOW * win, int y, int x, char c)
{
	curwin=win;
	yLoc=y;
	xLoc=x;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);
	character=c;
}

void Player::mvup()
{
	if (yLoc == 5 && (xLoc >= 3 && xLoc<=8))
		yLoc = 5;
	else if (yLoc == 15 && (xLoc >= 8 && xLoc <= 18))
		yLoc = 15;
	else if (yLoc == 20 && (xLoc >= 13 && xLoc <= 18))
		yLoc = 20;
	else if (yLoc == 10 &&(xLoc >= 13 && xLoc <= 23)) 
		yLoc = 10;
	else if (yLoc == 15 && (xLoc >=  23 && xLoc <= 33))
		yLoc = 15;
	else if (yLoc == 5 && (xLoc >= 18 && xLoc <= 23)) 
		yLoc = 5;
	else
	{
		mvwaddch(curwin, yLoc, xLoc, ' ');
		yLoc--;
		if(yLoc<1)
			yLoc=1;
	}
}
void Player::mvdown()
{
	if (yLoc == 3 && (xLoc >= 3 && xLoc<=8))
		yLoc = 3; 
	else if (yLoc == 13 && (xLoc >= 8 && xLoc <= 18))
		yLoc = 13;
	else if (yLoc == 18 && (xLoc >= 13 && xLoc <= 18))
		yLoc = 18;
	else if (yLoc == 8 &&(xLoc >= 13 && xLoc <= 23))
		yLoc = 8;
	else if (yLoc == 13 && (xLoc >= 23 && xLoc <= 33))
		yLoc = 13;
	else if (yLoc == 3 && (xLoc >= 18 && xLoc <= 23)) 
		yLoc = 3;
	else
	{
		mvwaddch(curwin, yLoc, xLoc, ' ');
		yLoc++;
		if(yLoc>yMax-2)
			yLoc=yMax-2;
	}
}

void Player::mvleft()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	xLoc--;
	if(xLoc<1)
		xLoc=1;
}

void Player::mvright()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	xLoc++;
	if(xLoc > xMax-2)
		xLoc=xMax-2;

	
}

int Player::getmv()
{
	int choice=wgetch(curwin);
	switch(choice)
	{
		case KEY_UP:
			
			
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		defalut:
			break;
	}
	return choice;
}


void Player::display()
{
	mvwaddch(curwin, yLoc, xLoc, character);
}

#endif
