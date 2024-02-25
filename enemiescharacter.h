#ifndef __ENEMIESCHARACTER_H
#define __ENEMIESCHARACTER_H

#include "typeofobjects.h"

struct enemiescharacter
{
	char character1[2];
	int enemiesposx;
	int enemiesposy;
	int enemiesindex;
	char *weapons[10];
	struct typeofobject enemiesobject;
};

#endif
