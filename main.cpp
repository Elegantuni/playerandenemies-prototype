#if defined(_WIN32)
	#include <curses.h>
#else
	#include <ncurses.h>
#endif

#include <stdlib.h>
#include <time.h>
#include "playercharacter.h"
#include "enemiescharacter.h"
#include <math.h>
#include <iostream>
using namespace std;

struct screenindex
{
	char *name;
};

int main()
{
	srand(time(NULL));
	int width = 80, height = 24, ch;
	int screenx = 0, screeny = 0, index1 = 0;
	int playeramount = 0;
	int enemiesamount = 0;
	int playerindex1 = 0;
	int enemiesindex1 = 0;
	const int screenindexcount1 = 10;
	const int screenindexcount2 = 10;
	struct screenindex screenindex[screenindexcount1];
	struct screenindex screenindexenemies[screenindexcount2];
	int screenindexamount = 0;
	int screenindexamount2 = 0;
	
	screenindex[screenindexamount].name = const_cast<char *>("Heads");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Arms");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Legs");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Necks");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Shoulders");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Backs");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Chests");
	
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Heads");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Arms");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Legs");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Necks");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Shoulders");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Backs");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Chests");

	while(enemiesamount < 50 || enemiesamount > 100000)
	{
		printf("Enter a amount for the amount of enemies (50-100000): ");

		cin >> enemiesamount;
	}

	playeramount = int(ceil(enemiesamount / 2));

	const int playeramountreal = playeramount;

#if !defined(_WIN32)
	struct playercharacter player[playeramountreal];
#else
	struct playercharacter* player = (struct playercharacter *) malloc(sizeof(struct playercharacter) * playeramountreal);
#endif

	player[playerindex1].character1 = const_cast<char *>("@");
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
			mvprintw(screeny, screenx, "Press b to view body parts for player(not fully implemented)");
			screeny++;
			mvprintw(screeny, screenx, "Press v to view body parts for enemy in line of sight");
			screeny++;
			mvprintw(screeny, screenx, "Press a key to exit this help");

			refresh();
			
			getch();

			clear();

			screeny = 0;
		}

		if(ch == 'b')
		{
			ch = 'n';
			index1 = 0;
			
			while(ch != 'b')
			{
				clear();
				mvprintw(screeny, screenx, "Player %d", playerindex1 + 1);
				screeny++;
				mvprintw(screeny, screenx, screenindex[index1].name);
				screeny++;
				mvprintw(screeny, screenx, "Press b to exit this menu");
				screeny++;
				mvprintw(screeny, screenx, "Press a to move to previous screen");
				screeny++;
				mvprintw(screeny, screenx, "Press d to move to next screen");
				refresh();

				switch(ch = getch())
				{
					case 'd':
					{
						index1++;
						screeny = 0;

						if(index1 > screenindexamount)
						{
							index1 = 0;
						}
					}
					break;

					case 'a':
					{
						index1--;
						screeny = 0;

						if(index1 < 0)
						{
							index1 = screenindexamount;
						}
					}
				}
			}

			screeny = 0;
			index1 = 0;
			clear();
		}

		if (ch == 'v')
		{
			ch = 'n';
			index1 = 0;

			while (ch != 'v')
			{
				clear();
				mvprintw(screeny, screenx, "Enemies %d", enemiesindex1 + 1);
				screeny++;
				mvprintw(screeny, screenx, screenindexenemies[index1].name);
				screeny++;
				mvprintw(screeny, screenx, "Press v to exit this menu");
				screeny++;
				mvprintw(screeny, screenx, "Press a to move to previous screen");
				screeny++;
				mvprintw(screeny, screenx, "Press d to move to next screen");
				refresh();

				switch (ch = getch())
				{
					case 'd':
					{
						index1++;
						screeny = 0;

						if (index1 > screenindexamount2)
						{
							index1 = 0;
						}
					}
					break;

					case 'a':
					{
						index1--;
						screeny = 0;

						if (index1 < 0)
						{
							index1 = screenindexamount2;
						}
					}
				}
			}

			screeny = 0;
			index1 = 0;
			clear();
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

