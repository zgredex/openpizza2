/* Game_HideBuildingOverlay (0x47fe70). */

struct Record;

struct Map {
    char pad[0x8c];
    int count;
    Record *MapRecordToGlobal(int index);
};

struct Record {
    char pad[0xc8];
    int child;
    int Is1A1B1C();
    void SetChildShort();
};

struct Game {
    char pad0[0x16f0];
    Map *map;
    char pad1[0x1a20 - 0x16f4];
    char overlayVisible;
    void HideBuildingOverlay(int which);
};

void Game::HideBuildingOverlay(int which)
{
    int i;
    Record *record;
    Map *map;

    switch (which) {
    case 1:
        map = this->map;
        overlayVisible = 0;
        i = 0;
        if (0 < map->count) {
            do {
                record = map->MapRecordToGlobal(i);
                if (record->Is1A1B1C() != 0 && record->child != 0) {
                    record->SetChildShort();
                }
                map = this->map;
                i++;
            } while (i < map->count);
        }
        break;
    }
}
