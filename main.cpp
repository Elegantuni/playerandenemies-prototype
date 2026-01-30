#if defined(_WIN32) || defined(__MINIX3__)
	#include <curses.h>
#else
	#include <ncurses.h>
#endif

#include <stdlib.h>
#include <time.h>
#include "playercharacter.h"
#include "enemiescharacter.h"
#include "typeofobjects.h"
#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;

struct screenindex
{
	char *name;
};

#if defined(__OpenBSD__)
#define rand() arc4random()
#endif

int main()
{
	srand(time(NULL));
	int width = 80, height = 24, ch;
	int screenx = 0, screeny = 0, index1 = 0;
	int mapwidth = 500, mapheight = 500;
	int playeramount = 0;
	int enemiesamount = 0;
	int playerindex1 = 0;
	int enemiesindex1 = 0;
	const int screenindexcount1 = 20;
	const int screenindexcount2 = 20;
	struct screenindex screenindex[screenindexcount1];
	struct screenindex screenindexenemies[screenindexcount2];
	int screenindexamount = 0;
	int screenindexamount2 = 0;
	int rowpos1 = 0;
	int rowpos2 = 0;
	int enemyvisiblex = 0;
	int enemyvisibley = 0;
	int enemiesindex1_max = 0;
	int statcharacter = -1;
	int playermovement = 0;
	int enemiesmovement = 0;
	int neutralindex1 = 0;
	int neutralindex1_max = 100;

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
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Toes");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Wrists");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Waists");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Nails");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Toe Nails");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char *>("Eyes");
	screenindexamount++;
	screenindex[screenindexamount].name = const_cast<char*>("Lips");
	screenindexamount++;
	screenindexenemies[screenindexamount].name = const_cast<char*>("Feet");
	screenindexamount++;
	screenindexenemies[screenindexamount].name = const_cast<char*>("Teeth");
	screenindexamount++;
	screenindexenemies[screenindexamount].name = const_cast<char*>("Hair");
	
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
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Toes");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Wrists");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Waists");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Nails");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Toe Nails");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Eyes");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Lips");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Feet");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Teeth");
	screenindexamount2++;
	screenindexenemies[screenindexamount2].name = const_cast<char*>("Hair");
	
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

	player[playerindex1].playerposx = rand() % (2*mapwidth);
	player[playerindex1].playerposy = rand() % (2*mapheight);

	enemy[enemiesindex1].enemiesposx = rand() % (2*mapwidth);
	enemy[enemiesindex1].enemiesposy = rand() % (2*mapheight);

	player[playerindex1].playerobject.player = 1;

	player[playerindex1].playerobject.enemy = 0;

	enemy[enemiesindex1].enemiesobject.enemy = 1;

	enemy[enemiesindex1].enemiesobject.player = 0;
	
	FILE* fp1 = fopen("Data/PlayerCharacter.txt", "r");

	if(fp1 == NULL)
	{
		cout << "Can't open Data/PlayerCharacter.txt" << endl;

		return 0;
	}	

	int characternow1 = fgetc(fp1);
	char characternow2 = (char)characternow1;

	player[playerindex1].character1[0] = characternow2;
	player[playerindex1].character1[1] = '\0';

	FILE* fp2 = NULL;
	
	for (enemiesindex1 = 0; enemiesindex1 < enemiesamountreal; enemiesindex1++)
	{
		int counterindex1 = rand() % 5;

		if (counterindex1 == 0)
		{
			fp2 = fopen("Data/EnemyCharacterDwarf.txt", "r");

			if (fp2 == NULL)
			{
				cout << "Can't open Data/EnemyCharacterDwarf.txt" << endl;

				return 0;
			}
		}

		if (counterindex1 == 1)
		{
			fp2 = fopen("Data/EnemyCharacterElf.txt", "r");

			if (fp2 == NULL)
			{
				cout << "Can't open Data/EnemyCharacterElf.txt" << endl;

				return 0;
			}
		}

		if (counterindex1 == 2)
		{
			fp2 = fopen("Data/EnemyCharacterHuman.txt", "r");

			if (fp2 == NULL)
			{
				cout << "Can't open Data/EnemyCharacterHumun.txt" << endl;

				return 0;
			}
		}

		if (counterindex1 == 3)
		{
			fp2 = fopen("Data/EnemyCharacterOrc.txt", "r");

			if (fp2 == NULL)
			{
				cout << "Can't open Data/EnemyCharacterOrc.txt" << endl;

				return 0;
			}
		}

		if (counterindex1 == 4)
		{
			fp2 = fopen("Data/EnemyCharacterNecromancer.txt", "r");

			if (fp2 == NULL)
			{
				cout << "Can't open Data/EnemyCharacterNecromancer.txt" << endl;

				return 0;
			}
		}

		int characternow3 = fgetc(fp2);
		char characternow4 = (char)characternow3;

		enemy[enemiesindex1].character1[0] = characternow4;
		enemy[enemiesindex1].character1[1] = '\0';

		enemiesindex1_max = enemiesamountreal;
	}

	char buffer1[100][30];
	int nposy;
	int nposx;
	char buffer1signs[100][2];

	strcpy(buffer1[neutralindex1], "Hitpoints");
	strcpy(buffer1signs[neutralindex1], "U");

	neutralindex1++;

	strcpy(buffer1[neutralindex1], "Magicpoints");
	strcpy(buffer1signs[neutralindex1], "P");

	neutralindex1++;

	for(int i = 0; i < neutralindex1_max; i++)
	{
		int index3;

		index3 = rand() % neutralindex1;
	
		player[playerindex1].neutralpickups[i] = 1;	
		strcpy(player[playerindex1].neutral[i], buffer1[index3]);
		strcpy(player[playerindex1].neutralsigns[i], buffer1signs[index3]);

		player[playerindex1].neutralposy[i] = rand() % (2*mapheight);
		player[playerindex1].neutralposx[i] = rand() % (2*mapwidth);

		if(player[playerindex1].neutralposy[i] >= mapheight)
		{
			player[playerindex1].neutralposy[i] = -player[playerindex1].neutralposy[i] + mapheight;
		}

		if(player[playerindex1].neutralposx[i] >= mapwidth)
		{
			player[playerindex1].neutralposx[i] = -player[playerindex1].neutralposx[i] + mapwidth;
		}

		while(player[playerindex1].neutralposy[i] == player[playerindex1].playerposy && player[playerindex1].neutralposx[i] == player[playerindex1].playerposx)
		{
			player[playerindex1].neutralposy[i] = rand() % (2*mapheight);
			player[playerindex1].neutralposx[i] = rand() % (2*mapwidth);

		if(player[playerindex1].neutralposy[i] >= mapheight)
		{
			player[playerindex1].neutralposy[i] = -player[playerindex1].neutralposy[i] + mapheight;
		}

		if(player[playerindex1].neutralposx[i] >= mapwidth)
		{
			player[playerindex1].neutralposx[i] = -player[playerindex1].neutralposx[i] + mapwidth;
		}
			
		}

		for(int j = 0; j < enemiesamount; j++)
		{
			while(player[playerindex1].neutralposy[i] == enemy[enemiesindex1].enemiesposy && player[playerindex1].neutralposx[i] == enemy[enemiesindex1].enemiesposx)
			{
				player[playerindex1].neutralposy[i] = rand() % (2*mapheight);
				player[playerindex1].neutralposx[i] = rand() % (2*mapwidth);

		if(player[playerindex1].neutralposy[i] >= mapheight)
		{
			player[playerindex1].neutralposy[i] = -player[playerindex1].neutralposy[i] + mapheight;
		}

		if(player[playerindex1].neutralposx[i] >= mapwidth)
		{
			player[playerindex1].neutralposx[i] = -player[playerindex1].neutralposx[i] + mapwidth;
		}
				
			}
		}
	}

	rowpos1 = rand() % 3 + 3;
	rowpos2 = rand() % 3 + 1;
	
	if (rowpos1 == 3)
	{
		player[playerindex1].textheads[0] = const_cast<char*>("Head 1");
		player[playerindex1].textheads[1] = const_cast<char*>("Head 2");
		player[playerindex1].textheads[2] = const_cast<char*>("Head 3");
		player[playerindex1].textheads[3] = const_cast<char*>("Head 4");
		player[playerindex1].textarms[0] = const_cast<char*>("Arm 1");
		player[playerindex1].textarms[1] = const_cast<char*>("Arm 2");
		player[playerindex1].textarms[2] = const_cast<char*>("Arm 3");
		player[playerindex1].textarms[3] = const_cast<char*>("Arm 4");
		player[playerindex1].textlegs[0] = const_cast<char*>("Leg 1");
		player[playerindex1].textlegs[1] = const_cast<char*>("Leg 2");
		player[playerindex1].textlegs[2] = const_cast<char*>("Leg 3");
		player[playerindex1].textlegs[3] = const_cast<char*>("Leg 4");
		player[playerindex1].textnecks[0] = const_cast<char*>("Neck 1");
		player[playerindex1].textnecks[1] = const_cast<char*>("Neck 2");
		player[playerindex1].textnecks[2] = const_cast<char*>("Neck 3");
		player[playerindex1].textnecks[3] = const_cast<char*>("Neck 4");
		player[playerindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		player[playerindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		player[playerindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
		player[playerindex1].textshoulders[3] = const_cast<char*>("Shoulder 4");
		player[playerindex1].textbacks[0] = const_cast<char*>("Back 1");
		player[playerindex1].textbacks[1] = const_cast<char*>("Back 2");
		player[playerindex1].textbacks[2] = const_cast<char*>("Back 3");
		player[playerindex1].textbacks[3] = const_cast<char*>("Back 4");
		player[playerindex1].textchests[0] = const_cast<char*>("Chest 1");
		player[playerindex1].textchests[1] = const_cast<char*>("Chest 2");
		player[playerindex1].textchests[2] = const_cast<char*>("Chest 3");
		player[playerindex1].textchests[3] = const_cast<char*>("Chest 4");
		player[playerindex1].texttoes[0] = const_cast<char*>("Toe 1");
		player[playerindex1].texttoes[1] = const_cast<char*>("Toe 2");
		player[playerindex1].texttoes[2] = const_cast<char*>("Toe 3");
		player[playerindex1].texttoes[3] = const_cast<char*>("Toe 4");
		player[playerindex1].textwrists[0] = const_cast<char*>("Wrist 1");
		player[playerindex1].textwrists[1] = const_cast<char*>("Wrist 2");
		player[playerindex1].textwrists[2] = const_cast<char*>("Wrist 3");
		player[playerindex1].textwrists[3] = const_cast<char*>("Wrist 4");
		player[playerindex1].textwaists[0] = const_cast<char*>("Waist 1");
		player[playerindex1].textwaists[1] = const_cast<char*>("Waist 2");
		player[playerindex1].textwaists[2] = const_cast<char*>("Waist 3");
		player[playerindex1].textwaists[3] = const_cast<char*>("Waist 4");
		player[playerindex1].textnails[0] = const_cast<char*>("Nail 1");
		player[playerindex1].textnails[1] = const_cast<char*>("Nail 2");
		player[playerindex1].textnails[2] = const_cast<char*>("Nail 3");
		player[playerindex1].textnails[3] = const_cast<char*>("Nail 4");
		player[playerindex1].texttoenails[0] = const_cast<char*>("Toe Nail 1");
      		player[playerindex1].texttoenails[1] = const_cast<char*>("Toe Nail 2");
      		player[playerindex1].texttoenails[2] = const_cast<char*>("Toe Nail 3");
      		player[playerindex1].texttoenails[3] = const_cast<char*>("Toe Nail 4");
		player[playerindex1].texteyes[0] = const_cast<char*>("Eye 1");
		player[playerindex1].texteyes[1] = const_cast<char*>("Eye 2");
		player[playerindex1].texteyes[2] = const_cast<char*>("Eye 3");
		player[playerindex1].texteyes[3] = const_cast<char*>("Eye 4");
		player[playerindex1].textlips[0] = const_cast<char*>("Lip 1");
		player[playerindex1].textlips[1] = const_cast<char*>("Lip 2");
		player[playerindex1].textlips[2] = const_cast<char*>("Lip 3");
		player[playerindex1].textlips[3] = const_cast<char*>("Lip 4");
		player[playerindex1].textfeet[0] = const_cast<char*>("Foot 1");
		player[playerindex1].textfeet[1] = const_cast<char*>("Foot 2");
		player[playerindex1].textfeet[2] = const_cast<char*>("Foot 3");
		player[playerindex1].textfeet[3] = const_cast<char*>("Foot 4");
		player[playerindex1].textteeth[0] = const_cast<char*>("Tooth 1");
		player[playerindex1].textteeth[1] = const_cast<char*>("Tooth 2");
		player[playerindex1].textteeth[2] = const_cast<char*>("Tooth 3");
		player[playerindex1].textteeth[3] = const_cast<char*>("Tooth 4");
		player[playerindex1].texthair[0] = const_cast<char*>("Hair 1");
		player[playerindex1].texthair[1] = const_cast<char*>("Hair 2");
		player[playerindex1].texthair[2] = const_cast<char*>("Hair 3");
		player[playerindex1].texthair[3] = const_cast<char*>("Hair 4");
	}

	if (rowpos1 == 4)
	{
		player[playerindex1].textheads[0] = const_cast<char*>("Head 1");
		player[playerindex1].textheads[1] = const_cast<char*>("Head 2");
		player[playerindex1].textheads[2] = const_cast<char*>("Head 3");
		player[playerindex1].textheads[3] = const_cast<char*>("Head 4");
		player[playerindex1].textheads[4] = const_cast<char*>("Head 5");
		player[playerindex1].textarms[0] = const_cast<char*>("Arm 1");
		player[playerindex1].textarms[1] = const_cast<char*>("Arm 2");
		player[playerindex1].textarms[2] = const_cast<char*>("Arm 3");
		player[playerindex1].textarms[3] = const_cast<char*>("Arm 4");
		player[playerindex1].textarms[4] = const_cast<char*>("Arm 5");
		player[playerindex1].textlegs[0] = const_cast<char*>("Leg 1");
		player[playerindex1].textlegs[1] = const_cast<char*>("Leg 2");
		player[playerindex1].textlegs[2] = const_cast<char*>("Leg 3");
		player[playerindex1].textlegs[3] = const_cast<char*>("Leg 4");
		player[playerindex1].textlegs[4] = const_cast<char*>("Leg 5");
		player[playerindex1].textnecks[0] = const_cast<char*>("Neck 1");
		player[playerindex1].textnecks[1] = const_cast<char*>("Neck 2");
		player[playerindex1].textnecks[2] = const_cast<char*>("Neck 3");
		player[playerindex1].textnecks[3] = const_cast<char*>("Neck 4");
		player[playerindex1].textnecks[4] = const_cast<char*>("Neck 5");
		player[playerindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		player[playerindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		player[playerindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
		player[playerindex1].textshoulders[3] = const_cast<char*>("Shoulder 4");
		player[playerindex1].textshoulders[4] = const_cast<char*>("Shoulder 5");
		player[playerindex1].textbacks[0] = const_cast<char*>("Back 1");
		player[playerindex1].textbacks[1] = const_cast<char*>("Back 2");
		player[playerindex1].textbacks[2] = const_cast<char*>("Back 3");
		player[playerindex1].textbacks[3] = const_cast<char*>("Back 4");
		player[playerindex1].textbacks[4] = const_cast<char*>("Back 5");
		player[playerindex1].textchests[0] = const_cast<char*>("Chest 1");
		player[playerindex1].textchests[1] = const_cast<char*>("Chest 2");
		player[playerindex1].textchests[2] = const_cast<char*>("Chest 3");
		player[playerindex1].textchests[3] = const_cast<char*>("Chest 4");
		player[playerindex1].textchests[4] = const_cast<char*>("Chest 5");
		player[playerindex1].texttoes[0] = const_cast<char*>("Toe 1");
		player[playerindex1].texttoes[1] = const_cast<char*>("Toe 2");
		player[playerindex1].texttoes[2] = const_cast<char*>("Toe 3");
		player[playerindex1].texttoes[3] = const_cast<char*>("Toe 4");
		player[playerindex1].texttoes[4] = const_cast<char*>("Toe 5");
		player[playerindex1].textwrists[0] = const_cast<char*>("Wrist 1");
		player[playerindex1].textwrists[1] = const_cast<char*>("Wrist 2");
		player[playerindex1].textwrists[2] = const_cast<char*>("Wrist 3");
		player[playerindex1].textwrists[3] = const_cast<char*>("Wrist 4");
		player[playerindex1].textwrists[4] = const_cast<char*>("Wrist 5");
		player[playerindex1].textwaists[0] = const_cast<char*>("Waist 1");
		player[playerindex1].textwaists[1] = const_cast<char*>("Waist 2");
		player[playerindex1].textwaists[2] = const_cast<char*>("Waist 3");
		player[playerindex1].textwaists[3] = const_cast<char*>("Waist 4");
		player[playerindex1].textwaists[4] = const_cast<char*>("Waist 5");
		player[playerindex1].textnails[0] = const_cast<char*>("Nail 1");
		player[playerindex1].textnails[1] = const_cast<char*>("Nail 2");
		player[playerindex1].textnails[2] = const_cast<char*>("Nail 3");
		player[playerindex1].textnails[3] = const_cast<char*>("Nail 4");
		player[playerindex1].textnails[4] = const_cast<char*>("Nail 5");
		player[playerindex1].texttoenails[0] = const_cast<char*>("Toe Nail 1");
      		player[playerindex1].texttoenails[1] = const_cast<char*>("Toe Nail 2");
      		player[playerindex1].texttoenails[2] = const_cast<char*>("Toe Nail 3");
      		player[playerindex1].texttoenails[3] = const_cast<char*>("Toe Nail 4");
      		player[playerindex1].texttoenails[4] = const_cast<char*>("Toe Nail 5");
		player[playerindex1].texteyes[0] = const_cast<char*>("Eye 1");
		player[playerindex1].texteyes[1] = const_cast<char*>("Eye 2");
		player[playerindex1].texteyes[2] = const_cast<char*>("Eye 3");
		player[playerindex1].texteyes[3] = const_cast<char*>("Eye 4");
		player[playerindex1].texteyes[4] = const_cast<char*>("Eye 5");
		player[playerindex1].textlips[0] = const_cast<char*>("Lip 1");
		player[playerindex1].textlips[1] = const_cast<char*>("Lip 2");
		player[playerindex1].textlips[2] = const_cast<char*>("Lip 3");
		player[playerindex1].textlips[3] = const_cast<char*>("Lip 4");
		player[playerindex1].textlips[4] = const_cast<char*>("Lip 5");
		player[playerindex1].textfeet[0] = const_cast<char*>("Foot 1");
		player[playerindex1].textfeet[1] = const_cast<char*>("Foot 2");
		player[playerindex1].textfeet[2] = const_cast<char*>("Foot 3");
		player[playerindex1].textfeet[3] = const_cast<char*>("Foot 4");
		player[playerindex1].textfeet[4] = const_cast<char*>("Foot 5");
		player[playerindex1].textteeth[0] = const_cast<char*>("Tooth 1");
		player[playerindex1].textteeth[1] = const_cast<char*>("Tooth 2");
		player[playerindex1].textteeth[2] = const_cast<char*>("Tooth 3");
		player[playerindex1].textteeth[3] = const_cast<char*>("Tooth 4");
		player[playerindex1].textteeth[4] = const_cast<char*>("Tooth 5");
		player[playerindex1].texthair[0] = const_cast<char*>("Hair 1");
		player[playerindex1].texthair[1] = const_cast<char*>("Hair 2");
		player[playerindex1].texthair[2] = const_cast<char*>("Hair 3");
		player[playerindex1].texthair[3] = const_cast<char*>("Hair 4");
		player[playerindex1].texthair[4] = const_cast<char*>("Hair 5");
	}

	if (rowpos1 == 5)
	{
		player[playerindex1].textheads[0] = const_cast<char*>("Head 1");
		player[playerindex1].textheads[1] = const_cast<char*>("Head 2");
		player[playerindex1].textheads[2] = const_cast<char*>("Head 3");
		player[playerindex1].textheads[3] = const_cast<char*>("Head 4");
		player[playerindex1].textheads[4] = const_cast<char*>("Head 5");
		player[playerindex1].textheads[5] = const_cast<char*>("Head 6");
		player[playerindex1].textarms[0] = const_cast<char*>("Arm 1");
		player[playerindex1].textarms[1] = const_cast<char*>("Arm 2");
		player[playerindex1].textarms[2] = const_cast<char*>("Arm 3");
		player[playerindex1].textarms[3] = const_cast<char*>("Arm 4");
		player[playerindex1].textarms[4] = const_cast<char*>("Arm 5");
		player[playerindex1].textarms[5] = const_cast<char*>("Arm 6");
		player[playerindex1].textlegs[0] = const_cast<char*>("Leg 1");
		player[playerindex1].textlegs[1] = const_cast<char*>("Leg 2");
		player[playerindex1].textlegs[2] = const_cast<char*>("Leg 3");
		player[playerindex1].textlegs[3] = const_cast<char*>("Leg 4");
		player[playerindex1].textlegs[4] = const_cast<char*>("Leg 5");
		player[playerindex1].textlegs[5] = const_cast<char*>("Leg 6");
		player[playerindex1].textnecks[0] = const_cast<char*>("Neck 1");
		player[playerindex1].textnecks[1] = const_cast<char*>("Neck 2");
		player[playerindex1].textnecks[2] = const_cast<char*>("Neck 3");
		player[playerindex1].textnecks[3] = const_cast<char*>("Neck 4");
		player[playerindex1].textnecks[4] = const_cast<char*>("Neck 5");
		player[playerindex1].textnecks[5] = const_cast<char*>("Neck 6");
		player[playerindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
		player[playerindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
		player[playerindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
		player[playerindex1].textshoulders[3] = const_cast<char*>("Shoulder 4");
		player[playerindex1].textshoulders[4] = const_cast<char*>("Shoulder 5");
		player[playerindex1].textshoulders[5] = const_cast<char*>("Shoulder 6");
		player[playerindex1].textbacks[0] = const_cast<char*>("Back 1");
		player[playerindex1].textbacks[1] = const_cast<char*>("Back 2");
		player[playerindex1].textbacks[2] = const_cast<char*>("Back 3");
		player[playerindex1].textbacks[3] = const_cast<char*>("Back 4");
		player[playerindex1].textbacks[4] = const_cast<char*>("Back 5");
		player[playerindex1].textbacks[5] = const_cast<char*>("Back 6");
		player[playerindex1].textchests[0] = const_cast<char*>("Chest 1");
        	player[playerindex1].textchests[1] = const_cast<char*>("Chest 2");
        	player[playerindex1].textchests[2] = const_cast<char*>("Chest 3");
        	player[playerindex1].textchests[3] = const_cast<char*>("Chest 4");
        	player[playerindex1].textchests[4] = const_cast<char*>("Chest 5");
		player[playerindex1].textchests[5] = const_cast<char*>("Chest 6");
		player[playerindex1].texttoes[0] = const_cast<char*>("Toe 1");
		player[playerindex1].texttoes[1] = const_cast<char*>("Toe 2");
		player[playerindex1].texttoes[2] = const_cast<char*>("Toe 3");
		player[playerindex1].texttoes[3] = const_cast<char*>("Toe 4");
		player[playerindex1].texttoes[4] = const_cast<char*>("Toe 5");
		player[playerindex1].texttoes[5] = const_cast<char*>("Toe 6");
		player[playerindex1].textwrists[0] = const_cast<char*>("Wrist 1");
		player[playerindex1].textwrists[1] = const_cast<char*>("Wrist 2");
		player[playerindex1].textwrists[2] = const_cast<char*>("Wrist 3");
		player[playerindex1].textwrists[3] = const_cast<char*>("Wrist 4");
		player[playerindex1].textwrists[4] = const_cast<char*>("Wrist 5");
		player[playerindex1].textwrists[5] = const_cast<char*>("Wrist 6");
		player[playerindex1].textwaists[0] = const_cast<char*>("Waist 1");
		player[playerindex1].textwaists[1] = const_cast<char*>("Waist 2");
		player[playerindex1].textwaists[2] = const_cast<char*>("Waist 3");
		player[playerindex1].textwaists[3] = const_cast<char*>("Waist 4");
		player[playerindex1].textwaists[4] = const_cast<char*>("Waist 5");
		player[playerindex1].textwaists[5] = const_cast<char*>("Waist 6");
		player[playerindex1].textnails[0] = const_cast<char*>("Nail 1");
		player[playerindex1].textnails[1] = const_cast<char*>("Nail 2");
		player[playerindex1].textnails[2] = const_cast<char*>("Nail 3");
		player[playerindex1].textnails[3] = const_cast<char*>("Nail 4");
		player[playerindex1].textnails[4] = const_cast<char*>("Nail 5");
		player[playerindex1].textnails[5] = const_cast<char*>("Nail 6");
		player[playerindex1].texttoenails[0] = const_cast<char*>("Toe Nail 1");
      		player[playerindex1].texttoenails[1] = const_cast<char*>("Toe Nail 2");
      		player[playerindex1].texttoenails[2] = const_cast<char*>("Toe Nail 3");
      		player[playerindex1].texttoenails[3] = const_cast<char*>("Toe Nail 4");
      		player[playerindex1].texttoenails[4] = const_cast<char*>("Toe Nail 5");
    		player[playerindex1].texttoenails[5] = const_cast<char*>("Toe Nail 6");
		player[playerindex1].texteyes[0] = const_cast<char*>("Eye 1");
		player[playerindex1].texteyes[1] = const_cast<char*>("Eye 2");
		player[playerindex1].texteyes[2] = const_cast<char*>("Eye 3");
		player[playerindex1].texteyes[3] = const_cast<char*>("Eye 4");
		player[playerindex1].texteyes[4] = const_cast<char*>("Eye 5");
		player[playerindex1].texteyes[5] = const_cast<char*>("Eye 6");
		player[playerindex1].textlips[0] = const_cast<char*>("Lip 1");
		player[playerindex1].textlips[1] = const_cast<char*>("Lip 2");
		player[playerindex1].textlips[2] = const_cast<char*>("Lip 3");
		player[playerindex1].textlips[3] = const_cast<char*>("Lip 4");
		player[playerindex1].textlips[4] = const_cast<char*>("Lip 5");
		player[playerindex1].textlips[5] = const_cast<char*>("Lip 6");
		player[playerindex1].textfeet[0] = const_cast<char*>("Foot 1");
		player[playerindex1].textfeet[1] = const_cast<char*>("Foot 2");
		player[playerindex1].textfeet[2] = const_cast<char*>("Foot 3");
		player[playerindex1].textfeet[3] = const_cast<char*>("Foot 4");
		player[playerindex1].textfeet[4] = const_cast<char*>("Foot 5");
		player[playerindex1].textfeet[5] = const_cast<char*>("Foot 6");
		player[playerindex1].textteeth[0] = const_cast<char*>("Tooth 1");
		player[playerindex1].textteeth[1] = const_cast<char*>("Tooth 2");
		player[playerindex1].textteeth[2] = const_cast<char*>("Tooth 3");
		player[playerindex1].textteeth[3] = const_cast<char*>("Tooth 4");
		player[playerindex1].textteeth[4] = const_cast<char*>("Tooth 5");
		player[playerindex1].textteeth[5] = const_cast<char*>("Tooth 6");
		player[playerindex1].texthair[0] = const_cast<char*>("Hair 1");
		player[playerindex1].texthair[1] = const_cast<char*>("Hair 2");
		player[playerindex1].texthair[2] = const_cast<char*>("Hair 3");
		player[playerindex1].texthair[3] = const_cast<char*>("Hair 4");
		player[playerindex1].texthair[4] = const_cast<char*>("Hair 5");
		player[playerindex1].texthair[5] = const_cast<char*>("Hair 6");
	}

	for (enemiesindex1 = 0; enemiesindex1 <= enemiesindex1_max; enemiesindex1++)
	{
		if (rowpos2 == 1)
		{
			enemy[enemiesindex1].textheads[0] = const_cast<char*>("Head 1");
			enemy[enemiesindex1].textheads[1] = const_cast<char*>("Head 2");
			enemy[enemiesindex1].textarms[0] = const_cast<char*>("Arm 1");
			enemy[enemiesindex1].textarms[1] = const_cast<char*>("Arm 2");
			enemy[enemiesindex1].textlegs[0] = const_cast<char*>("Leg 1");
			enemy[enemiesindex1].textlegs[1] = const_cast<char*>("Leg 2");
			enemy[enemiesindex1].textnecks[0] = const_cast<char*>("Neck 1");
			enemy[enemiesindex1].textnecks[1] = const_cast<char*>("Neck 2");
			enemy[enemiesindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
			enemy[enemiesindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
			enemy[enemiesindex1].textbacks[0] = const_cast<char*>("Back 1");
			enemy[enemiesindex1].textbacks[1] = const_cast<char*>("Back 2");
			enemy[enemiesindex1].textchests[0] = const_cast<char*>("Chest 1");
			enemy[enemiesindex1].textchests[1] = const_cast<char*>("Chest 2");
			enemy[enemiesindex1].texttoes[0] = const_cast<char*>("Toe 1");
			enemy[enemiesindex1].texttoes[1] = const_cast<char*>("Toe 2");
			enemy[enemiesindex1].textwrists[0] = const_cast<char*>("Wrist 1");
			enemy[enemiesindex1].textwrists[1] = const_cast<char*>("Wrist 2");
			enemy[enemiesindex1].textwaists[0] = const_cast<char*>("Waist 1");
			enemy[enemiesindex1].textwaists[1] = const_cast<char*>("Waist 2");
			enemy[enemiesindex1].textnails[0] = const_cast<char*>("Nail 1");
			enemy[enemiesindex1].textnails[1] = const_cast<char*>("Nail 2");
			enemy[enemiesindex1].texttoenails[0] = const_cast<char*>("Toe Nail 1");
			enemy[enemiesindex1].texttoenails[1] = const_cast<char*>("Toe Nail 2");
			enemy[enemiesindex1].texteyes[0] = const_cast<char*>("Eye 1");
			enemy[enemiesindex1].texteyes[1] = const_cast<char*>("Eye 2");
			enemy[enemiesindex1].textlips[0] = const_cast<char*>("Lip 1");
			enemy[enemiesindex1].textlips[1] = const_cast<char*>("Lip 2");
			enemy[enemiesindex1].textfeet[0] = const_cast<char*>("Foot 1");
			enemy[enemiesindex1].textfeet[1] = const_cast<char*>("Foot 2");
			enemy[enemiesindex1].textteeth[0] = const_cast<char*>("Tooth 1");
			enemy[enemiesindex1].textteeth[1] = const_cast<char*>("Tooth 2");
			enemy[enemiesindex1].texthair[0] = const_cast<char*>("Hair 1");
			enemy[enemiesindex1].texthair[1] = const_cast<char*>("Hair 2");
		}

		if (rowpos2 == 2)
		{
			enemy[enemiesindex1].textheads[0] = const_cast<char*>("Head 1");
			enemy[enemiesindex1].textheads[1] = const_cast<char*>("Head 2");
			enemy[enemiesindex1].textheads[2] = const_cast<char*>("Head 3");
			enemy[enemiesindex1].textarms[0] = const_cast<char*>("Arm 1");
			enemy[enemiesindex1].textarms[1] = const_cast<char*>("Arm 2");
			enemy[enemiesindex1].textarms[2] = const_cast<char*>("Arm 3");
			enemy[enemiesindex1].textlegs[0] = const_cast<char*>("Leg 1");
			enemy[enemiesindex1].textlegs[1] = const_cast<char*>("Leg 2");
			enemy[enemiesindex1].textlegs[2] = const_cast<char*>("Leg 3");
			enemy[enemiesindex1].textnecks[0] = const_cast<char*>("Neck 1");
			enemy[enemiesindex1].textnecks[1] = const_cast<char*>("Neck 2");
			enemy[enemiesindex1].textnecks[2] = const_cast<char*>("Neck 3");
			enemy[enemiesindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
			enemy[enemiesindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
			enemy[enemiesindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
			enemy[enemiesindex1].textbacks[0] = const_cast<char*>("Back 1");
			enemy[enemiesindex1].textbacks[1] = const_cast<char*>("Back 2");
			enemy[enemiesindex1].textbacks[2] = const_cast<char*>("Back 3");
			enemy[enemiesindex1].textchests[0] = const_cast<char*>("Chest 1");
			enemy[enemiesindex1].textchests[1] = const_cast<char*>("Chest 2");
			enemy[enemiesindex1].textchests[2] = const_cast<char*>("Chest 3");
			enemy[enemiesindex1].texttoes[0] = const_cast<char*>("Toe 1");
			enemy[enemiesindex1].texttoes[1] = const_cast<char*>("Toe 2");
			enemy[enemiesindex1].texttoes[2] = const_cast<char*>("Toe 3");
			enemy[enemiesindex1].textwrists[0] = const_cast<char*>("Wrist 1");
			enemy[enemiesindex1].textwrists[1] = const_cast<char*>("Wrist 2");
			enemy[enemiesindex1].textwrists[2] = const_cast<char*>("Wrist 3");
			enemy[enemiesindex1].textwaists[0] = const_cast<char*>("Waist 1");
			enemy[enemiesindex1].textwaists[1] = const_cast<char*>("Waist 2");
			enemy[enemiesindex1].textwaists[2] = const_cast<char*>("Waist 3");
			enemy[enemiesindex1].textnails[0] = const_cast<char*>("Nail 1");
			enemy[enemiesindex1].textnails[1] = const_cast<char*>("Nail 2");
			enemy[enemiesindex1].textnails[2] = const_cast<char*>("Nail 3");
			enemy[enemiesindex1].texttoenails[0] = const_cast<char*>("Toe Nail 1");
			enemy[enemiesindex1].texttoenails[1] = const_cast<char*>("Toe Nail 2");
			enemy[enemiesindex1].texttoenails[2] = const_cast<char*>("Toe Nail 3");
			enemy[enemiesindex1].texteyes[0] = const_cast<char*>("Eye 1");
			enemy[enemiesindex1].texteyes[1] = const_cast<char*>("Eye 2");
			enemy[enemiesindex1].texteyes[2] = const_cast<char*>("Eye 3");
			enemy[enemiesindex1].textlips[0] = const_cast<char*>("Lip 1");
			enemy[enemiesindex1].textlips[1] = const_cast<char*>("Lip 2");
			enemy[enemiesindex1].textlips[2] = const_cast<char*>("Lip 3");
			enemy[enemiesindex1].textfeet[0] = const_cast<char*>("Foot 1");
			enemy[enemiesindex1].textfeet[1] = const_cast<char*>("Foot 2");
			enemy[enemiesindex1].textfeet[2] = const_cast<char*>("Foot 3");
			enemy[enemiesindex1].textteeth[0] = const_cast<char*>("Tooth 1");
			enemy[enemiesindex1].textteeth[1] = const_cast<char*>("Tooth 2");
			enemy[enemiesindex1].textteeth[2] = const_cast<char*>("Tooth 3");
			enemy[enemiesindex1].texthair[0] = const_cast<char*>("Hair 1");
			enemy[enemiesindex1].texthair[1] = const_cast<char*>("Hair 2");
			enemy[enemiesindex1].texthair[2] = const_cast<char*>("Hair 3");
		}

		if (rowpos2 == 3)
		{
			enemy[enemiesindex1].textheads[0] = const_cast<char*>("Head 1");
			enemy[enemiesindex1].textheads[1] = const_cast<char*>("Head 2");
			enemy[enemiesindex1].textheads[2] = const_cast<char*>("Head 3");
			enemy[enemiesindex1].textheads[3] = const_cast<char*>("Head 4");
			enemy[enemiesindex1].textarms[0] = const_cast<char*>("Arm 1");
			enemy[enemiesindex1].textarms[1] = const_cast<char*>("Arm 2");
			enemy[enemiesindex1].textarms[2] = const_cast<char*>("Arm 3");
			enemy[enemiesindex1].textarms[3] = const_cast<char*>("Arm 4");
			enemy[enemiesindex1].textlegs[0] = const_cast<char*>("Leg 1");
			enemy[enemiesindex1].textlegs[1] = const_cast<char*>("Leg 2");
			enemy[enemiesindex1].textlegs[2] = const_cast<char*>("Leg 3");
			enemy[enemiesindex1].textlegs[3] = const_cast<char*>("Leg 4");
			enemy[enemiesindex1].textnecks[0] = const_cast<char*>("Neck 1");
			enemy[enemiesindex1].textnecks[1] = const_cast<char*>("Neck 2");
			enemy[enemiesindex1].textnecks[2] = const_cast<char*>("Neck 3");
			enemy[enemiesindex1].textnecks[3] = const_cast<char*>("Neck 4");
			enemy[enemiesindex1].textshoulders[0] = const_cast<char*>("Shoulder 1");
			enemy[enemiesindex1].textshoulders[1] = const_cast<char*>("Shoulder 2");
			enemy[enemiesindex1].textshoulders[2] = const_cast<char*>("Shoulder 3");
			enemy[enemiesindex1].textshoulders[3] = const_cast<char*>("Shoulder 4");
			enemy[enemiesindex1].textbacks[0] = const_cast<char*>("Back 1");
			enemy[enemiesindex1].textbacks[1] = const_cast<char*>("Back 2");
			enemy[enemiesindex1].textbacks[2] = const_cast<char*>("Back 3");
			enemy[enemiesindex1].textbacks[3] = const_cast<char*>("Back 4");
			enemy[enemiesindex1].textchests[0] = const_cast<char*>("Chest 1");
			enemy[enemiesindex1].textchests[1] = const_cast<char*>("Chest 2");
			enemy[enemiesindex1].textchests[2] = const_cast<char*>("Chest 3");
			enemy[enemiesindex1].textchests[3] = const_cast<char*>("Chest 4");
			enemy[enemiesindex1].texttoes[0] = const_cast<char*>("Toe 1");
			enemy[enemiesindex1].texttoes[1] = const_cast<char*>("Toe 2");
			enemy[enemiesindex1].texttoes[2] = const_cast<char*>("Toe 3");
			enemy[enemiesindex1].texttoes[3] = const_cast<char*>("Toe 4");
			enemy[enemiesindex1].textwrists[0] = const_cast<char*>("Wrist 1");
			enemy[enemiesindex1].textwrists[1] = const_cast<char*>("Wrist 2");
			enemy[enemiesindex1].textwrists[2] = const_cast<char*>("Wrist 3");
			enemy[enemiesindex1].textwrists[3] = const_cast<char*>("Wrist 4");
			enemy[enemiesindex1].textwaists[0] = const_cast<char*>("Waist 1");
			enemy[enemiesindex1].textwaists[1] = const_cast<char*>("Waist 2");
			enemy[enemiesindex1].textwaists[2] = const_cast<char*>("Waist 3");
			enemy[enemiesindex1].textwaists[3] = const_cast<char*>("Waist 4");
			enemy[enemiesindex1].textnails[0] = const_cast<char*>("Nail 1");
			enemy[enemiesindex1].textnails[1] = const_cast<char*>("Nail 2");
			enemy[enemiesindex1].textnails[2] = const_cast<char*>("Nail 3");
			enemy[enemiesindex1].textnails[3] = const_cast<char*>("Nail 4");
			enemy[enemiesindex1].texttoenails[0] = const_cast<char*>("Toe Nail 1");
			enemy[enemiesindex1].texttoenails[1] = const_cast<char*>("Toe Nail 2");
			enemy[enemiesindex1].texttoenails[2] = const_cast<char*>("Toe Nail 3");
			enemy[enemiesindex1].texttoenails[3] = const_cast<char*>("Toe Nail 4");
			enemy[enemiesindex1].texteyes[0] = const_cast<char*>("Eye 1");
			enemy[enemiesindex1].texteyes[1] = const_cast<char*>("Eye 2");
			enemy[enemiesindex1].texteyes[2] = const_cast<char*>("Eye 3");
			enemy[enemiesindex1].texteyes[3] = const_cast<char*>("Eye 4");
			enemy[enemiesindex1].textlips[0] = const_cast<char*>("Lip 1");
			enemy[enemiesindex1].textlips[1] = const_cast<char*>("Lip 2");
			enemy[enemiesindex1].textlips[2] = const_cast<char*>("Lip 3");
			enemy[enemiesindex1].textlips[3] = const_cast<char*>("Lip 4");
			enemy[enemiesindex1].textfeet[0] = const_cast<char*>("Foot 1");
			enemy[enemiesindex1].textfeet[1] = const_cast<char*>("Foot 2");
			enemy[enemiesindex1].textfeet[2] = const_cast<char*>("Foot 3");
			enemy[enemiesindex1].textfeet[3] = const_cast<char*>("Foot 4");
			enemy[enemiesindex1].textteeth[0] = const_cast<char*>("Tooth 1");
			enemy[enemiesindex1].textteeth[1] = const_cast<char*>("Tooth 2");
			enemy[enemiesindex1].textteeth[2] = const_cast<char*>("Tooth 3");
			enemy[enemiesindex1].textteeth[3] = const_cast<char*>("Tooth 4");
			enemy[enemiesindex1].texthair[0] = const_cast<char*>("Hair 1");
			enemy[enemiesindex1].texthair[1] = const_cast<char*>("Hair 2");
			enemy[enemiesindex1].texthair[2] = const_cast<char*>("Hair 3");
			enemy[enemiesindex1].texthair[3] = const_cast<char*>("Hair 4");
		}
	}

	

	for (enemiesindex1 = 0; enemiesindex1 <= enemiesindex1_max; enemiesindex1++)
	{
		if (enemy[enemiesindex1].enemiesposx >= mapwidth)
		{
			enemy[enemiesindex1].enemiesposx = -enemy[enemiesindex1].enemiesposx + mapwidth;
		}
		if (enemy[enemiesindex1].enemiesposy >= mapheight)
		{
			enemy[enemiesindex1].enemiesposy = -enemy[enemiesindex1].enemiesposy + mapheight;
		}
	}

	for (int enemiesindex1 = 0; enemiesindex1 <= enemiesindex1_max; enemiesindex1++)
	{
		if (player[playerindex1].playerposx == enemy[enemiesindex1].enemiesposx && player[playerindex1].playerposy == enemy[enemiesindex1].enemiesposy)
		{
			enemy[enemiesindex1].enemiesposx = rand() % (2 * mapwidth);
			enemy[enemiesindex1].enemiesposy = rand() % (2 * mapheight);

			if (enemy[enemiesindex1].enemiesposx >= mapwidth)
			{
				enemy[enemiesindex1].enemiesposx = -enemy[enemiesindex1].enemiesposx + mapwidth;
			}
			if (enemy[enemiesindex1].enemiesposy >= mapheight)
			{
				enemy[enemiesindex1].enemiesposy = -enemy[enemiesindex1].enemiesposy + mapheight;
			}
		}
	}

	for (int enemiesindex1 = 0; enemiesindex1 <= enemiesindex1_max; enemiesindex1++)
	{
		if (enemy[enemiesindex1].enemiesposx == enemy[enemiesindex1].enemiesposx && enemy[enemiesindex1].enemiesposy == enemy[enemiesindex1].enemiesposy)
		{
			enemy[enemiesindex1].enemiesposx = rand() % (2*mapwidth);
			enemy[enemiesindex1].enemiesposy = rand() % (2*mapheight);

			if (enemy[enemiesindex1].enemiesposx >= mapwidth)
			{
				enemy[enemiesindex1].enemiesposx = -enemy[enemiesindex1].enemiesposx + mapwidth;
			}
			if (enemy[enemiesindex1].enemiesposy >= mapheight)
			{
				enemy[enemiesindex1].enemiesposy = -enemy[enemiesindex1].enemiesposy + mapheight;
			}
		}
	}
	
	initscr();
	#if defined(__MINIX3__)
		resizeterm(mapheight, mapwidth);
	#else
		resize_term(mapheight, mapwidth);
	#endif

	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	for (enemiesindex1 = 0; enemiesindex1 <= enemiesindex1_max; enemiesindex1++)
	{
		enemyvisibley = (enemy[enemiesindex1].enemiesposy / height);
		enemyvisiblex = (enemy[enemiesindex1].enemiesposx / width);

		if (enemyvisibley == (player[playerindex1].playerposy / height))
		{
			if (enemyvisiblex == (player[playerindex1].playerposx / width))
			{
				if (enemy[enemiesindex1].enemiesposy >= 0 && enemy[enemiesindex1].enemiesposx >= 0)
				{
					mvprintw(abs(enemy[enemiesindex1].enemiesposy % height), abs(enemy[enemiesindex1].enemiesposx % width), "%s", enemy[enemiesindex1].character1);
				}
				else if (enemy[enemiesindex1].enemiesposy >= 0 && enemy[enemiesindex1].enemiesposx < 0)
				{
					mvprintw(abs(enemy[enemiesindex1].enemiesposy % height), width - abs(enemy[enemiesindex1].enemiesposx % width), "%s", enemy[enemiesindex1].character1);
				}
				else if (enemy[enemiesindex1].enemiesposy < 0 && enemy[enemiesindex1].enemiesposx < 0)
				{
					mvprintw(height - abs(enemy[enemiesindex1].enemiesposy % height), width - abs(enemy[enemiesindex1].enemiesposx % width), "%s", enemy[enemiesindex1].character1);
				}
				else
				{
					mvprintw(height - abs(enemy[enemiesindex1].enemiesposy % height), abs(enemy[enemiesindex1].enemiesposx % width), "%s", enemy[enemiesindex1].character1);
				}
			}
		}
	}
	
	for (int i = 0; i <= neutralindex1_max; i++)
	{
		enemyvisibley = (player[playerindex1].playerposy / height);
		enemyvisiblex = (player[playerindex1].playerposx / width);

		if (enemyvisibley == (player[playerindex1].neutralposy[i] / height))
		{
			if (enemyvisiblex == (player[playerindex1].neutralposx[i] / width))
			{
				if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx >= 0)
				{
					mvprintw(abs(player[playerindex1].neutralposy[i] % height), abs(player[playerindex1].neutralposx[i] % width), "%s", player[playerindex1].neutralsigns[i]);
				}
				else if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx < 0)
				{
					mvprintw(abs(player[playerindex1].neutralposy[i] % height), width - abs(player[playerindex1].neutralposx[i] % width), "%s", player[playerindex1].neutralsigns[i]);
				}
				else if (player[playerindex1].playerposy < 0 && player[playerindex1].playerposx < 0)
				{
					mvprintw(height - abs(player[playerindex1].neutralposy[i] % height), width - abs(player[playerindex1].neutralposx[i] % width), "%s", player[playerindex1].neutralsigns[i]);
				}
				else
				{
					mvprintw(height - abs(player[playerindex1].neutralposy[i] % height), abs(player[playerindex1].neutralposx[i] % width), "%s", player[playerindex1].neutralsigns[i]);
				}
			}
		}
	}
	
	int loopcount = 0;
	int posx = player[playerindex1].playerposx;
	int posy = player[playerindex1].playerposy;
	
	if (posy >= 0 && posx >= 0)
	{
		mvprintw(abs(posy % height), abs(posx % width), "%s", player[playerindex1].character1);
		move(abs(posy % height), abs(posx % width));
	}
	else if (posy >= 0 && posx < 0)
	{
		mvprintw(abs(posy % height), width - abs(posx % width), "%s", player[playerindex1].character1);
		move(abs(posy % height), width - abs(posx % width));
	}
	else if (posy < 0 && posx < 0)
	{
		mvprintw(height - abs(posy % height), width - abs(posx % width), "%s", player[playerindex1].character1);
		move(height - abs(posy % height), width - abs(posx % width));
	}
	else
	{
		mvprintw(height - abs(posy % height), abs(posx % width), "%s", player[playerindex1].character1);
		move(height - abs(posy % height), abs(posx % width));
	}

	refresh();
	
	while((ch = getch()) != 'q')
	{
		clear();

		if(ch == 'f')
		{
			playermovement = !playermovement;

			if(playermovement != 0)
			{
				clear();

				for(int j = -1; j <= 1; j++)
				{
					for(int i = -3; i <= 3; i++)
					{
						if((player[playerindex1].playerposx+i > -2*mapwidth && player[playerindex1].playerposy+j > -2*mapheight) || (player[playerindex1].playerposx+i > -2*mapwidth && player[playerindex1].playerposy+j < 2*mapheight) || (player[playerindex1].playerposx+i < 2*mapwidth && player[playerindex1].playerposy+j > -2*mapheight) || (player[playerindex1].playerposx+i < 2*mapwidth && player[playerindex1].playerposy+j < 2*mapheight))
						{

							if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx >= 0)
							{
								mvprintw(abs((player[playerindex1].playerposy+j) % height), abs((player[playerindex1].playerposx+i) % width), "P");
							}
							else if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx < 0)
							{
								mvprintw(abs((player[playerindex1].playerposy+j) % height), width - abs((player[playerindex1].playerposx+i) % width), "P");
							}
							else if (player[playerindex1].playerposy < 0 && player[playerindex1].playerposx < 0)
							{
								mvprintw(height - abs((player[playerindex1].playerposy+j) % height), width - abs((player[playerindex1].playerposx+i) % width), "P");
							}
							else
							{
								mvprintw(height - abs((player[playerindex1].playerposy+j) % height), abs((player[playerindex1].playerposx+i) % width), "P");
							}
						}
						
						if(i == 3 && j == 1)
						{
							for(int o=0; o <= enemiesamount; o++)
							{
							if((player[playerindex1].playerposx != enemy[o].enemiesposx) && (player[playerindex1].playerposy != enemy[o].enemiesposy))
							{	
								if (posy >= 0 && posx >= 0)
								{
									mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
									move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
								}
								else if (posy >= 0 && posx < 0)
								{
									mvprintw(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
									move(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
								}
								else if (posy < 0 && posx < 0)
								{
									mvprintw(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
									move(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
								}
								else
								{
									mvprintw(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
									move(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
								}
							}
							else
							{
								if (posy >= 0 && posx >= 0)
								{
									mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
									move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
								}
								else if (posy >= 0 && posx < 0)
								{
									mvprintw(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
									move(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
								}
								else if (posy < 0 && posx < 0)
								{
									mvprintw(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
									move(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
								}
								else
								{
									mvprintw(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
									move(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
								}
							}
							}
									
							refresh();
						}
					}
				}

				while((ch = getch()) != 'g')
				{
					clear();

					if(loopcount == 0)
					{
						posx = player[playerindex1].playerposx;
						posy = player[playerindex1].playerposy;
						loopcount++;
						clear();
					}

					if(ch == 'a')
					{
						posx--;

						for (int j = 0; j < enemiesamount; j++)
						{
							if ((posx == enemy[j].enemiesposx) && (posy == enemy[j].enemiesposy))
							{
								posx++;
							}
						}
					}
					if(ch == 'd')
					{
						posx++;

						for (int j = 0; j < enemiesamount; j++)
						{
							if ((posx == enemy[j].enemiesposx) && (posy == enemy[j].enemiesposy))
							{
								posx--;
							}
						}
					}
					if(ch == 'w')
					{
						posy--;

						for (int j = 0; j < enemiesamount; j++)
						{
							if ((posx == enemy[j].enemiesposx) && (posy == enemy[j].enemiesposy))
							{
								posy++;
							}
						}
					}
					if(ch == 's')
					{
						posy++;

						for (int j = 0; j < enemiesamount; j++)
						{
							if ((posx == enemy[j].enemiesposx) && (posy == enemy[j].enemiesposy))
							{
								posy--;
							}
						}
					}

					for(int j = -1; j <= 1; j++)
					{
						for(int i = -3; i <= 3; i++)
						{
							if((player[playerindex1].playerposx+i > -2*mapwidth && player[playerindex1].playerposy+j > -2*mapheight) || (player[playerindex1].playerposx+i > -2*mapwidth && player[playerindex1].playerposy+j < 2*mapheight) || (player[playerindex1].playerposx+i < 2*mapwidth && player[playerindex1].playerposy+j > -2*mapheight) || (player[playerindex1].playerposx+i < 2*mapwidth && player[playerindex1].playerposy+j < 2*mapheight))
							{
								if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx >= 0)
								{
									mvprintw(abs(player[playerindex1].playerposy % height) + j, abs(player[playerindex1].playerposx % width) + i, "P");
									move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
								}
								else if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx < 0)
								{
									mvprintw(abs(player[playerindex1].playerposy % height) + j, width - abs(player[playerindex1].playerposx % width) + i, "P");
									move(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
								}
								else if (player[playerindex1].playerposy < 0 && player[playerindex1].playerposx < 0)
								{
									mvprintw(height - abs(player[playerindex1].playerposy % height) + j, width - abs(player[playerindex1].playerposx % width) + i, "P");
									move(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
								}
								else
								{
									mvprintw(height - abs(player[playerindex1].playerposy % height) + j, abs(player[playerindex1].playerposx % width) + i, "P");
									move(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
								}
							}
							if(i == 3 && j == 1)
							{

								if (posy >= 0 && posx >= 0)
								{
									mvprintw(abs(posy % height), abs(posx % width), "%s", player[playerindex1].character1);
									move(abs(posy % height), abs(posx % width));
								}
								else if (posy >= 0 && posx < 0)
								{
									mvprintw(abs(posy % height), width - abs(posx % width), "%s", player[playerindex1].character1);
									move(abs(posy % height), width - abs(posx % width));
								}
								else if (posy < 0 && posx < 0)
								{
									mvprintw(height - abs(posy % height), width - abs(posx % width), "%s", player[playerindex1].character1);
									move(height - abs(posy % height), width - abs(posx % width));
								}
								else
								{
									mvprintw(height - abs(posy % height), abs(posx % width), "%s", player[playerindex1].character1);
									move(height - abs(posy % height), abs(posx % width));
								}
								refresh();
							}
						}
					}
					
					if(ch == 'q')
					{
						if((abs(posx - player[playerindex1].playerposx) <= 3) && (abs(posy - player[playerindex1].playerposy) <= 1))
						{
							player[playerindex1].playerposx = posx;
							player[playerindex1].playerposy = posy;
						}
					}
				}
			}
		}

		loopcount = 0;
		
		if(ch == 'a')
		{
			if(playermovement == 1)
			{
			} 
			else if(playermovement == 0)
			{
				player[playerindex1].playerposx--;

				for(int i = 0; i < enemiesamountreal; i++)
				{
					if(player[playerindex1].playerposx == enemy[i].enemiesposx && player[playerindex1].playerposy == enemy[i].enemiesposy)
					{
						player[playerindex1].playerposx++;
					}
				}

				if(player[playerindex1].playerposx < 0 && player[playerindex1].playerposx < -mapwidth)
				{
					player[playerindex1].playerposx = -mapwidth;
				}
			}
		}

		if(ch == 'd')
		{
			if(playermovement == 1)
			{
			}
			else if(playermovement == 0)
			{
				player[playerindex1].playerposx++;

				for(int i = 0; i < enemiesamountreal; i++)
				{
					if(player[playerindex1].playerposx == enemy[i].enemiesposx && player[playerindex1].playerposy == enemy[i].enemiesposy)
					{
						player[playerindex1].playerposx--;
					}
				}

				if(player[playerindex1].playerposx > mapwidth)
				{
					player[playerindex1].playerposx = mapwidth;
				}
			}
		}

		if(ch == 'w')
		{
			if(playermovement == 1)
			{
			}
			else if(playermovement == 0)
			{
				player[playerindex1].playerposy--;

				for(int i = 0; i < enemiesamountreal; i++)
				{
					if(player[playerindex1].playerposx == enemy[i].enemiesposx && player[playerindex1].playerposy == enemy[i].enemiesposy)
					{
						player[playerindex1].playerposy++;
					}
				}

				if(player[playerindex1].playerposy < 0 && player[playerindex1].playerposy < -mapheight)
				{
					player[playerindex1].playerposy = -mapheight;
				}
			}
		}

		if(ch == 's')
		{
			if(playermovement == 1)
			{
			}
			else if(playermovement == 0)
			{
				player[playerindex1].playerposy++;

				for(int i = 0; i < enemiesamountreal; i++)
				{
					if(player[playerindex1].playerposx == enemy[i].enemiesposx && player[playerindex1].playerposy == enemy[i].enemiesposy)
					{
						player[playerindex1].playerposy--;
					}
				}

				if(player[playerindex1].playerposy > mapheight)
				{
					player[playerindex1].playerposy = mapheight;
				}
			}
		}

		if (ch == 'c')
		{
			statcharacter++;

			if(statcharacter > enemiesamount)
			{
				statcharacter = 0;
			}
			
			mvprintw(0 % height, 0 % width, "Enemy %d is at %d, %d", statcharacter + 1, enemy[statcharacter].enemiesposx, enemy[statcharacter].enemiesposy);
			mvprintw(1 % height, 0 % width, "Player %d is at %d, %d", playerindex1 + 1, player[playerindex1].playerposx, player[playerindex1].playerposy);
		}

		refresh();

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
			mvprintw(screeny, screenx, "Press q to exit the game");
			screeny++;
			mvprintw(screeny, screenx, "Press a key to exit this help");
			screeny++;
			mvprintw(screeny, screenx, "Press c to view enemy positions");
			screeny++;
			mvprintw(screeny, screenx, "Press f to toggle attack movement on and off. a,d,w,s to move around. q to update position and then press g and then f to exit attack movement");
			
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
					mvprintw(i%24+5, 0, "%s", player[playerindex1].textheads[i]);
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
					mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textarms[i]);
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
					mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textlegs[i]);
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
					mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textnecks[i]);
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
					mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textshoulders[i]);
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
					mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textbacks[i]);
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
					mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textchests[i]);
				}
			}
			if(itempos1 == 7)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Toes");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].texttoes[i]);
				}
			}
			if(itempos1 == 8)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Wrists");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].textwrists[i]);
				}
			}
			if(itempos1 == 9)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Waists");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].textwaists[i]);
				}
			}
			if(itempos1 == 10)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Nails");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].textnails[i]);
				}
			}
			if(itempos1 == 11)
         		{	
            			mvprintw(0, 0, "Press e to move up");
            			mvprintw(1, 0, "Press d to move down");
            			mvprintw(2, 0, "Press p to exit this screen");
            			mvprintw(3, 0, "Press n to view next body part");
            			mvprintw(4, 0, "Player Toe Nails");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].texttoenails[i]);
				}
			}
			if(itempos1 == 12)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Eyes");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].texteyes[i]);
				}
			}
			if(itempos1 == 13)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Lips");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].textlips[i]);
				}
			}
			if(itempos1 == 14)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Feet");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].textfeet[i]);
				}
			}
			if(itempos1 == 15)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Teeth");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].textteeth[i]);
				}
			}
			if(itempos1 == 16)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Player Hair");

				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, "%s", player[playerindex1].texthair[i]);
				}
			}

			refresh();

			while((ch = getch()) != 'p')
  			{
				switch (ch)
				{
				case 'n':
					itempos1++;

					if (itempos1 > 16)
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textheads[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textarms[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textlegs[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textnecks[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textshoulders[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textbacks[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textchests[i]);
						}
					}
					if(itempos1 == 7)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Toes");

						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].texttoes[i]);
						}
					}
					if(itempos1 == 8)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Wrists");

						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textwrists[i]);
						}
					}
					if(itempos1 == 9)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Waists");

						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textwaists[i]);
						}
					}
					if(itempos1 == 10)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Nails");

						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textnails[i]);
						}
					}
					if(itempos1 == 11)
               				{
                  				mvprintw(0, 0, "Press e to move up");
                  				mvprintw(1, 0, "Press d to move down");
                  				mvprintw(2, 0, "Press p to exit this screen");
                  				mvprintw(3, 0, "Press n to view next body part");
                  				mvprintw(4, 0, "Player Toe Nails");

                  				for(int i = 0; i <= indexpos1; i++)
                  				{
                     					mvprintw(i%24+5, 0, "%s", player[playerindex1].texttoenails[i]);
                  				}
               				}
					if(itempos1 == 12)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Eyes");

						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].texteyes[i]);
						}
					}
					if (itempos1 == 13)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Lips");
						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textlips[i]);
						}
					}
					if(itempos1 == 14)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Feet");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textfeet[i]);
						}
					}
					if(itempos1 == 15)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Teeth");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textteeth[i]);
						}
					}
					if(itempos1 == 16)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Hair");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].texthair[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textheads[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textarms[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textlegs[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textnecks[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textshoulders[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textbacks[i]);
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
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textchests[i]);
						}
					}
					if(itempos1 == 7)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Toes");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].texttoes[i]);
						}
					}
					if(itempos1 == 8)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Wrists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textwrists[i]);
						}
					}
					if(itempos1 == 9)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Waists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textwaists[i]);
						}
					}
					if(itempos1 == 10)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Nails");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textnails[i]);
						}
					}
					if(itempos1 == 11)
               				{
                  				mvprintw(0, 0, "Press e to move up");
                  				mvprintw(1, 0, "Press d to move down");
                  				mvprintw(2, 0, "Press p to exit this screen");
                  				mvprintw(3, 0, "Press n to view next body part");
                  				mvprintw(4, 0, "Player Toe Nails");
                  				
						for(int i = 0; i <= indexpos1; i++)
                  				{
                     					mvprintw(i%24+5, 0, "%s", player[playerindex1].texttoenails[i]);
                  				}
               				}
					if(itempos1 == 12)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Eyes");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].texteyes[i]);
						}
					}
					if (itempos1 == 13)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Lips");
						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textlips[i]);
						}
					}
					if(itempos1 == 14)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Feet");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textfeet[i]);
						}
					}
					if(itempos1 == 15)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Teeth");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].textteeth[i]);
						}
					}
					if(itempos1 == 16)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Hair");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s",  player[playerindex1].texthair[i]);
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
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textheads[i]);
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
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textarms[i]);
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
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textlegs[i]);
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
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textnecks[i]);
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
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textshoulders[i]);
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
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textbacks[i]);
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
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textchests[i]);
						}
					}
					if(itempos1 == 7)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Toes");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].texttoes[i]);
						}
					}
					if(itempos1 == 8)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Wrists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textwrists[i]);
						}
					}
					if(itempos1 == 9)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Waists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textwaists[i]);
						}
					}
					if(itempos1 == 10)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Nails");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].textnails[i]);
						}
					}
					if(itempos1 == 11)
               				{
                  				mvprintw(0, 0, "Press e to move up");
                  				mvprintw(1, 0, "Press d to move down");
                  				mvprintw(2, 0, "Press p to exit this screen");
                  				mvprintw(3, 0, "Press n to view next body part");
                  				mvprintw(4, 0, "Player Toe Nails");
                  
						for(int i = 0; i <= indexpos1; i++)
                  				{
                     					mvprintw(i%24+5, 0, "%s", player[playerindex1].texttoenails[i]);
                  				}
               				}
					if(itempos1 == 12)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Eyes");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, "%s", player[playerindex1].texteyes[i]);
						}
					}
					if (itempos1 == 13)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Lips");
						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textlips[i]);
						}
					}
					if(itempos1 == 14)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Feet");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textfeet[i]);
						}
					}
					if(itempos1 == 15)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Teeth");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].textteeth[i]);
						}
					}
					if(itempos1 == 16)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Player Hair");

						for (int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i % 24 + 5, 0, "%s", player[playerindex1].texthair[i]);
						}
					}

					refresh();
    					break;
     				}
			}
		}


		clear();

		for (enemiesindex1 = 0; enemiesindex1 <= enemiesindex1_max; enemiesindex1++)
		{
			enemyvisibley = (enemy[enemiesindex1].enemiesposy / height);
			enemyvisiblex = (enemy[enemiesindex1].enemiesposx / width);

			if (enemyvisibley == (player[playerindex1].playerposy / height))
			{
				if (enemyvisiblex == (player[playerindex1].playerposx / width))
				{
					if (enemy[enemiesindex1].enemiesposy >= 0 && enemy[enemiesindex1].enemiesposx >= 0)
					{
						mvprintw(abs(enemy[enemiesindex1].enemiesposy % height), abs(enemy[enemiesindex1].enemiesposx % width), "%s", enemy[enemiesindex1].character1);
					}
					else if (enemy[enemiesindex1].enemiesposy >= 0 && enemy[enemiesindex1].enemiesposx < 0)
					{
						mvprintw(abs(enemy[enemiesindex1].enemiesposy % height), width - abs(enemy[enemiesindex1].enemiesposx % width), "%s", enemy[enemiesindex1].character1);
					}
					else if (enemy[enemiesindex1].enemiesposy < 0 && enemy[enemiesindex1].enemiesposx < 0)
					{
						mvprintw(height - abs(enemy[enemiesindex1].enemiesposy % height), width - abs(enemy[enemiesindex1].enemiesposx % width), "%s", enemy[enemiesindex1].character1);
					}
					else
					{
						mvprintw(height - abs(enemy[enemiesindex1].enemiesposy % height), abs(enemy[enemiesindex1].enemiesposx % width), "%s", enemy[enemiesindex1].character1);
					}
				}
			}
		}

	for (int i = 0; i <= neutralindex1_max; i++)
	{
		enemyvisibley = (player[playerindex1].playerposy / height);
		enemyvisiblex = (player[playerindex1].playerposx / width);

		if (enemyvisibley == (player[playerindex1].neutralposy[i] / height))
		{
			if (enemyvisiblex == (player[playerindex1].neutralposx[i] / width))
			{
				if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx >= 0)
				{
					mvprintw(abs(player[playerindex1].neutralposy[i] % height), abs(player[playerindex1].neutralposx[i] % width), "%s", player[playerindex1].neutralsigns[i]);
				}
				else if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx < 0)
				{
					mvprintw(abs(player[playerindex1].neutralposy[i] % height), width - abs(player[playerindex1].neutralposx[i] % width), "%s", player[playerindex1].neutralsigns[i]);
				}
				else if (player[playerindex1].playerposy < 0 && player[playerindex1].playerposx < 0)
				{
					mvprintw(height - abs(player[playerindex1].neutralposy[i] % height), width - abs(player[playerindex1].neutralposx[i] % width), "%s", player[playerindex1].neutralsigns[i]);
				}
				else
				{
					mvprintw(height - abs(player[playerindex1].neutralposy[i] % height), abs(player[playerindex1].neutralposx[i] % width), "%s", player[playerindex1].neutralsigns[i]);
				}
			}
		}
	}
		

		if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx >= 0)
		{
			mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
			move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
		}
		else if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx < 0)
		{
			mvprintw(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
			move(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
		}
		else if (player[playerindex1].playerposy < 0 && player[playerindex1].playerposx < 0)
		{
			mvprintw(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
			move(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
		}
		else
		{
			mvprintw(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
			move(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
		}

		if (statcharacter != -1)
		{
			mvprintw(0 % height, 0 % width, "Enemy %d is at %d, %d", statcharacter + 1, enemy[statcharacter].enemiesposx, enemy[statcharacter].enemiesposy);
			mvprintw(1 % height, 0 % width, "Player %d is at %d, %d", playerindex1 + 1, player[playerindex1].playerposx, player[playerindex1].playerposy);
		}

		if(playermovement != 0)
		{
			clear();

			for(int j = -1; j <= 1; j++)
			{
				for(int i = -3; i <= 3; i++)
				{
					if((player[playerindex1].playerposx+i > -2*mapwidth && player[playerindex1].playerposy+j > -2*mapheight) || (player[playerindex1].playerposx+i > -2*mapwidth && player[playerindex1].playerposy+j < 2*mapheight) || (player[playerindex1].playerposx+i < 2*mapwidth && player[playerindex1].playerposy+j > -2*mapheight) || (player[playerindex1].playerposx+i < 2*mapwidth && player[playerindex1].playerposy+j < 2*mapheight))
					{
						if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx >= 0)
						{
							mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "P");
							move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
						}
						else if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx < 0)
						{
							mvprintw(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "P");
							move(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
						}
						else if (player[playerindex1].playerposy < 0 && player[playerindex1].playerposx < 0)
						{
							mvprintw(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "P");
							move(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
						}
						else
						{
							mvprintw(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "P");
							move(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
						}
					}

					if(i == 3 && j == 1)
					{
						if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx >= 0)
						{
							mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
							move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
						}
						else if (player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx < 0)
						{
							mvprintw(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
							move(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
						}
						else if (player[playerindex1].playerposy < 0 && player[playerindex1].playerposx < 0)
						{
							mvprintw(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
							move(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
						}
						else
						{
							mvprintw(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
							move(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
						}
						
						refresh();		
					}
				}
			}
		}
		else
		{
			if(player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx >= 0)
			{
				mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
				move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
			}
			else if(player[playerindex1].playerposy >= 0 && player[playerindex1].playerposx < 0)
			{
				mvprintw(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
				move(abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
			}
			else if(player[playerindex1].playerposy < 0 && player[playerindex1].playerposx < 0)
			{
				mvprintw(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
				move(height - abs(player[playerindex1].playerposy % height), width - abs(player[playerindex1].playerposx % width));
			}
			else
			{
				mvprintw(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), "%s", player[playerindex1].character1);
				move(height - abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));
			}

			refresh();
	        }
	}

	endwin();
	return 0;
}
