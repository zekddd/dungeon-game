/*
 * item.c
 *
 *  Created on: 17 Ara 2024
 *      Author: zek
 */
#include "item.h"

Item* createItem(const char *name, int attackPower, int strRequirement,
		int gainStrength) {
	Item *item = malloc(sizeof(Item));
	if (!item) {
		printf("Memory allocation failed for item.\n");
		exit(1);
	}

	strncpy(item->name, name, MAX_NAME);
	item->attackPower = attackPower;
	item->strRequirement = strRequirement;
	item->gainStrength = gainStrength;

	return item;
}
