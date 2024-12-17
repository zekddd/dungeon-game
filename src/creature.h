/*
 * creature.h
 *
 *  Created on: 17 Ara 2024
 *      Author: zek
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"

typedef struct Creature {
	char name[MAX_NAME];
	int health;
	int attack;
	int gainStrength;
} Creature;

Creature* createCreature(const char *name, int health, int attack,
		int gainStrength);

#endif /* CREATURE_H_ */
