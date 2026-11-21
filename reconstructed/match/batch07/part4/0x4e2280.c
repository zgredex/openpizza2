/* Game_GetPlayerFieldC20: returns a city field for the player's company slot
   (0x4e2280). */
struct IDMap {
    int field0;
    void *Lookup(int key, int *out);
};

struct Player {
    char pad[0x48];
    int slot;
    char pad2[0x18c];
    int field1d8;
};

extern char *DAT_0057c670;

int __fastcall Game_GetPlayerFieldC20(Player *player)
{
    char *city;

    if (player->field1d8 == 0)
        return 0;
    city = (char *)((IDMap *)(DAT_0057c670 + 4))
               ->Lookup(*(int *)(DAT_0057c670 + 0x2f4), 0);
    return *(int *)(city + 0xc20 + player->slot * 4);
}
