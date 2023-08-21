#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int width = 80, height = 24, ch;
	const char *character1 = "@";
	int playerposx = rand() % width, playerposy = rand() % height;
	
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

			if(playerposx < 0)
			{
				playerposx = 0;
			}
		}

		if(ch == 'd')
		{
			playerposx++;

			if(playerposx > width)
			{
				playerposx = width;
			}
		}

		if(ch == 'w')
		{
			playerposy--;

			if(playerposy < 0)
			{
				playerposy = 0;
			}
		}

		if(ch == 's')
		{
			playerposy++;

			if(playerposy > height)
			{
				playerposy = height;
			}
		}

		mvprintw(playerposy, playerposx, character1);
		move(playerposy, playerposx);

		refresh();
	}

	endwin();

	return 0;
}

