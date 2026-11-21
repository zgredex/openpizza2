/* Game_UpdateBuildingStates (0x50e230). */
struct MapList {
    char pad0[0x8c];
    int count;              /* 0x8c */

    void *MapRecordToGlobal(int index);
};
struct Building {
    char pad0[0x30];
    int type;               /* 0x30 */
    char pad1[4];
    int field38;            /* 0x38 */
    char pad2[0x90];        /* to 0xcc */
    int fieldcc;            /* 0xcc */
    char pad3[0x38];        /* to 0x108 */
    int field108;           /* 0x108 */

    void SetState(int state);
};
struct Game {
    char pad0[0xcc];
    int fieldcc;            /* 0xcc */
    char pad1[0x24];        /* to 0xf4 */
    MapList *list;          /* 0xf4 */

    void UpdateBuildingStates();
};

void Game::UpdateBuildingStates()
{
    int index = 0;
    MapList *list = this->list;

    if (list->count > 0) {
        do {
            Building *building = (Building *)list->MapRecordToGlobal(index);
            int type = building->type;

            if ((type == 0x16 || type == 0x1e || type == 0x1f) &&
                building->field38 == 0x38) {
                building->SetState(0x39);
                building->field108 = 6;
                building->fieldcc = fieldcc;
            }
            list = this->list;
            index++;
        } while (index < list->count);
    }
}
