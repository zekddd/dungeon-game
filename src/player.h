#ifndef PLAYER_H_
#define PLAYER_H_

#include "inventory.h"
#include "room.h"

typedef struct Player {
    int health;
    int strength;
    int punchDamage;
    Inventory *inventory;
} Player;

void look(Room *currentRoom);
void move(char *direction, Room **currentRoom);
void pickup(int compartment, Room *currentRoom, Player *player, Inventory *myInventory);
int max(int a, int b);
void attack(Room *currentRoom, Player *player);

#endif /* PLAYER_H_ */
