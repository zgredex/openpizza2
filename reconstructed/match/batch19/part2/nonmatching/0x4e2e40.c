// Game_IsValueAssignedToCompany: checks whether a value belongs to a company.

extern char DAT_0057c670[];

struct IDMap {
    char *Lookup(int key, int *index);
};

struct Game {
    char IsValueAssignedToCompany(int value);
};

char Game::IsValueAssignedToCompany(int value)
{
    int index;

    if (value == 0)
        return 0;
    if (*(int *)((char *)this + 0x1cc) > 0) {
        index = 0;
        do {
            char *record = ((IDMap *)((char *)this + 0x1b8))->Lookup(index, 0);
            char *object = ((IDMap *)(*(char **)DAT_0057c670 + 0x3c))->Lookup(
                *(int *)record, 0);
            if (*(int *)(object + 0xa4) != -1) {
                if (*(int *)(object + 0x74) == 0) {
                    if (*(int *)(object + 0xfc) == value)
                        return 1;
                } else {
                    if (*(int *)(object + 0xf4) == value)
                        return 1;
                }
            }
            index++;
        } while (index < *(int *)((char *)this + 0x1cc));
    }
    if (*(int *)(*(char **)DAT_0057c670 + 0x50) > 0) {
        index = 0;
        do {
            char *object =
                ((IDMap *)(*(char **)DAT_0057c670 + 0x3c))->Lookup(index, 0);
            if (*(int *)(object + 0xa4) != -1 &&
                *(int *)(object + 0x110) == *(int *)((char *)this + 0x48) &&
                *(int *)(object + 0x30) == 0x16) {
                if (*(int *)(object + 0x74) == 0) {
                    if (*(int *)(object + 0xfc) == value)
                        return 1;
                } else {
                    if (*(int *)(object + 0xf4) == value)
                        return 1;
                }
            }
            index++;
        } while (index < *(int *)(*(char **)DAT_0057c670 + 0x50));
    }
    return 0;
}
