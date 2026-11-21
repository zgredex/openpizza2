/* Game_GetRecordByteC: looks up a record and returns byte 0xc (0x4e5e10). */
struct IDMap {
    void *Lookup(int key, int *out);
};

extern char *DAT_0057c670;

unsigned char __fastcall Game_GetRecordByteC(char *record)
{
    int key = *(int *)(record + 4);
    char *found = (char *)((IDMap *)(DAT_0057c670 + 0x74))->Lookup(key, 0);

    if (found != 0) {
        return *(unsigned char *)(found + 0xc);
    }
    return 0;
}
