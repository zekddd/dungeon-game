/*
 * item.h
 *
 *  Created on: 17 Ara 2024
 *      Author: zek
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"

typedef struct Item {
	char name[MAX_NAME];
	int attackPower;
	int strRequirement;
	int gainStrength;
} Item;

Item* createItem(const char *name, int attackPower, int strRequirement,
		int gainStrength);

#endif /* ITEM_H_ */
