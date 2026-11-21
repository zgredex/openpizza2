/* Map_FindNameIndex: finds a map name in the name table (0x4eaa40). */
extern "C" int strcmp(const char *a, const char *b);
#pragma intrinsic(strcmp)

struct Map {
    int FindNameIndex(char *name);
};

int Map::FindNameIndex(char *name)
{
    int i;

    for (i = 0; i < 0x9c4; i++) {
        if (strcmp(name, (char *)this + 0x25 + i * 0x48) == 0) {
            return i;
        }
    }
    return -1;
}
