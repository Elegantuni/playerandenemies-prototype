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

struct listtext
{
	char *textheads[10];
	char *textarms[10];
	char *textlegs[10];
	char *textnecks[10];
	char *textshoulders[10];
	char *textbacks[10];
	char *textchests[10];
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
	int rowpos1 = 0;
	int rowpos2 = 0;

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

	const int enemiesamountreal = enemiesamount;

#if !defined(_WIN32)
	struct playercharacter player[playeramountreal];

	struct enemiescharacter enemy[enemiesamountreal];
#else
	struct playercharacter* player = (struct playercharacter *) malloc(sizeof(struct playercharacter) * playeramountreal);

	struct enemiescharacter* enemy = (struct enemiescharacter *) malloc(sizeof(struct enemiescharacter) * enemiesamountreal);
#endif

#if !defined(_WIN32)
	struct listtext playerlist[playeramountreal];

	struct listtext enemieslist[enemiesamountreal];
#else
	struct listtext* playerlist = (struct listtext *) malloc(sizeof(struct listtext) * playeramountreal);

	struct listtext* enemieslist = (struct listtext *) malloc(sizeof(struct listtext) * enemiesamountreal);
#endif

	player[playerindex1].playerposx = rand() % width;
	player[playerindex1].playerposy = rand() % height;

	enemy[enemiesindex1].enemiesposx = rand() % width;
	enemy[enemiesindex1].enemiesposy = rand() % height;

	FILE* fp1 = fopen("Data/PlayerCharacter.txt", "r");

	if (fp1 == NULL)
	{
		cout << "Can't open Data/PlayerCharacter.txt" << endl;

		return 0;
	}

	int characternow1 = fgetc(fp1);
	char characternow2 = (char)characternow1;

	player[playerindex1].character1[0] = characternow2;
	player[playerindex1].character1[1] = '\0';

	FILE* fp2 = fopen("Data/EnemyCharacterDwarf.txt", "r");
	
	if (fp2 == NULL)
	{
		cout << "Can't open Data/EnemyCharacterDwarf.txt" << endl;

		return 0;
	}

	int characternow3 = fgetc(fp2);
	char characternow4 = (char)characternow3;

	enemy[enemiesindex1].character1[0] = characternow4;
	enemy[enemiesindex1].character1[1] = '\0';

	rowpos1 = rand() % 3 + 3;
	rowpos2 = rand() % 3 + 1;
	
