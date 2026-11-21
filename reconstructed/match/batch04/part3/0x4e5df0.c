/* Game_GetPlayerByte8: looks up a player record and returns byte 8 (0x4e5df0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

extern char *DAT_0057c670;

unsigned char __fastcall Game_GetPlayerByte8(char *record)
{
    int key = *(int *)(record + 4);
    char *found = (char *)((IDMap *)(DAT_0057c670 + 0x74))->Lookup(key, 0);

    if (found != 0) {
        return *(unsigned char *)(found + 8);
    }
    return 0;
}
