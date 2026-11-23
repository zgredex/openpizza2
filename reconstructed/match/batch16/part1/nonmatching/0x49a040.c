// Game_IsCompanyNameTaken @ 0x49a040 (150 bytes)
// Checks the active company list for an equal name.

extern "C" int strcmp(const char *a, const char *b);
#pragma intrinsic(strcmp)

extern char *DAT_0057c670;

class IDMap {
public:
    void *Lookup(int index, int *out);
};

extern "C" bool __cdecl Game_IsCompanyNameTaken(unsigned char *name)
{
    char *global = DAT_0057c670;
    char *list = *(char **)(global + 0x200 + *(int *)(global + 0x2ec) * 4);
    int count = *(int *)(list + 0x124);
    int index;

    for (index = 0; index < count; index++) {
        int found = (int)((IDMap *)(list + 0x110))->Lookup(index, 0);
        if (found != *(int *)(DAT_0057c670 + 0x98)) {
            if (strcmp((char *)(found + 4), (char *)name) == 0)
                return 1;
        }
    }
    return 0;
}
