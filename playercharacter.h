#ifndef __PLAYERCHARACTER_H
#define __PLAYERCHARACTER_H

#include "typeofobjects.h"

struct playercharacter
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
	char *textfeet[10];
	char *textteeth[10];
	char *texthair[10];
	int playerposx;
	int playerposy;
	int playerindex;
	char *weapons[10];
	struct typeofobject playerobject;
	int level;
};

#endif
