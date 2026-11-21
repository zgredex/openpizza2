/* Game_GetRecordByte14: reads byte 0x14 of the record mapped by field 4 (0x4e5ff0). */
struct IDMap {
    int *Lookup(int key, int *out);
};

extern int DAT_0057c670;

int __fastcall Game_GetRecordByte14(int record)
{
    int key = *(int *)(record + 4);
    int *mapped = ((IDMap *)(DAT_0057c670 + 0x74))->Lookup(key, 0);

    if (mapped != 0)
        return *(unsigned char *)((char *)mapped + 0x14);
    return -1;
}
