/* Game_ShowBuildingOverlay: enables the building overlay and refreshes the
   height of every active building child (0x47fe10). */
struct Record {
    int IsState1A1B1C();
    void SetChildHeightFromValue();
};

struct Map {
    char pad[0x8c];
    int count;
    void *MapRecordToGlobal(int index);
};

struct Game {
    char pad[0x16f0];
    struct Map *map;
    char pad2[0x32c];
    unsigned char overlayVisible;

    void ShowBuildingOverlay(int mode);
};

void Game::ShowBuildingOverlay(int mode)
{
    int i;
    struct Map *current;

    switch (mode) {
    case 1:
        current = map;
        overlayVisible = 1;
        for (i = 0; i < current->count; i++) {
            struct Record *record =
                (struct Record *)current->MapRecordToGlobal(i);

            if (record->IsState1A1B1C() != 0) {
                record->SetChildHeightFromValue();
            }
            current = map;
        }
    }
}
