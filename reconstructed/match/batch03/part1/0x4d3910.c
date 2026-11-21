/* Game_GetRecordByField814: looks up the record id stored at offset 0x814 (0x4d3910). */
extern int DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

void __fastcall Game_GetRecordByField814(char *this_)
{
    int key = *(int *)(this_ + 0x814);

    if (key)
        ; /* the load is kept for the register allocation of the original */
    ((IDMap *)(DAT_0057c670 + 0x3c))->Lookup(key, 0);
}
