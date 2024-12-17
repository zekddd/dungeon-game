#include "player.h"

void look(Room *currentRoom) {
    printf("%s\n", currentRoom->description);

    // List items in the room
    if (currentRoom->itemCount > 0) {
        printf("You see the following items:\n");
        for (int i = 0; i < currentRoom->itemCount; i++) {
            Item *item = currentRoom->items[i];
            if (item->attackPower != 0)
                printf("- %s->>>> (Attack Power: %d) (Strength Requirement: %d)\n", item->name, item->attackPower, item->strRequirement);
            else
                printf("- %s->>>> (Strength: +%d) (Strength Requirement: %d)\n", item->name, item->gainStrength, item->strRequirement);
        }
    } else {
        printf("There are no items here.\n");
    }

    // List creatures in the room
    if (currentRoom->creature) {
        printf("A %s is here! (Health: %d) (Attack Power: %d)\n", currentRoom->creature->name, currentRoom->creature->health, currentRoom->creature->attack);
    }

    // List available directions
    printf("You can go ");
    if (currentRoom->right) printf("'right' ");
    if (currentRoom->left) printf("'left' ");
    if (currentRoom->up) printf("'up' ");
    if (currentRoom->down) printf("'down' ");
    printf("\n");
}

void move(char *direction, Room **currentRoom) {
    Room *nextRoom = NULL;
    if (strcmp(direction, "up") == 0) {
        nextRoom = (*currentRoom)->up;
    } else if (strcmp(direction, "down") == 0) {
        nextRoom = (*currentRoom)->down;
    } else if (strcmp(direction, "left") == 0) {
        nextRoom = (*currentRoom)->left;
    } else if (strcmp(direction, "right") == 0) {
        nextRoom = (*currentRoom)->right;
    }

    if (nextRoom) {
        *currentRoom = nextRoom;
        printf("You moved %s.\n", direction);
        look(*currentRoom);
    } else {
        printf("You can't go that way!\n");
    }
}

void pickup(int compartment, Room *currentRoom, Player *player, Inventory *myInventory) {
    if (currentRoom->itemCount == 0) {
        printf("There is nothing to pick up.\n");
        return;
    }

    // List items in the room
    printf("The room contains the following items:\n");
    for (int i = 0; i < currentRoom->itemCount; i++) {
        printf("%d. %s (Attack Power: %d)\n", i + 1, currentRoom->items[i]->name, currentRoom->items[i]->attackPower);
    }

    // Ask for user choice
    int choice;
    printf("Enter the number of the item you want to pick up: \n");
    printf(">>");
    scanf("%d", &choice);

    // Check if choice is valid
    if (choice < 1 || choice > currentRoom->itemCount) {
        printf("Invalid choice.\n");
        return;
    }

    // Pick up the item
    if (currentRoom->items[choice - 1]->strRequirement <= player->strength) {
        Item *itemToPickup = currentRoom->items[choice - 1];

        // Check the corresponding inventory slot
        Item **inventorySlot = NULL;
        switch (compartment) {
            case 1: inventorySlot = &myInventory->item1; break;
            case 2: inventorySlot = &myInventory->item2; break;
            case 3: inventorySlot = &myInventory->item3; break;
            case 4: inventorySlot = &myInventory->item4; break;
            case 5: inventorySlot = &myInventory->item5; break;
            default: printf("Invalid slot number. Choose between 1 and 5.\n"); return;
        }

        if (*inventorySlot) {
            // If slot is occupied, drop the item in the room
            if (currentRoom->itemCount >= MAX_ITEMS) {
                printf("The room cannot hold more items.\n");
                return;
            }
            currentRoom->items[currentRoom->itemCount] = *inventorySlot;
            currentRoom->itemCount++;

            printf("You dropped the %s from slot %d into the room.\n", (*inventorySlot)->name, compartment);
            player->strength -= (*inventorySlot)->gainStrength;
        }

        // Add new item to inventory
        *inventorySlot = itemToPickup;

        // Remove item from room
        for (int i = choice; i < currentRoom->itemCount; i++) {
            currentRoom->items[i - 1] = currentRoom->items[i];
        }
        currentRoom->items[currentRoom->itemCount - 1] = NULL;
        currentRoom->itemCount--;

        printf("You picked up the %s and placed it in slot %d.\n", itemToPickup->name, compartment);
        player->strength += itemToPickup->gainStrength;
        inventory(myInventory);
        return;
    } else {
        printf("You are not strong enough to pick up that item.\n");
        printf("Your strength is %d but the requirement is %d.\n", player->strength, currentRoom->items[choice - 1]->strRequirement);
        printf("If you want to gain strength, you have to beat creatures or find special strength items.\n");
        return;
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void attack(Room *currentRoom, Player *player) {
    if (currentRoom->creature) {
        printf("You attack the %s!\n", currentRoom->creature->name);

        int item1Attack = (player->inventory->item1 != NULL) ? player->inventory->item1->attackPower : 0;
        int item2Attack = (player->inventory->item2 != NULL) ? player->inventory->item2->attackPower : 0;
        int item3Attack = (player->inventory->item3 != NULL) ? player->inventory->item3->attackPower : 0;
        int item4Attack = (player->inventory->item4 != NULL) ? player->inventory->item4->attackPower : 0;
        int item5Attack = (player->inventory->item5 != NULL) ? player->inventory->item5->attackPower : 0;
        int punchAttack = player->punchDamage;

        // Get the maximum attack power
        int maxItemDamage = max(max(max(max(item1Attack, item2Attack), max(item3Attack, item4Attack)), item5Attack), punchAttack);

        currentRoom->creature->health -= maxItemDamage;
        if (currentRoom->creature->health <= 0) {
            printf("You defeated the %s!\n", currentRoom->creature->name);
            player->strength += currentRoom->creature->gainStrength;
            printf("You gain +%d strength.\n", currentRoom->creature->gainStrength);
            free(currentRoom->creature);
            currentRoom->creature = NULL;
        } else {
            printf("%s's health: %d\n", currentRoom->creature->name, currentRoom->creature->health);
            printf("The %s attacks back!\n", currentRoom->creature->name);
            player->health -= currentRoom->creature->attack;
            if (player->health <= 0) {
                printf("-----------------------GAME OVER-----------------------\n");
                printf("-----------------------GAME OVER-----------------------\n");
                printf("-----------------------GAME OVER-----------------------\n");
                printf("-------------------You started again-------------------\n\n");
            } else {
                printf("Your health: %d\n", player->health);
            }
        }
    } else {
        printf("There is nothing to attack here.\n");
    }
}
