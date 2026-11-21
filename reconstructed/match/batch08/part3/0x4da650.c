/* Game_CollectAllOwnedObjects: collects each player's owned objects
   (0x4da650). */
extern void *DAT_0057c670;

struct List_Node {
    void Reset();
};

struct Player;

struct Game {
    Player *GetPlayerBySlot(int slot);
    void CollectObjectsByOwner(void *list, int owner);
};

void __stdcall Game_CollectAllOwnedObjects(void *list, int owner)
{
    int i;

    ((List_Node *)list)->Reset();
    i = 0;
    do {
        Player *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(i);
        if (player != 0)
            ((Game *)player)->CollectObjectsByOwner(list, owner);
        i++;
    } while (i < 6);
}
