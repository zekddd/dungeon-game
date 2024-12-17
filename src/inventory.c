#include "inventory.h"

void inventory(Inventory *myInventory) {
    myInventory->item1 ?
        printf("Slot 1: %s (Attack Power: %d) (Strength: +%d) \n", myInventory->item1->name, myInventory->item1->attackPower, myInventory->item1->gainStrength) :
        printf("Slot 1: Empty\n");
    myInventory->item2 ?
        printf("Slot 2: %s (Attack Power: %d) (Strength: +%d) \n", myInventory->item2->name, myInventory->item2->attackPower, myInventory->item2->gainStrength) :
        printf("Slot 2: Empty\n");
    myInventory->item3 ?
        printf("Slot 3: %s (Attack Power: %d) (Strength: +%d) \n", myInventory->item3->name, myInventory->item3->attackPower, myInventory->item3->gainStrength) :
        printf("Slot 3: Empty\n");
    myInventory->item4 ?
        printf("Slot 4: %s (Attack Power: %d) (Strength: +%d) \n", myInventory->item4->name, myInventory->item4->attackPower, myInventory->item4->gainStrength) :
        printf("Slot 4: Empty\n");
    myInventory->item5 ?
        printf("Slot 5: %s (Attack Power: %d) (Strength: +%d) \n", myInventory->item5->name, myInventory->item5->attackPower, myInventory->item5->gainStrength) :
        printf("Slot 5: Empty\n");
}
