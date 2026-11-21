/* Game_GetNthFreePlayerSlot: returns the slot of the n-th free player
   (0x49d150). */
extern void *DAT_0057c670;

struct Game {
    void *GetPlayerBySlot(int slot);
};

int __cdecl Game_GetNthFreePlayerSlot(int wanted)
{
    int freeCount = 0;
    int slot;

    for (slot = 0; slot < 6; slot++) {
        char *player = (char *)((Game *)DAT_0057c670)->GetPlayerBySlot(slot);
        if (player != 0 && *(int *)(player + 0x50) == 0) {
            if (freeCount == wanted)
                return slot;
            freeCount++;
        }
    }
    return -1;
}
