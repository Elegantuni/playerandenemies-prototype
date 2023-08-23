#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int width = 80, height = 24, ch;
	const char *character1 = "@";
	int playerposx = rand() % width, playerposy = rand() % height;
	int screenx = 0, screeny = 0;
	
	initscr();
	noecho();
	cbreak();
	
	mvprintw(playerposy, playerposx, character1);
	move(playerposy, playerposx);

	while((ch = getch()) != 'q')
	{
		clear();
		
		if(ch == 'a')
		{
			playerposx--;
		}

		if(ch == 'd')
		{
			playerposx++;
		}

		if(ch == 'w')
		{
			playerposy--;
		}

		if(ch == 's')
		{
			playerposy++;
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

		if(playerposx < 0 && playerposy < 0)
		{
			mvprintw(height - abs(playerposy % height) + 1, width - abs(playerposx % width) + 1, character1);
			move(height - abs(playerposy % height) + 1, width - abs(playerposx % width) + 1);
		}
		else if (playerposx < 0 && playerposy >= 0)
		{
			mvprintw(abs(playerposy % height), width - abs(playerposx % width) + 1, character1);
			move(abs(playerposy % height), width - abs(playerposx % width) + 1);
		}
		else if (playerposx >=0 && playerposy < 0)
		{
			mvprintw(height - abs(playerposy % height) + 1, abs(playerposx % width), character1);
			move(height - abs(playerposy % height) + 1, abs(playerposx % width));
		}
		else
		{
			mvprintw(abs(playerposy % height), abs(playerposx % width), character1);
			move(abs(playerposy % height), abs(playerposx % width));
		}

		refresh();
	}

	endwin();

	return 0;
}

