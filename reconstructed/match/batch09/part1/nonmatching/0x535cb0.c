/* Palette_FindIndex: compares fixed-size palette records and returns the
   matching index or -1 (0x535cb0). */
struct PaletteEntry {
    int *data;
};

struct Palette {
    struct PaletteEntry **entries;
    char pad[4];
    int count;
    int FindIndex(int **value);
};

extern "C" int __cdecl memcmp(const void *left, const void *right, unsigned int size);
#pragma intrinsic(memcmp)

int Palette::FindIndex(int **value)
{
    int count = *(int *)((char *)this + 8);
    int *key = *value;
    int index = 0;

    if (count > 0) {
        struct PaletteEntry **entry = *(struct PaletteEntry ***)this;

        do {
            if (memcmp(key, (*entry)->data, 0xc0 * 4) == 0)
                return index;
            index++;
            entry++;
        } while (index < count);
    }
    return -1;
}
