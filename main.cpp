#if defined(_WIN32)
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
	int screenindexx1 = 0;
	int screenindexy1 = 0;
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

	player[playerindex1].playerposx = rand() % width;
	player[playerindex1].playerposy = rand() % height;

	enemy[enemiesindex1].enemiesposx = rand() % width;
	enemy[enemiesindex1].enemiesposy = rand() % height;

	player[playerindex1].playerobject.player = 1;

	player[playerindex1].playerobject.enemy = 0;

	enemy[enemiesindex1].enemiesobject.enemy = 1;

	enemy[enemiesindex1].enemiesobject.player = 0;
	
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

	int counterindex1 = rand() % 4;
	FILE* fp2 = NULL;
			
	if(counterindex1 == 0)
	{
		fp2 = fopen("Data/EnemyCharacterDwarf.txt", "r");
	
		if (fp2 == NULL)
		{
			cout << "Can't open Data/EnemyCharacterDwarf.txt" << endl;

			return 0;
		}
	}

	if(counterindex1 == 1)
	{
		fp2 = fopen("Data/EnemyCharacterElf.txt", "r");

		if (fp2 == NULL)
		{
			cout << "Can't open Data/EnemyCharacterElf.txt" << endl;

			return 0;
		}
	}

	if(counterindex1 == 2)
	{
		fp2 = fopen("Data/EnemyCharacterHuman.txt", "r");

		if (fp2 == NULL)
		{
			cout << "Can't open Data/EnemyCharacterHumun.txt" << endl;

			return 0;
		}
	}

	if(counterindex1 == 3)
	{
		fp2 = fopen("Data/EnemyCharacterOrc.txt", "r");

		if (fp2 == NULL)
		{
			cout << "Can't open Data/EnemyCharacterOrc.txt" << endl;

			return 0;
		}
	}
	
	int characternow3 = fgetc(fp2);
	char characternow4 = (char)characternow3;

	enemy[enemiesindex1].character1[0] = characternow4;
	enemy[enemiesindex1].character1[1] = '\0';

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
	}

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
	}

	while(player[playerindex1].playerposx == enemy[enemiesindex1].enemiesposx && player[playerindex1].playerposy == enemy[enemiesindex1].enemiesposy)
	{
		enemy[enemiesindex1].enemiesposx = rand() % width;
		enemy[enemiesindex1].enemiesposy = rand() % height;
	}
	
	initscr();
	noecho();
	cbreak();

	enemyvisibley = abs(screenindexy1) / height;
	enemyvisiblex = abs(screenindexx1) / width;

	if(enemyvisibley == abs(enemy[enemiesindex1].enemiesposy / height))
	{
		if(enemyvisiblex == abs(enemy[enemiesindex1].enemiesposx / width))
		{
			mvprintw(abs(enemy[enemiesindex1].enemiesposy % height) , abs(enemy[enemiesindex1].enemiesposx % width), enemy[enemiesindex1].character1);
		}
	}

	mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), player[playerindex1].character1);
	move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));

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

			screenindexx1--;
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

			screenindexy1++;
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

			screenindexy1--;
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
		
			screenindexy1++;
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
			mvprintw(screeny, screenx, "Press v to view body parts for enemy in line of sight");
			screeny++;
			mvprintw(screeny, screenx, "Press q to exit the game");
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
					mvprintw(i%24+5, 0, player[playerindex1].textheads[i]);
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
					mvprintw(i % 24 + 5, 0, player[playerindex1].textarms[i]);
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
					mvprintw(i % 24 + 5, 0, player[playerindex1].textlegs[i]);
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
					mvprintw(i % 24 + 5, 0, player[playerindex1].textnecks[i]);
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
					mvprintw(i % 24 + 5, 0, player[playerindex1].textshoulders[i]);
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
					mvprintw(i % 24 + 5, 0, player[playerindex1].textbacks[i]);
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
					mvprintw(i % 24 + 5, 0, player[playerindex1].textchests[i]);
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
					mvprintw(i%24+5, 0, player[playerindex1].texttoes[i]);
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
					mvprintw(i%24+5, 0, player[playerindex1].textwrists[i]);
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
					mvprintw(i%24+5, 0, player[playerindex1].textwaists[i]);
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
					mvprintw(i%24+5, 0, player[playerindex1].textnails[i]);
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
               				mvprintw(i%24+5, 0, player[playerindex1].texttoenails[i]);
            			}
         		}

			refresh();

			while((ch = getch()) != 'p')
  			{
				switch (ch)
				{
				case 'n':
					itempos1++;

					if (itempos1 > 11)
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textheads[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textarms[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textlegs[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textnecks[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textshoulders[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textbacks[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textchests[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].texttoes[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textwrists[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textwaists[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textnails[i]);
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
                     					mvprintw(i%24+5, 0, player[playerindex1].texttoenails[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textheads[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textarms[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textlegs[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textnecks[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textshoulders[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textbacks[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textchests[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].texttoes[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textwrists[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textwaists[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textnails[i]);
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
                     					mvprintw(i%24+5, 0, player[playerindex1].texttoenails[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textheads[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textarms[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textlegs[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textnecks[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textshoulders[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textbacks[i]);
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
							mvprintw(i % 24 + 5, 0, player[playerindex1].textchests[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].texttoes[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textwrists[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textwaists[i]);
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
							mvprintw(i%24+5, 0, player[playerindex1].textnails[i]);
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
                     					mvprintw(i%24+5, 0, player[playerindex1].texttoenails[i]);
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
					mvprintw(i%24+5, 0, enemy[enemiesindex1].textheads[i]);
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
					mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textarms[i]);
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
					mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textlegs[i]);
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
					mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textnecks[i]);
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
					mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textshoulders[i]);
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
					mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textbacks[i]);
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
					mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textchests[i]);
				}
			}
			if(itempos1 == 7)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Toes");
				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, enemy[enemiesindex1].texttoes[i]);
				}
			}
			if(itempos1 == 8)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Wrists");
				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, enemy[enemiesindex1].textwrists[i]);
				}
			}
			if(itempos1 == 9)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Waists");
				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, enemy[enemiesindex1].textwaists[i]);
				}
			}
			if(itempos1 == 10)
			{
				mvprintw(0, 0, "Press e to move up");
				mvprintw(1, 0, "Press d to move down");
				mvprintw(2, 0, "Press p to exit this screen");
				mvprintw(3, 0, "Press n to view next body part");
				mvprintw(4, 0, "Enemies Nails");
				for(int i = 0; i <= indexpos1; i++)
				{
					mvprintw(i%24+5, 0, enemy[enemiesindex1].textnails[i]);
				}
			}
			if(itempos1 == 11)
         		{
            			mvprintw(0, 0, "Press e to move up");
            			mvprintw(1, 0, "Press d to move down");
            			mvprintw(2, 0, "Press p to exit this screen");
            			mvprintw(3, 0, "Press n to view next body part");
            			mvprintw(4, 0, "Enemies Toe Nails");
            			for(int i = 0; i <= indexpos1; i++)
            			{
               				mvprintw(i%24+5, 0, enemy[enemiesindex1].texttoenails[i]);
            			}
         		}

			refresh();

			while((ch = getch()) != 'p')
  			{
    			switch (ch)
    			{
				case 'n':
					itempos1++;

					if (itempos1 > 11)
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textheads[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textarms[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textlegs[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textnecks[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textshoulders[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textbacks[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textchests[i]);
						}
					}
					if(itempos1 == 7)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Toes");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].texttoes[i]);
						}
					}
					if(itempos1 == 8)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Wrists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textwrists[i]);
						}
					}
					if(itempos1 == 9)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Waists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textwaists[i]);
						}
					}
					if(itempos1 == 10)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Nails");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textnails[i]);
						}
					}
					if(itempos1 == 11)
         				{
            					mvprintw(0, 0, "Press e to move up");
            					mvprintw(1, 0, "Press d to move down");
            					mvprintw(2, 0, "Press p to exit this screen");
            					mvprintw(3, 0, "Press n to view next body part");
            					mvprintw(4, 0, "Enemies Toe Nails");
            					for(int i = 0; i <= indexpos1; i++)
            					{
               						mvprintw(i%24+5, 0, enemy[enemiesindex1].texttoenails[i]);
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
                                        		mvprintw(i%24+5, 0, enemy[enemiesindex1].textheads[i]);
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
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textarms[i]);
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
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textlegs[i]);
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
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textnecks[i]);
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
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textshoulders[i]);
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
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textbacks[i]);
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
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textchests[i]);
						}
					}
					if(itempos1 == 7)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Toes");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].texttoes[i]);
						}
					}
					if(itempos1 == 8)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Wrists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textwrists[i]);
						}
					}
					if(itempos1 == 9)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Waists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textwaists[i]);
						}
					}
					if(itempos1 == 10)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Nails");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textnails[i]);
						}
					}
					if(itempos1 == 11)
               				{
                  				mvprintw(0, 0, "Press e to move up");
                  				mvprintw(1, 0, "Press d to move down");
                  				mvprintw(2, 0, "Press p to exit this screen");
                  				mvprintw(3, 0, "Press n to view next body part");
                  				mvprintw(4, 0, "Enemies Toe Nails");
                  				for(int i = 0; i <= indexpos1; i++)
                  				{
                     					mvprintw(i%24+5, 0, enemy[enemiesindex1].texttoenails[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textheads[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textarms[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textlegs[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textnecks[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textshoulders[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textbacks[i]);
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
							mvprintw(i % 24 + 5, 0, enemy[enemiesindex1].textchests[i]);
						}
					}
					if(itempos1 == 7)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Toes");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].texttoes[i]);
						}
					}
					if(itempos1 == 8)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Wrists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textwrists[i]);
						}
					}
					if(itempos1 == 9)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Waists");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textwaists[i]);
						}
					}
					if(itempos1 == 10)
					{
						mvprintw(0, 0, "Press e to move up");
						mvprintw(1, 0, "Press d to move down");
						mvprintw(2, 0, "Press p to exit this screen");
						mvprintw(3, 0, "Press n to view next body part");
						mvprintw(4, 0, "Enemies Nails");
						for(int i = 0; i <= indexpos1; i++)
						{
							mvprintw(i%24+5, 0, enemy[enemiesindex1].textnails[i]);
						}
					}
					if(itempos1 == 11)
               				{
                  				mvprintw(0, 0, "Press e to move up");
                  				mvprintw(1, 0, "Press d to move down");
                  				mvprintw(2, 0, "Press p to exit this screen");
                  				mvprintw(3, 0, "Press n to view next body part");
                  				mvprintw(4, 0, "Enemies Toe Nails");
                  				for(int i = 0; i <= indexpos1; i++)
                  				{
                     					mvprintw(i%24+5, 0, enemy[enemiesindex1].texttoenails[i]);
                  				}
               				}
					refresh();
    					break;
     				}
			}
		}

		clear();

		enemyvisibley = abs(screenindexy1) / height;
        	enemyvisiblex = abs(screenindexx1) / width;

        	if(enemyvisibley == abs(enemy[enemiesindex1].enemiesposy) / height)
        	{
                	if(enemyvisiblex == abs(enemy[enemiesindex1].enemiesposx) / width)  
                	{
                        	mvprintw(abs(enemy[enemiesindex1].enemiesposy % height) , abs(enemy[enemiesindex1].enemiesposx % width), enemy[enemiesindex1].character1);
                	}
        	}

        	mvprintw(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width), player[playerindex1].character1);
        	move(abs(player[playerindex1].playerposy % height), abs(player[playerindex1].playerposx % width));

		refresh();
	}

	endwin();

	return 0;
}
