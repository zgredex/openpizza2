/* Non-matching candidate.
   First difference: offset 0x26, 62 bytes differ.
   original materialises the two boolean locals with setne/setg before testing; candidate folds them into direct tests.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad0[0x200];
    void *players[6];
    void *GetPlayerBySlot(int slot);
};

struct Player {
    int CountActiveCompanies();
};

struct MapObject {
    void ClearObjectFlags(void *object, int flags);
    void SetObjectFlags(void *object, int flags);
};

void __fastcall Game_ClearObjectFlag20(char *entry)
{
    char *object = *(char **)(entry + 0x16f0);
    int record = (int)((IDMap *)((char *)DAT_0057c670 + 4))
                     ->Lookup(*(int *)(object + 0x28), 0);
    char *visual = *(char **)(record + 0xfa8);
    bool forced = *(int *)(entry + 0x14dc) != 0;

    if (forced)
        goto clear;
    {
        char *player = (char *)((Game *)DAT_0057c670)
                           ->GetPlayerBySlot(*(int *)(entry + 0x30));
        if (player != 0) {
            int companies = ((Player *)player)->CountActiveCompanies();
            bool active = companies > 0;
            if (active)
                goto clear;
        }
    }
    ((MapObject *)object)->SetObjectFlags(visual, 0x20);
    *(unsigned *)(entry + 0x28) |= 0x20;
    return;
clear:
    ((MapObject *)object)->ClearObjectFlags(visual, 0x20);
    *(unsigned *)(entry + 0x28) &= 0xdf;
}
