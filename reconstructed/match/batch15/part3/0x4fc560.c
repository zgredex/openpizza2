extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Company {
    bool IsRecordLinked(void *record);
    void RemoveRecipe(void *recipe);
};

void __fastcall Game_PurgeUnusedCompanyRecipes(char *game)
{
    if (*(int *)((char *)DAT_0057c670 + 0x290) == 5)
        return;
    int *entry = (int *)(game + 0x114);
    int remaining = 6;
    do {
        if (entry[1] != 0 && entry[0] != 0) {
            char *company = *(char **)((char *)entry - 0xa4);
            int index = *(int *)(company + 0x124) - 1;
            if (index >= 0) {
                do {
                    void *recipe =
                        ((IDMap *)(company + 0x110))->Lookup(index, 0);
                    if (!((Company *)company)->IsRecordLinked(recipe))
                        ((Company *)company)->RemoveRecipe(recipe);
                    index--;
                } while (index >= 0);
            }
        }
        entry = (int *)((char *)entry + 0x168);
        remaining--;
    } while (remaining != 0);
}
