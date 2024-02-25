#ifndef __PLAYERCHARACTER_H
#define __PLAYERCHARACTER_H

#include "typeofobjects.h"

struct playercharacter
{
	char character1[2];
	int playerposx;
	int playerposy;
	int playerindex;
	char *weapons[10];
	struct typeofobject playerobject;
};

#endif
