/* Map_LookupLinear (0x401930, 49 bytes).  Build: /O2 /TP.
   Linear search of the key array, returning the parallel value or -1. */
struct Map {
    int LookupLinear(int key);
};

int Map::LookupLinear(int key)
{
    int count = *(int *)((char *)this + 0xc);
    int index = 0;

    if (count > 0) {
        while (index < count) {
            if (*(int *)(*(int *)((char *)this + 4) + index * 4) == key)
                return *(int *)(*(int *)((char *)this + 8) + index * 4);
            index++;
        }
    }
    return -1;
}
