/* Game_ScalePlayerStat80: scales a player's rating by 80% (0x4e3f50). */
extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0x48];
    int player;
};

extern "C" void __fastcall Game_ScalePlayerStat80(void *object)
{
    void *first = ((struct IDMap *)((char *)DAT_0057c670 + 4))
        ->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
    int value = *(int *)((char *)first +
        *(int *)((char *)object + 0x48) * 4 + 0xd40);
    int scaled = (value << 3) / 10;
    void *second;

    second = ((struct IDMap *)((char *)DAT_0057c670 + 4))
        ->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
    *(int *)((char *)second + *(int *)((char *)object + 0x48) * 4 + 0xd40) =
        scaled;
}