	if (rowpos1 == 3)
	{
		playerlist[playerindex1].textheads[0] = const_cast<char*>("Head 1");
		playerlist[playerindex1].textheads[1] = const_cast<char*>("Head 2");
		playerlist[playerindex1].textheads[2] = const_cast<char*>("Head 3");
		playerlist[playerindex1].textheads[3] = const_cast<char*>("Head 4");
		playerlist[playerindex1].textarms[0] = const_cast<char*>("Arm 1");
		playerlist[playerindex1].textarms[1] = const_cast<char*>("Arm 2");
		playerlist[playerindex1].textarms[2] = const_cast<char*>("Arm 3");
		playerlist[playerindex1].textarms[3] = const_cast<char*>("Arm 4");
		playerlist[playerindex1].textlegs[0] = const_cast<char*>("Leg 1");
		playerlist[playerindex1].textlegs[1] = const_cast<char*>("Leg 2");
		playerlist[playerindex1].textlegs[2] = const_cast<char*>("Leg 3");
		playerlist[playerindex1].textlegs[3] = const_cast<char*>("Leg 4");
		playerlist[playerindex1].textnecks[0] = const_cast<char*>("Neck 1");
		playerlist[playerindex1].textnecks[1] = const_cast<char*>("Neck 2");
		playerlist[playerindex1].textnecks[2] = const_cast<char*>("Neck 3");
		playerlist[playerindex1].textnecks[3] = const_cast<char*>("Neck 4");
		playerlist[playerindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		playerlist[playerindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		playerlist[playerindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
		playerlist[playerindex1].textshoulders[3] = const_cast<char*>("Shoulder 4");
		playerlist[playerindex1].textbacks[0] = const_cast<char*>("Back 1");
		playerlist[playerindex1].textbacks[1] = const_cast<char*>("Back 2");
		playerlist[playerindex1].textbacks[2] = const_cast<char*>("Back 3");
		playerlist[playerindex1].textbacks[3] = const_cast<char*>("Back 4");
		playerlist[playerindex1].textchests[0] = const_cast<char*>("Chest 1");
		playerlist[playerindex1].textchests[1] = const_cast<char*>("Chest 2");
		playerlist[playerindex1].textchests[2] = const_cast<char*>("Chest 3");
		playerlist[playerindex1].textchests[3] = const_cast<char*>("Chest 4");
	}

	if (rowpos1 == 4)
	{
		playerlist[playerindex1].textheads[0] = const_cast<char*>("Head 1");
		playerlist[playerindex1].textheads[1] = const_cast<char*>("Head 2");
		playerlist[playerindex1].textheads[2] = const_cast<char*>("Head 3");
		playerlist[playerindex1].textheads[3] = const_cast<char*>("Head 4");
		playerlist[playerindex1].textheads[4] = const_cast<char*>("Head 5");
		playerlist[playerindex1].textarms[0] = const_cast<char*>("Arm 1");
		playerlist[playerindex1].textarms[1] = const_cast<char*>("Arm 2");
		playerlist[playerindex1].textarms[2] = const_cast<char*>("Arm 3");
		playerlist[playerindex1].textarms[3] = const_cast<char*>("Arm 4");
		playerlist[playerindex1].textarms[4] = const_cast<char*>("Arm 5");
		playerlist[playerindex1].textlegs[0] = const_cast<char*>("Leg 1");
		playerlist[playerindex1].textlegs[1] = const_cast<char*>("Leg 2");
		playerlist[playerindex1].textlegs[2] = const_cast<char*>("Leg 3");
		playerlist[playerindex1].textlegs[3] = const_cast<char*>("Leg 4");
		playerlist[playerindex1].textlegs[4] = const_cast<char*>("Leg 5");
		playerlist[playerindex1].textnecks[0] = const_cast<char*>("Neck 1");
		playerlist[playerindex1].textnecks[1] = const_cast<char*>("Neck 2");
		playerlist[playerindex1].textnecks[2] = const_cast<char*>("Neck 3");
		playerlist[playerindex1].textnecks[3] = const_cast<char*>("Neck 4");
		playerlist[playerindex1].textnecks[4] = const_cast<char*>("Neck 5");
		playerlist[playerindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		playerlist[playerindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		playerlist[playerindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
		playerlist[playerindex1].textshoulders[3] = const_cast<char*>("Shoulder 4");
		playerlist[playerindex1].textshoulders[4] = const_cast<char*>("Shoulder 5");
		playerlist[playerindex1].textbacks[0] = const_cast<char*>("Back 1");
		playerlist[playerindex1].textbacks[1] = const_cast<char*>("Back 2");
		playerlist[playerindex1].textbacks[2] = const_cast<char*>("Back 3");
		playerlist[playerindex1].textbacks[3] = const_cast<char*>("Back 4");
		playerlist[playerindex1].textbacks[4] = const_cast<char*>("Back 5");
		playerlist[playerindex1].textchests[0] = const_cast<char*>("Chest 1");
		playerlist[playerindex1].textchests[1] = const_cast<char*>("Chest 2");
		playerlist[playerindex1].textchests[2] = const_cast<char*>("Chest 3");
		playerlist[playerindex1].textchests[3] = const_cast<char*>("Chest 4");
		playerlist[playerindex1].textchests[4] = const_cast<char*>("Chest 5");
	}

	if (rowpos1 == 5)
	{
		playerlist[playerindex1].textheads[0] = const_cast<char*>("Head 1");
		playerlist[playerindex1].textheads[1] = const_cast<char*>("Head 2");
		playerlist[playerindex1].textheads[2] = const_cast<char*>("Head 3");
		playerlist[playerindex1].textheads[3] = const_cast<char*>("Head 4");
		playerlist[playerindex1].textheads[4] = const_cast<char*>("Head 5");
		playerlist[playerindex1].textheads[5] = const_cast<char*>("Head 6");
		playerlist[playerindex1].textarms[0] = const_cast<char*>("Arm 1");
		playerlist[playerindex1].textarms[1] = const_cast<char*>("Arm 2");
		playerlist[playerindex1].textarms[2] = const_cast<char*>("Arm 3");
		playerlist[playerindex1].textarms[3] = const_cast<char*>("Arm 4");
		playerlist[playerindex1].textarms[4] = const_cast<char*>("Arm 5");
		playerlist[playerindex1].textarms[5] = const_cast<char*>("Arm 6");
		playerlist[playerindex1].textlegs[0] = const_cast<char*>("Leg 1");
		playerlist[playerindex1].textlegs[1] = const_cast<char*>("Leg 2");
		playerlist[playerindex1].textlegs[2] = const_cast<char*>("Leg 3");
		playerlist[playerindex1].textlegs[3] = const_cast<char*>("Leg 4");
		playerlist[playerindex1].textlegs[4] = const_cast<char*>("Leg 5");
		playerlist[playerindex1].textlegs[5] = const_cast<char*>("Leg 6");
		playerlist[playerindex1].textnecks[0] = const_cast<char*>("Neck 1");
		playerlist[playerindex1].textnecks[1] = const_cast<char*>("Neck 2");
		playerlist[playerindex1].textnecks[2] = const_cast<char*>("Neck 3");
		playerlist[playerindex1].textnecks[3] = const_cast<char*>("Neck 4");
		playerlist[playerindex1].textnecks[4] = const_cast<char*>("Neck 5");
		playerlist[playerindex1].textnecks[5] = const_cast<char*>("Neck 6");
		playerlist[playerindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		playerlist[playerindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		playerlist[playerindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
		playerlist[playerindex1].textshoulders[3] = const_cast<char*>("Shoulder 4");
		playerlist[playerindex1].textshoulders[4] = const_cast<char*>("Shoulder 5");
		playerlist[playerindex1].textshoulders[5] = const_cast<char*>("Shoulder 6");
		playerlist[playerindex1].textbacks[0] = const_cast<char*>("Back 1");
		playerlist[playerindex1].textbacks[1] = const_cast<char*>("Back 2");
		playerlist[playerindex1].textbacks[2] = const_cast<char*>("Back 3");
		playerlist[playerindex1].textbacks[3] = const_cast<char*>("Back 4");
		playerlist[playerindex1].textbacks[4] = const_cast<char*>("Back 5");
		playerlist[playerindex1].textbacks[5] = const_cast<char*>("Back 6");
		playerlist[playerindex1].textchests[0] = const_cast<char*>("Chest 1");
                playerlist[playerindex1].textchests[1] = const_cast<char*>("Chest 2");
                playerlist[playerindex1].textchests[2] = const_cast<char*>("Chest 3");
                playerlist[playerindex1].textchests[3] = const_cast<char*>("Chest 4");
                playerlist[playerindex1].textchests[4] = const_cast<char*>("Chest 5");
		playerlist[playerindex1].textchests[5] = const_cast<char*>("Chest 6");
	}

	if (rowpos2 == 1)
	{
		enemieslist[enemiesindex1].textheads[0] = const_cast<char*>("Head 1");
		enemieslist[enemiesindex1].textheads[1] = const_cast<char*>("Head 2");
		enemieslist[enemiesindex1].textarms[0] = const_cast<char*>("Arm 1");
		enemieslist[enemiesindex1].textarms[1] = const_cast<char*>("Arm 2");
		enemieslist[enemiesindex1].textlegs[0] = const_cast<char*>("Leg 1");
		enemieslist[enemiesindex1].textlegs[1] = const_cast<char*>("Leg 2");
		enemieslist[enemiesindex1].textnecks[0] = const_cast<char*>("Neck 1");
		enemieslist[enemiesindex1].textnecks[1] = const_cast<char*>("Neck 2");
		enemieslist[enemiesindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		enemieslist[enemiesindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		enemieslist[enemiesindex1].textbacks[0] = const_cast<char*>("Back 1");
		enemieslist[enemiesindex1].textbacks[1] = const_cast<char*>("Back 2");
		enemieslist[enemiesindex1].textchests[0] = const_cast<char*>("Chest 1");
		enemieslist[enemiesindex1].textchests[1] = const_cast<char*>("Chest 2");
	}

	if (rowpos2 == 2)
	{
		enemieslist[enemiesindex1].textheads[0] = const_cast<char*>("Head 1");
		enemieslist[enemiesindex1].textheads[1] = const_cast<char*>("Head 2");
		enemieslist[enemiesindex1].textheads[2] = const_cast<char*>("Head 3");
		enemieslist[enemiesindex1].textarms[0] = const_cast<char*>("Arm 1");
		enemieslist[enemiesindex1].textarms[1] = const_cast<char*>("Arm 2");
		enemieslist[enemiesindex1].textarms[2] = const_cast<char*>("Arm 3");
		enemieslist[enemiesindex1].textlegs[0] = const_cast<char*>("Leg 1");
		enemieslist[enemiesindex1].textlegs[1] = const_cast<char*>("Leg 2");
		enemieslist[enemiesindex1].textlegs[2] = const_cast<char*>("Leg 3");
		enemieslist[enemiesindex1].textnecks[0] = const_cast<char*>("Neck 1");
		enemieslist[enemiesindex1].textnecks[1] = const_cast<char*>("Neck 2");
		enemieslist[enemiesindex1].textnecks[2] = const_cast<char*>("Neck 3");
		enemieslist[enemiesindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		enemieslist[enemiesindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		enemieslist[enemiesindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
		enemieslist[enemiesindex1].textbacks[0] = const_cast<char*>("Back 1");
		enemieslist[enemiesindex1].textbacks[1] = const_cast<char*>("Back 2");
		enemieslist[enemiesindex1].textbacks[2] = const_cast<char*>("Back 3");
		enemieslist[enemiesindex1].textchests[0] = const_cast<char*>("Chest 1");
		enemieslist[enemiesindex1].textchests[1] = const_cast<char*>("Chest 2");
		enemieslist[enemiesindex1].textchests[2] = const_cast<char*>("Chest 3");
	}

	if (rowpos2 == 3)
	{
		enemieslist[enemiesindex1].textheads[0] = const_cast<char*>("Head 1");
		enemieslist[enemiesindex1].textheads[1] = const_cast<char*>("Head 2");
		enemieslist[enemiesindex1].textheads[2] = const_cast<char*>("Head 3");
		enemieslist[enemiesindex1].textheads[3] = const_cast<char*>("Head 4");
		enemieslist[enemiesindex1].textarms[0] = const_cast<char*>("Arm 1");
		enemieslist[enemiesindex1].textarms[1] = const_cast<char*>("Arm 2");
		enemieslist[enemiesindex1].textarms[2] = const_cast<char*>("Arm 3");
		enemieslist[enemiesindex1].textarms[3] = const_cast<char*>("Arm 4");
		enemieslist[enemiesindex1].textlegs[0] = const_cast<char*>("Leg 1");
		enemieslist[enemiesindex1].textlegs[1] = const_cast<char*>("Leg 2");
		enemieslist[enemiesindex1].textlegs[2] = const_cast<char*>("Leg 3");
		enemieslist[enemiesindex1].textlegs[3] = const_cast<char*>("Leg 4");
		enemieslist[enemiesindex1].textnecks[0] = const_cast<char*>("Neck 1");
		enemieslist[enemiesindex1].textnecks[1] = const_cast<char*>("Neck 2");
		enemieslist[enemiesindex1].textnecks[2] = const_cast<char*>("Neck 3");
		enemieslist[enemiesindex1].textnecks[3] = const_cast<char*>("Neck 4");
		enemieslist[enemiesindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		enemieslist[enemiesindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		enemieslist[enemiesindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
		enemieslist[enemiesindex1].textshoulders[3] = const_cast<char*>("Shoulder 4");
		enemieslist[enemiesindex1].textbacks[0] = const_cast<char*>("Back 1");
		enemieslist[enemiesindex1].textbacks[1] = const_cast<char*>("Back 2");
		enemieslist[enemiesindex1].textbacks[2] = const_cast<char*>("Back 3");
		enemieslist[enemiesindex1].textbacks[3] = const_cast<char*>("Back 4");
		enemieslist[enemiesindex1].textchests[0] = const_cast<char*>("Chest 1");
		enemieslist[enemiesindex1].textchests[1] = const_cast<char*>("Chest 2");
		enemieslist[enemiesindex1].textchests[2] = const_cast<char*>("Chest 3");
		enemieslist[enemiesindex1].textchests[3] = const_cast<char*>("Chest 4");
	}

	while(player[playerindex1].playerposx == enemy[enemiesindex1].enemiesposx && player[playerindex1].playerposy == enemy[enemiesindex1].enemiesposy)
	{
		enemy[enemiesindex1].enemiesposx = rand() % width;
		enemy[enemiesindex1].enemiesposy = rand() % height;
	}
	
	initscr();
	noecho();
	cbreak();

	mvprintw(enemy[enemiesindex1].enemiesposy, enemy[enemiesindex1].enemiesposx, enemy[enemiesindex1].character1);
	
	mvprintw(player[playerindex1].playerposy, player[playerindex1].playerposx, player[playerindex1].character1);
	move(player[playerindex1].playerposy, player[playerindex1].playerposx);

	refresh();
	
	while((ch = getch()) != 'q')
	{
		clear();
		
		if(ch == 'a')
		{
			player[playerindex1].playerposx--;

			for(int i = 0; i < enemiesamountreal; i++)
			{
				if(player[playerindex1].playerposx == enemy[i].enemiesposx && player[playerindex1].playerposy == enemy[i].enemiesposy)
				{
					player[playerindex1].playerposx++;
				}
			}
		}

		if(ch == 'd')
		{
			player[playerindex1].playerposx++;

			for(int i = 0; i < enemiesamountreal; i++)
			{
				if(player[playerindex1].playerposx == enemy[i].enemiesposx && player[playerindex1].playerposy == enemy[i].enemiesposy)
				{
					player[playerindex1].playerposx--;
				}
			}
		}

		if(ch == 'w')
		{
			player[playerindex1].playerposy--;

			for(int i = 0; i < enemiesamountreal; i++)
			{
				if(player[playerindex1].playerposx == enemy[i].enemiesposx && player[playerindex1].playerposy == enemy[i].enemiesposy)
				{
					player[playerindex1].playerposy++;
				}
			}
		}

		if(ch == 's')
		{
			player[playerindex1].playerposy++;

			for(int i = 0; i < enemiesamountreal; i++)
			{
				if(player[playerindex1].playerposx == enemy[i].enemiesposx && player[playerindex1].playerposy == enemy[i].enemiesposy)
				{
					player[playerindex1].playerposy--;
				}
			}
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
			int indexpos1 = 0;
			int itempos1 = 0;

			if(itempos1 == 0)
			{
					mvprintw(0, 0, "Press e to move up");
					mvprintw(1, 0, "Press d to move down");
					mvprintw(2, 0, "Press p to exit this screen");
					mvprintw(3, 0, "Press n to view next body part");
    				mvprintw(4, 0, "Player Heads");
				
					for(int i = 0; i <= indexpos1; i++)
					{
						mvprintw(i%24+5, 0, playerlist[playerindex1].textheads[i]);
					}
			}
			if (itempos1 == 1)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Arms");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textarms[i]);
				}
			}
			if (itempos1 == 2)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Legs");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textlegs[i]);
				}
			}
			if (itempos1 == 3)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Necks");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textnecks[i]);
				}
			}
			if (itempos1 == 4)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Shoulders");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textshoulders[i]);
				}
			}
			if (itempos1 == 5)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Backs");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textbacks[i]);
				}
			}
			if (itempos1 == 6)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Chests");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textchests[i]);
				}
			}
			refresh();

			while((ch = getch()) != 'p')
  			{
				switch (ch)
				{
				case 'n':
					itempos1++;

					if (itempos1 > 6)
					{
						itempos1 = 0;
					}
					clear();
					if (itempos1 == 0)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Heads");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textheads[i]);
						}
					}
					if (itempos1 == 1)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Arms");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textarms[i]);
						}
					}
					if (itempos1 == 2)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Legs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textlegs[i]);
						}
					}
					if (itempos1 == 3)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Necks");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textnecks[i]);
						}
					}
					if (itempos1 == 4)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Shoulders");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textshoulders[i]);
						}
					}
					if (itempos1 == 5)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Backs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textbacks[i]);
						}
					}
					if (itempos1 == 6)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Chests");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textchests[i]);
						}
					}
					refresh();
					break;
				case 'e':
					if (indexpos1 > 0)
					{
						indexpos1--;
						if (indexpos1 < 0)
						{
							indexpos1 = 0;
						}
					}
					clear();
					if (itempos1 == 0)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Heads");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textheads[i]);
						}
					}
					if (itempos1 == 1)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Arms");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textarms[i]);
						}
					}
					if (itempos1 == 2)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Legs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textlegs[i]);
						}
					}
					if (itempos1 == 3)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Necks");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textnecks[i]);
						}
					}
					if (itempos1 == 4)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Shoulders");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textshoulders[i]);
						}
					}
					if (itempos1 == 5)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Backs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textbacks[i]);
						}
					}
					if (itempos1 == 6)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Chests");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textchests[i]);
						}
					}
					refresh();
					break;
				case 'd':
					if (indexpos1 < rowpos1)
					{
						indexpos1++;
						if (indexpos1 > rowpos1)
						{
							indexpos1--;
						}
					}
					clear();
					if (itempos1 == 0)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Heads");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textheads[i]);
						}
					}
					if (itempos1 == 1)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Arms");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textarms[i]);
						}
					}
					if (itempos1 == 2)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Legs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textlegs[i]);
						}
					}
					if (itempos1 == 3)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Necks");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textnecks[i]);
						}
					}
					if (itempos1 == 4)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Shoulders");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textshoulders[i]);
						}
					}
					if (itempos1 == 5)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Backs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textbacks[i]);
						}
					}
					if (itempos1 == 6)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Chests");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, playerlist[playerindex1].textchests[i]);
						}
					}
					refresh();
    				break;
     			}
			}
		}

		if (ch == 'v')
		{
			int indexpos1 = 0;
			int itempos1 = 0;

			if(itempos1 == 0)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
    			mvprintw(4, 0, "Enemies Heads");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, enemieslist[enemiesindex1].textheads[i]);
				}
			}
			if (itempos1 == 1)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Arms");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textarms[i]);
				}
			}
			if (itempos1 == 2)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Legs");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textlegs[i]);
				}
			}
			if (itempos1 == 3)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Necks");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textnecks[i]);
				}
			}
			if (itempos1 == 4)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Shoulders");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textshoulders[i]);
				}
			}
			if (itempos1 == 5)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Backs");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textbacks[i]);
				}
			}
			if (itempos1 == 6)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Chests");

				for (int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textchests[i]);
				}
			}
			refresh();

			while((ch = getch()) != 'p')
  			{
    			switch (ch)
    			{
				case 'n':
					itempos1++;

					if (itempos1 > 6)
					{
						itempos1 = 0;
					}
					clear();
					if (itempos1 == 0)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Heads");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textheads[i]);
						}
					}
					if (itempos1 == 1)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Arms");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textarms[i]);
						}
					}
					if (itempos1 == 2)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Legs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textlegs[i]);
						}
					}
					if (itempos1 == 3)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Necks");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textnecks[i]);
						}
					}
					if (itempos1 == 4)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Shoulders");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textshoulders[i]);
						}
					}
					if (itempos1 == 5)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Backs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textbacks[i]);
						}
					}
					if (itempos1 == 6)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Chests");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textchests[i]);
						}
					}
					refresh();
					break;
      				case 'e':
        			if (indexpos1 > 0)
    				{
      					indexpos1--;
						if(indexpos1 < 0)
						{
							indexpos1 = 0;
						}
    				}
					clear();
					if(itempos1 == 0)
					{
    					mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Heads");
						
						for(int i = 0; i <= indexpos1; i++)
                                		{
                                        		mvprintw(i%24+5, 0, enemieslist[enemiesindex1].textheads[i]);
                                		}
					}
					if (itempos1 == 1)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Arms");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemieslist[enemiesindex1].textarms[i]);
						}
					}
					if (itempos1 == 2)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Legs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemieslist[enemiesindex1].textlegs[i]);
						}
					}
					if (itempos1 == 3)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Necks");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemieslist[enemiesindex1].textnecks[i]);
						}
					}
					if (itempos1 == 4)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Shoulders");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemieslist[enemiesindex1].textshoulders[i]);
						}
					}
					if (itempos1 == 5)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Backs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemieslist[enemiesindex1].textbacks[i]);
						}
					}
					if (itempos1 == 6)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Chests");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemieslist[enemiesindex1].textchests[i]);
						}
					}
					refresh();
    				break;
      				case 'd':
    				if (indexpos1 < rowpos2)
    				{
      					indexpos1++;
						if(indexpos1 > rowpos2)
						{
							indexpos1--;
						}
    				}
					clear();
					if(itempos1 == 0)
					{
    					mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Head");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textheads[i]);
						}
					}
					if (itempos1 == 1)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Arms");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textarms[i]);
						}
					}
					if (itempos1 == 2)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Legs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textlegs[i]);
						}
					}
					if (itempos1 == 3)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Necks");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textnecks[i]);
						}
					}
					if (itempos1 == 4)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Shoulders");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textshoulders[i]);
						}
					}
					if (itempos1 == 5)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Backs");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textbacks[i]);
						}
					}
					if (itempos1 == 6)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Chests");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, enemieslist[enemiesindex1].textchests[i]);
						}
					}
					refresh();
    				break;
     			}
			}
		}

		clear();

		mvprintw(enemy[enemiesindex1].enemiesposy, enemy[enemiesindex1].enemiesposx, enemy[enemiesindex1].character1);

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
