/* Game_AdvanceCurrentRecord (0x4ba250). */

struct IDMapHelper {
    char pad[0x14];

    void *Lookup(int key, int *out);
};

struct Player {
    char pad0[0x48];
    int company;                /* 0x48 */
    char pad1[0xfc];
    IDMapHelper map;            /* 0x148 */
    int units;                  /* 0x15c */
};

struct Game {
    Player *GetPlayerBySlot(int slot);
    int GetCurrentPlayerCompanyName();
};

extern Game *DAT_0057c670;
extern void *DAT_0057d6e8;

void Game_AdvanceCurrentRecord(void)
{
    int slot = *(int *)((char *)DAT_0057d6e8 + 0x30);
    char found = 0;
    Player *player = DAT_0057c670->GetPlayerBySlot(slot);
    int index = 0;
    int count = player->units;

    if (count < 1)
        return;
    do {
        void *record = player->map.Lookup(index, 0);

        if (record == DAT_0057d6e8) {
            void *next = player->map.Lookup(index + 1, 0);

            if (next != 0) {
                DAT_0057d6e8 = next;
                return;
            }
            int tries = 0;
            while (1) {
                tries++;
                slot++;
                if (slot > 5)
                    slot = 0;
                player = DAT_0057c670->GetPlayerBySlot(slot);
                if (player != 0 &&
                    player->company !=
                        DAT_0057c670->GetCurrentPlayerCompanyName() &&
                    player->units > 0)
                    break;
                if (found || tries > 6)
                    goto next_record;
            }
            DAT_0057d6e8 = player->map.Lookup(0, 0);
            found = 1;
        }
next_record:
        index++;
    } while (index < count);
}
