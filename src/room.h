/*
 * room.h
 *
 *  Created on: 17 Ara 2024
 *      Author: zek
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"
#include "creature.h"
#include "const.h"

typedef struct Room {
	char description[MAX_DESCRIPTION];
	Item *items[MAX_ITEMS]; // Sabit boyutlu gösterici dizisi
	int itemCount;          // Odada kaç eşya olduğunu takip eder
	Creature *creature;
	struct Room *up;
	struct Room *down;
	struct Room *left;
	struct Room *right;
} Room;

Room* createRoom(const char *description, Item *items[], int itemCount,
		Creature *creature);

#endif /* ROOM_H_ */
