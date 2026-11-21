/* SparseMap_Lookup48 (0x4eab50, 47 bytes).  Build: /O2 /TP.
   Resolves -1 and negative keys to the map's two default slots, then indexes
   the 0x48-byte record table for keys below 2500. */
struct SparseMap {
    int Lookup48(int key);
};

int SparseMap::Lookup48(int key)
{
    if (key != -1) {
        if (key < 0)
            return *(int *)((char *)this + 8);
        if (key >= 0x9c4)
            return 0;
        return *(int *)((char *)this + key * 0x48 + 0x58);
    }
    return *(int *)((char *)this + 4);
}
