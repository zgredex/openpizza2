/* Non-matching candidate.
   First difference: offset 0x3, 12 bytes differ.
   original keeps this in esi and the city in edi; candidate swaps the two callee-saved registers.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

struct IDMap {
    char pad0[0x14];
    int count;
    void *Lookup(int key, int *out);
};

struct Game {
    void *GetPlayerBySlot(int slot);
};

struct Player {
    int GetPlayerCity();
};

void __fastcall Game_ComputeCityDateBonus(int self)
{
    *(int *)(self + 0x18) = 0;
    void *player =
        ((Game *)DAT_0057c670)->GetPlayerBySlot(*(int *)(self + 0xc));
    int city = ((Player *)player)->GetPlayerCity();
    IDMap *map = (IDMap *)(city + 0x8c);
    int count = map->count;
    int index = 0;
    if (count > 0) {
        do {
            char *record = (char *)map->Lookup(index, 0);
            int days = (unsigned)*(unsigned short *)(*(int *)((char *)DAT_0057c670 + 0x94) + 4) -
                       (unsigned)*(unsigned short *)(record + 8) + 1;
            if (days > 0 && days < 4) {
                int rate;
                switch (*(int *)(record + 4)) {
                case 0:
                    rate = 0x1e;
                    break;
                case 1:
                    rate = 0x28;
                    break;
                case 2:
                    rate = 0x14;
                    break;
                default:
                    goto skip;
                }
                *(int *)(self + 0x18) += (int)(rate / days);
            }
        skip:
            index++;
        } while (index < count);
    }
}
