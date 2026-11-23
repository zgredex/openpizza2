struct IDMap {
    int unused;
    int **Lookup(int index, int *out);
};

struct Rating {
    int GetInverse100();
    int AdjustB();
};

struct Game {
    int CountFreeResidentialBuildings();
    int CountObjectsByType(int type);
};

struct City {
    char pad0[0x1500];
    IDMap map;
    int MoveResidentIntoVacantHouse(int param2, void *city, int flag);
};

struct AI {
    int TryTakeOverRivalBranch(int value, int unused, void *city);
};

int AI::TryTakeOverRivalBranch(int value, int unused, void *city)
{
    int count = ((Game *)city)->CountFreeResidentialBuildings();
    if (count != 0)
        return ((City *)this)->MoveResidentIntoVacantHouse(value, city, 0);
    if (((Rating *)city)->GetInverse100() <= 0x28)
        return ((City *)this)->MoveResidentIntoVacantHouse(value, city, 0);
    count = ((Game *)city)->CountObjectsByType(-1);
    for (int i = 0; i < count; i++) {
        int **record = ((IDMap *)((char *)city + 0x1500))->Lookup(i, 0);
        if (record != 0) {
            int *object = *record;
            if (*(int *)((char *)object + 0xc) <= 0x14)
                goto takeover;
            if (((Rating *)object)->AdjustB() <= 0x14)
                goto takeover;
        }
    }
    return 3;
takeover:
    return ((City *)this)->MoveResidentIntoVacantHouse(value, city, 1);
}
