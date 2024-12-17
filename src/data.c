#include "data.h"

void saveRooms(Room *room, FILE *file) {
    while (room) {
        fprintf(file, "%s\n%d\n", room->description, room->itemCount);
        for (int i = 0; i < room->itemCount; i++) {
            fprintf(file, "%s\n%d %d %d\n", room->items[i]->name, room->items[i]->attackPower, room->items[i]->strRequirement, room->items[i]->gainStrength);
        }
        if (room->creature) {
            fprintf(file, "%s\n%d %d %d\n", room->creature->name, room->creature->health, room->creature->attack, room->creature->gainStrength);
        } else {
            fprintf(file, "NULL\n");
        }
        room = room->right; // Save only rightward rooms for simplicity
    }
}

void saveGame(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to save the game.\n");
        return;
    }

    // Save player data
    fprintf(file, "%d %d %d\n", player.health, player.strength, player.punchDamage);
    for (int i = 0; i < 5; i++) {
        Item *item = NULL;
        switch (i) {
            case 0: item = myInventory->item1; break;
            case 1: item = myInventory->item2; break;
            case 2: item = myInventory->item3; break;
            case 3: item = myInventory->item4; break;
            case 4: item = myInventory->item5; break;
        }
        if (item) {
            fprintf(file, "%s\n%d %d %d\n", item->name, item->attackPower, item->strRequirement, item->gainStrength);
        } else {
            fprintf(file, "NULL\n");
        }
    }

    // Save current room
    fprintf(file, "%s\n", currentRoom->description);

    // Save room data (First row of map)
    Room *r1 = room1;
    saveRooms(r1, file);

    // Save room data (Second row of map)
    Room *r4 = room4;
    saveRooms(r4, file);

    // Save room data (Third row of map)
    Room *r7 = room7;
    saveRooms(r7, file);

    fclose(file);
    printf("Game saved successfully.\n");
}

void loadRooms(Room *room, FILE *file) {
    char description[MAX_DESCRIPTION];
    while (room) {
        fgets(description, MAX_DESCRIPTION, file);
        description[strcspn(description, "\n")] = '\0'; // Remove newline character
        strcpy(room->description, description);

        int itemCount;
        fscanf(file, "%d\n", &itemCount);
        room->itemCount = itemCount;

        for (int i = 0; i < itemCount; i++) {
            char name[MAX_NAME];
            int attackPower, strRequirement, gainStrength;
            fgets(name, MAX_NAME, file);
            name[strcspn(name, "\n")] = '\0'; // Remove newline character
            fscanf(file, "%d %d %d\n", &attackPower, &strRequirement, &gainStrength);
            strcpy(room->items[i]->name, name);
            room->items[i]->attackPower = attackPower;
            room->items[i]->strRequirement = strRequirement;
            room->items[i]->gainStrength = gainStrength;
        }

        char creatureName[MAX_NAME];
        fgets(creatureName, MAX_NAME, file);
        creatureName[strcspn(creatureName, "\n")] = '\0'; // Remove newline character
        if (strcmp(creatureName, "NULL") != 0) {
            int health, attack, gainStrength;
            fscanf(file, "%d %d %d\n", &health, &attack, &gainStrength);
            strcpy(room->creature->name, creatureName);
            room->creature->health = health;
            room->creature->attack = attack;
            room->creature->gainStrength = gainStrength;
        } else {
            room->creature = NULL;
        }

        room = room->right; // Move to the next room pointer in the chain
    }
}

void loadGame(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to load the game.\n");
        return;
    }

    // Load player data
    fscanf(file, "%d %d %d\n", &player.health, &player.strength, &player.punchDamage);

    // Load inventory
    for (int i = 0; i < 5; i++) {
        char name[MAX_NAME];
        int attackPower, strRequirement, gainStrength;
        fgets(name, MAX_NAME, file);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        if (strcmp(name, "NULL") != 0) {
            fscanf(file, "%d %d %d\n", &attackPower, &strRequirement, &gainStrength);
            Item *item = createItem(name, attackPower, strRequirement, gainStrength); // Assuming gainStrength = 0 for items
            switch (i) {
                case 0: myInventory->item1 = item; break;
                case 1: myInventory->item2 = item; break;
                case 2: myInventory->item3 = item; break;
                case 3: myInventory->item4 = item; break;
                case 4: myInventory->item5 = item; break;
            }
        }
    }

    // Load current room description
    char currentRoomDescription[MAX_DESCRIPTION];
    fgets(currentRoomDescription, MAX_DESCRIPTION, file);
    currentRoomDescription[strcspn(currentRoomDescription, "\n")] = '\0'; // Remove newline character

    // Load room data (First row of map)
    Room *r1 = room1;
    loadRooms(r1, file);

    // Load room data (Second row of map)
    Room *r4 = room4;
    loadRooms(r4, file);

    // Load room data (Third row of map)
    Room *r7 = room7;
    loadRooms(r7, file);

    // Set currentRoom to the loaded room
    Room *allRooms[] = {room1, room1->right, room1->right->right,
                        room4, room4->right, room4->right->right,
                        room7, room7->right, room7->right->right};
    for (int i = 0; i < 9; i++) {
        if (strcmp(allRooms[i]->description, currentRoomDescription) == 0) {
            currentRoom = allRooms[i];
            break;
        }
    }

    fclose(file);
    printf("Game loaded successfully.\n");
}
