/*
 * room.c
 *
 *  Created on: 17 Ara 2024
 *      Author: zek
 */

#include "room.h"

Room* createRoom(const char *description, Item *items[], int itemCount,
		Creature *creature) {
	Room *room = malloc(sizeof(Room));
	if (!room) {
		printf("Memory allocation failed for room.\n");
		exit(1);
	}

	// Oda açıklamasını ayarla
	strncpy(room->description, description, MAX_DESCRIPTION);

	// Eşyaları ekle
	room->itemCount = itemCount;
	for (int i = 0; i < itemCount && i < MAX_ITEMS; i++) {
		room->items[i] = items[i];
	}
	for (int i = itemCount; i < MAX_ITEMS; i++) {
		room->items[i] = NULL; // Artık boş alanlar NULL
	}

	// Yaratığı ayarla
	room->creature = creature;

	// Komşu odaları NULL olarak başlat
	room->up = room->down = room->left = room->right = NULL;

	return room;
}
