/*
 * data.h
 *
 *  Created on: 17 Ara 2024
 *      Author: zek
 */

#ifndef DATA_H_
#define DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "room.h"
#include "item.h"
#include "creature.h"
#include "inventory.h"

#include "const.h"

extern Player player; // Declare global variables
extern Inventory *myInventory;
extern Room *room1, *room4, *room7;
extern Room *currentRoom;

void saveRooms(Room *room, FILE *file);

void saveGame(const char *filename);

void loadRooms(Room *room, FILE *file);

void loadGame(const char *filename);


#endif /* DATA_H_ */
