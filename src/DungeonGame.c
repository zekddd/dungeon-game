#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "room.h"
#include "item.h"
#include "creature.h"
#include "inventory.h"
#include "const.h"
#include "data.h"

Player player;
Room *currentRoom, *room1, *room4, *room7;
Inventory *myInventory;

void initializeGame() {
    player.health = 200;
    player.strength = 15;
    player.punchDamage = 10;

    printf("-------------Welcome to the Dungeons of Eternal Shadows------------- \n");
    printf("-------------------------------Map----------------------------------\n\n");
    printf("Dungeon7-----Dungeon8-----Dungeon9\n");
    printf("   |            |             |  \n");
    printf("   |            |             |  \n");
    printf("   |            |             |  \n");
    printf("Dungeon4-----Dungeon5-----Dungeon6\n");
    printf("   |            |             |  \n");
    printf("   |            |             |  \n");
    printf("   |            |             |  \n");
    printf("Dungeon1-----Dungeon2-----Dungeon3\n\n");
    printf("Now, You are in Dungeon2. You have to kill the Dungeon Dragon in Dungeon8\nbut there are a lot of danger on your way. Be careful.\n\n");
    printf("(Your Health: %d) (Your Strength: %d) (Your Punch Damage: %d) \n\n", player.health, player.strength, player.punchDamage);
    printf("Commands:\n");
    printf("look >>>> For looking around\n");
    printf("move >>>> For moving another room\n");
    printf("pickup >>>> For picking up the items\n");
    printf("inventory >>>> For checking the inventory\n");
    printf("attack >>>> For attacking the creatures\n\n");
    printf("Write a command \n");

    myInventory = malloc(sizeof(Inventory));
    memset(myInventory, 0, sizeof(Inventory));
    player.inventory = myInventory;

    // Create items
    Item *oldSword = createItem("Old Sword", 15, 10, 0);
    Item *sword = createItem("Sword", 20, 15, 0);
    Item *oldRing1 = createItem("Old Ring", 0, 10, 5);
    Item *oldRing2 = createItem("Old Ring", 0, 10, 5);
    Item *oldRing3 = createItem("Old Ring", 0, 10, 5);
    Item *magicHat = createItem("Magic Hat", 0, 95, 25);
    Item *axe = createItem("Axe", 40, 30, 0);
    Item *magicAmulet = createItem("Magic Amulet", 0, 25, 10);
    Item *enchantedArmor = createItem("Enchanted Armor", 0, 60, 15);
    Item *excalibur = createItem("Excalibur", 45, 75, 0);
    Item *cannibalBlade = createItem("Cannibal Blade", 60, 115, 0);
    Item *dragonSlayer = createItem("Dragon Slayer", 85, 150, 0);

    // Create creatures
    Creature *goblin1 = createCreature("Armoured Goblin", 40, 7, 10);
    Creature *goblin2 = createCreature("Goblin", 30, 5, 5);
    Creature *goblin3 = createCreature("Armoured Goblin", 40, 7, 10);
    Creature *orc1 = createCreature("Orc", 50, 12, 10);
    Creature *orc2 = createCreature("Orc", 50, 12, 10);
    Creature *troll = createCreature("Troll", 80, 17, 15);
    Creature *shadowKnight1 = createCreature("Shadow Knight", 120, 25, 20);
    Creature *shadowKnight2 = createCreature("Shadow Knight", 120, 25, 20);
    Creature *dungeonDragon = createCreature("Dungeon Dragon", 250, 34, 30);

    // Create rooms
    Item *room1Items[] = { sword };
    room1 = createRoom("----(Dungeon1)----> You find yourself in a dimly lit room with broken furniture scattered around.", room1Items, 1, goblin1);

    Item *room2Items[] = { oldSword, oldRing1 };
    Room *room2 = createRoom("----(Dungeon2)----> The air is damp and cold. A faint glow comes from an old ring placed on a pedestal. You sense danger nearby.", room2Items, 2, goblin2);

    Item *room3Items[] = { axe };
    Room *room3 = createRoom("----(Dungeon3)----> You enter a chamber with bloodstains on the walls. An axe rests on a shattered stone table.", room3Items, 1, goblin3);

    Item *room4Items[] = { magicAmulet, oldRing2 };
    room4 = createRoom("----(Dungeon4)----> This room radiates an eerie energy. A glowing amulet hovers in the center of the room.", room4Items, 2, troll);

    Item *room5Items[] = { enchantedArmor };
    Room *room5 = createRoom("----(Dungeon5)----> You step into a grand hall with armor stands lining the walls. One suit of armor glows with a mystical light.", room5Items, 1, orc1);

    Item *room6Items[] = { excalibur, oldRing3 };
    Room *room6 = createRoom("----(Dungeon6)----> A collapsed ceiling leaves this room filled with rubble. The silence is broken only by distant growls.", room6Items, 2, orc2);

    Item *room7Items[] = { cannibalBlade, magicHat };
    room7 = createRoom("----(Dungeon7)----> A cold wind brushes past you as you enter a shadowy corridor. A shadow knight stands guard, watching your every move.", room7Items, 2, shadowKnight1);

    Item *room8Items[] = { dragonSlayer };
    Room *room8 = createRoom("----(Dungeon8)----> You stand in the heart of the dungeon. The massive form of the Dungeon Dragon blocks your path, guarding a legendary sword.", room8Items, 1, dungeonDragon);

    Item *room9Items[] = { };
    Room *room9 = createRoom("----(Dungeon9)----> A dark, foreboding chamber with strange runes carved into the walls. You feel an overwhelming presence here.", room9Items, 0, shadowKnight2);

    // Link rooms
    room1->right = room2;
    room1->up = room4;
    room2->left = room1;
    room2->up = room5;
    room2->right = room3;
    room3->left = room2;
    room3->up = room6;
    room4->down = room1;
    room4->right = room5;
    room4->up = room7;
    room5->down = room2;
    room5->up = room8;
    room5->right = room6;
    room5->left = room4;
    room6->down = room3;
    room6->left = room5;
    room6->up = room9;
    room7->down = room4;
    room7->right = room8;
    room8->left = room7;
    room8->down = room5;
    room8->right = room9;
    room9->left = room8;
    room9->down = room6;

    currentRoom = room2;
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    initializeGame();

    char inputCommand[MAX_NAME];

    while (1) {
        if (player.health <= 0) initializeGame();
        printf(">>");
        scanf("%s", inputCommand);
        // Command input and processing
        if (strcmp(inputCommand, "look") == 0) {
            look(currentRoom);
        } else if (strcmp(inputCommand, "move") == 0) {
            printf("Which direction do you want to go: \n");
            char direction[MAX_NAME];
            scanf("%s", direction);
            fflush(stdin);
            move(direction, &currentRoom);
        } else if (strcmp(inputCommand, "pickup") == 0) {
            printf("Which slot of the inventory would you like to put the item in (1,2,3,4,5): \n");
            inventory(myInventory);
            int compartment;
            printf(">>");
            scanf("%d", &compartment);
            fflush(stdin);
            pickup(compartment, currentRoom, &player, myInventory);
        } else if (strcmp(inputCommand, "inventory") == 0) {
            inventory(myInventory);
            printf("(Health: %d) (Strength: %d)\n", player.health, player.strength);
        } else if (strcmp(inputCommand, "attack") == 0) {
            attack(currentRoom, &player);
        } else if (strcmp(inputCommand, "save") == 0) {
            printf("Enter the filename to save the game: \n");
            char filename[MAX_NAME];
            scanf("%s", filename);
            saveGame(filename);
        } else if (strcmp(inputCommand, "load") == 0) {
            printf("Enter the filename to load the game: \n");
            char filename[MAX_NAME];
            scanf("%s", filename);
            loadGame(filename);
        } else {
            printf("Unknown command: %s\n", inputCommand);
        }
    }

    return 0;
}
