struct IDMap {
    int unused;
    int Lookup(int index, int *out);
};

struct Recipe {
    void SetOnMenu(int recipe, char onMenu);
};

struct Game {
    void *FindBestRatedBuilding(int index);
    int CountActiveCompanies();
};

struct Company {
    char pad0[0x110];
    IDMap menuMap;
    char pad1[0x124 - 0x114];
    int recipeCount;
    char pad2[0x1dc - 0x128];
    char onMenu;
};

struct GameData {
    char pad[0x70];
    Company *companies[1];
    int AutoFillCompanyMenu(int slot);
};

int GameData::AutoFillCompanyMenu(int slot)
{
    Company *company = *(Company **)((char *)this + slot * 0x168 + 0x70);
    int count = *(int *)((char *)company + 0x124);
    if (count == 0)
        return 1;
    int i;
    for (i = 0; i < count; i++) {
        int recipe = ((IDMap *)((char *)company + 0x110))->Lookup(i, 0);
        ((Recipe *)company)->SetOnMenu(recipe, 0);
    }
    for (i = 0; i < 7; i++) {
        void *best = ((Game *)company)->FindBestRatedBuilding(i);
        if (best != 0)
            ((Recipe *)company)->SetOnMenu((int)best, 1);
    }
    int slots = 8 - ((Game *)company)->CountActiveCompanies();
    if (0 < slots && 0 < count) {
        i = 0;
        do {
            int recipe = ((IDMap *)((char *)company + 0x110))->Lookup(i, 0);
            if (*(char *)(recipe + 0x1dc) == 0) {
                ((Recipe *)company)->SetOnMenu(recipe, 1);
                slots = slots - 1;
                if (slots == 0)
                    return 1;
            }
            i++;
        } while (i < count);
    }
    return 1;
}
