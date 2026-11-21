/* Game_CountFreeBuildingsByType: counts the free map objects of a building
   type (0x4d2ae0). */
struct Record {
    char pad[0x30];
    int type;

    int IsState2DOr2E();
};

struct Game {
    char pad[0x8c];
    int objectCount;

    struct Record *MapRecordToGlobal(int index);

    int CountFreeBuildingsByType(int type);
};

int Game::CountFreeBuildingsByType(int type)
{
    int count = 0;
    int i;

    for (i = 0; i < objectCount; i++) {
        struct Record *record = MapRecordToGlobal(i);

        if (record->IsState2DOr2E() == 0 && record != 0 &&
            record->type == type) {
            count++;
        }
    }
    return count;
}
