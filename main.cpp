#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "playercharacter.h"
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	srand(time(NULL));
	int width = 80, height = 24, ch;
	int screenx = 0, screeny = 0;
	int playeramount = 0;
	int enemiesamount = 0;
	int playerindex1 = 0;
	
	while(enemiesamount < 50 || enemiesamount > 100000)
	{
		printf("Enter a amount for the amount of enemies (50-100000): ");

		cin >> enemiesamount;
	}

	playeramount = ceil(enemiesamount / 2);

	const int playeramountreal = playeramount;
	
	struct playercharacter player[playeramountreal];

	player[playerindex1].character1 = "@";
	player[playerindex1].playerposx = rand() % width;
	player[playerindex1].playerposy = rand() % height;
	
	initscr();
	noecho();
	cbreak();
	
	mvprintw(player[playerindex1].playerposy, player[playerindex1].playerposx, player[playerindex1].character1);
	move(player[playerindex1].playerposy, player[playerindex1].playerposx);

	refresh();
	
	while((ch = getch()) != 'q')
	{
		clear();
		
		if(ch == 'a')
		{
			player[playerindex1].playerposx--;
		}

		if(ch == 'd')
		{
			player[playerindex1].playerposx++;
		}

		if(ch == 'w')
		{
			player[playerindex1].playerposy--;
		}

		if(ch == 's')
		{
			player[playerindex1].playerposy++;
		}

		if(ch == '?')
		{
			mvprintw(screeny, screenx, "Press a to move left");
			screeny++;
			mvprintw(screeny, screenx, "Press d to move right");
			screeny++;
			mvprintw(screeny, screenx, "Press w to move up");
			screeny++;
			mvprintw(screeny, screenx, "Press s to move down");
			screeny++;
			mvprintw(screeny, screenx, "Press ? to view this help");
			screeny++;
			mvprintw(screeny, screenx, "Press a key to exit this help");

			refresh();
			
			getch();

			clear();

			screeny = 0;
		}

		if(player[playerindex1].playerposx < 0 && player[playerindex1].playerposy < 0)
		{
			mvprintw(height - abs(player[playerindex1].playerposy % height) + 1, width - abs(player[playerindex1].playerposx % width) + 1, player[playerindex1].character1);
			move(height - abs(player[playerindex1].playerposy % height) + 1, width - abs(player[playerindex1].playerposx % width) + 1);
		}
		else if (player[playerindex1].playerposx < 0 && player[playerindex1].playerposy >= 0)
		{
			mvprintw(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width) + 1, player[playerindex1].character1);
			move(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width) + 1);
		}
		else if (player[playerindex1].playerposx >=0 && player[playerindex1].playerposy < 0)
		{
			mvprintw(height - abs(player[playerindex1].playerposy % height) + 1, abs(player[playerindex1].playerposx % width), player[playerindex1].character1);
			move(height - abs(player[playerindex1].playerposy % height) + 1, abs(player[playerindex1].playerposx % width));
		}
		else
		{
			mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), player[playerindex1].character1);
			move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
		}

		refresh();
	}

	endwin();

	return 0;
}

