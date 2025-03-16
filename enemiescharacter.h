#ifndef __ENEMIESCHARACTER_H
#define __ENEMIESCHARACTER_H

#include "typeofobjects.h"

struct enemiescharacter
{
	char character1[2];
	char *textheads[10];
	char *textarms[10];
	char *textlegs[10];
	char *textnecks[10];
	char *textshoulders[10];
	char *textbacks[10];
	char *textchests[10];
	char *texttoes[10];
	char *textwrists[10];
	char *textwaists[10];
	char *textnails[10];
	char *texttoenails[10];
	char *texteyes[10];
	char* textlips[10];
	char* textfeet[10];
	char* textteeth[10];
	int enemiesposx;
	int enemiesposy;
	int enemiesindex;
	char *weapons[10];
	struct typeofobject enemiesobject;
	int level;
};

#endif
