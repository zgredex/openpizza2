/* Player_GetFirstRecordType1 (0x4e34e0, 48 bytes).  Build: /O2 /TP.
   Returns the first record whose type field is 1, or zero. */
struct IDMap {
    int Lookup(int key, int *out);
};

extern "C" int __fastcall Player_GetFirstRecordType1(int player)
{
    int count = *(int *)(player + 0x140);
    int index = 0;

    while (index < count) {
        int record = ((IDMap *)(player + 0x12c))->Lookup(index, 0);

        if (*(int *)(record + 8) == 1)
            return record;
        index++;
    }
    return 0;
}
