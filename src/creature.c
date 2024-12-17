/*
 * creature.c
 *
 *  Created on: 17 Ara 2024
 *      Author: zek
 */
#include "creature.h"

Creature* createCreature(const char *name, int health, int attack,
		int gainStrength) {
	Creature *creature = malloc(sizeof(Creature));
	if (!creature) {
		printf("Memory allocation failed for creature.\n");
		exit(1);
	}

	strncpy(creature->name, name, MAX_NAME);
	creature->health = health;
	creature->attack = attack;
	creature->gainStrength = gainStrength;

	return creature;
}
