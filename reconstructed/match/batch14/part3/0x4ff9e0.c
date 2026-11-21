struct Building { char pad[0x4c]; int type; char pad2[0x108 - 0x50]; double value; };
struct InventorySlot { int id; int unused1; int unused2; int timestamp; };
struct InventoryArray { void ResetInventory(Building *building); };
extern int DAT_0057bcd8[];
void InventoryArray::ResetInventory(Building *building)
{
    int i;
    int index = building->type;
    char *block;
    int amount;
    block = (char *)this + index * 0x168;
    amount = DAT_0057bcd8[*(int *)(block + 0x40) * 0x30];
    building->value = (double)((amount * 50000) / 100);
    InventorySlot *slot = (InventorySlot *)(block + 0x74);
    for (i = 0; i < 10; i++) {
        slot->timestamp = 0;
        slot->id = -1;
        slot++;
    }
    *(int *)(block + 300) = 3;
}
