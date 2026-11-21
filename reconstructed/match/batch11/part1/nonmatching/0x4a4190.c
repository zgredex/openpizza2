/* Game_GetPlayerSlotByOrdinal: maps an ordinal to the player slot, skipping
   the current player and empty slots (0x4a4190). */
extern "C" int *DAT_0057c670;

struct Game {
    int GetCurrentPlayerCompanyName();
};

extern "C" int __cdecl Game_GetPlayerSlotByOrdinal(int ordinal)
{
    int count = 0;

    if (*(int *)0x57d248 < 6) {
        int index = *(int *)0x57d248;
        int *slot = (int *)0x57d24c + index;

        do {
            if (index != ((Game *)DAT_0057c670)->GetCurrentPlayerCompanyName()
                && *slot != 0) {
                if (ordinal == count)
                    return index;
                count++;
            }
            slot++;
            index++;
        } while ((int)slot < 0x57d264);
    }
    return count;
}
