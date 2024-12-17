/*
 * inventory.h
 *
 *  Created on: 17 Ara 2024
 *      Author: zek
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "item.h"

typedef struct Inventory {
	Item *item1;
	Item *item2;
	Item *item3;
	Item *item4;
	Item *item5;
} Inventory;

void inventory(Inventory *myInventory);


#endif /* INVENTORY_H_ */
