Game Overview: Dungeons of Eternal Shadows

Introduction
"Dungeons of Eternal Shadows" is a text-based adventure game where the player navigates through a series of interconnected dungeon rooms, battles creatures, and collects items. The ultimate goal is to defeat the Dungeon Dragon located in Dungeon8. The game features a dynamic inventory system, and player stats such as health and strength, and allows saving and loading game progress.

Game Flow
Initialization: The game initializes player stats, creates items, creatures, and rooms, and links the rooms to form the dungeon map.

Main Loop: The game runs in a loop where the player can enter commands to look around, move between rooms, pick up items, check inventory, attack creatures, save the game, and load a saved game.

Player Commands:
look: Describes the current room, including items and creatures present.
move <direction>: Moves the player to an adjacent room in the specified direction.
pickup <inventory_slot>: Picks up an item from the current room and places it in the specified inventory slot.
inventory: Displays the contents of the player's inventory.
attack: Attacks any creature present in the current room.
save <filename>: Saves the current game state to a file.
load <filename>: Loads a previously saved game state from a file.

Application Design
The game is designed using a modular approach with the following key components:

Player:
Structure: Contains health, strength, punch damage, and a pointer to the inventory.
Functions: Handling look, move, pickup, and attack actions.

Room:
Structure: Contains description, items, creatures, and pointers to adjacent rooms (up, down, left, right).
Functions: Creating and managing room contents.

Item:
Structure: Contains name, attack power, strength requirement, and strength gain.
Functions: Creating items.

Creature:
Structure: Contains name, health, attack power, and strength gain.
Functions: Creating creatures.

Inventory:
Structure: Contains pointers to items in five slots.
Functions: Managing inventory contents.

Game Initialization:
Function: Initializes player stats, items, creatures, and rooms, and sets up the dungeon map.

Data Handling:
Functions: Save and load game state, including player stats, inventory, and room contents.
Implementation Details

Player:
Header (player.h): Defines the Player structure and function prototypes.
Source (player.c): Implements player-related functions such as look, move, pickup, and attack.

Room:
Header (room.h): Defines the Room structure and function prototypes.
Source (room.c): Implements room-related functions such as creating rooms and managing their contents.

Item:
Header (item.h): Defines the Item structure and function prototypes.
Source (item.c): Implements item-related functions such as creating items.

Creature:
Header (creature.h): Defines the Creature structure and function prototypes.
Source (creature.c): Implements creature-related functions such as creating creatures.

Inventory:
Header (inventory.h): Defines the Inventory structure and function prototypes.
Source (inventory.c): Implements inventory-related functions such as displaying inventory contents.

Game Initialization:
Source (DungeonGame.c): Implements the main game loop, initialization function, and command handling.

Data Handling:
Header (data.h): Defines function prototypes for saving and loading game data.
Source (data.c): Implements save and load functions to handle game state persistence.

Key Functions and Their Roles
initializeGame(): Sets up the initial game state, including player stats, items, creatures, and rooms.
look(Room *currentRoom): Describes the current room, listing items and creatures present.
**move(char *direction, Room currentRoom): Moves the player to an adjacent room in the specified direction.
pickup(int compartment, Room *currentRoom, Player *player, Inventory *myInventory): Picks up an item from the current room and places it in the specified inventory slot.
inventory(Inventory *myInventory): Displays the contents of the player's inventory.
attack(Room *currentRoom, Player *player): Attacks any creature present in the current room.
saveGame(const char *filename): Saves the current game state to a file, including player stats, inventory, and room contents.
loadGame(const char *filename): Loads a previously saved game state from a file, restoring player stats, inventory, and room contents.
Save and Load Mechanics
To support game state persistence, the save and load functions handle all aspects of the game state:

saveGame():
Saves player health, strength, and punch damage.
Saves inventory items.
Saves the description of the current room.
Saves room contents (items and creatures) and their connections (up, down, left, right).

loadGame():
Loads player health, strength, and punch damage.
Loads inventory items.
Loads the description of the current room and sets the currentRoom pointer.
Loads room contents (items and creatures) and their connections (up, down, left, right).

By ensuring the currentRoom is properly saved and loaded, the game allows players to resume from their last saved location, maintaining continuity and enhancing the gaming experience.

Conclusion
"Dungeons of Eternal Shadows" is a comprehensive text-based adventure game that provides an engaging experience through its modular design and detailed implementation. The save and load mechanics ensure players can enjoy a seamless and continuous journey through the dungeon, battling creatures and collecting powerful items along the way.


