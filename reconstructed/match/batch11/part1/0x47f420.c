/* Game_MarkAllObjectsDirty: advances the game stage and marks every map
   record dirty (0x47f420). */
struct Game {
    char pad[0x50];

    int SetStageIfHigher(int stage);
    char *MapRecordToGlobal(int index);
    int MarkAllObjectsDirty(int stage);
};

int Game::MarkAllObjectsDirty(int stage)
{
    int count;
    int i;

    if (SetStageIfHigher(stage) == 0)
        return 0;
    count = *(int *)(*(int *)((char *)this + 0x16f0) + 0x8c);
    if (count > 0) {
        for (i = 0; i < count; i++) {
            char *record =
                ((Game *)*(void **)((char *)this + 0x16f0))
                    ->MapRecordToGlobal(i);

            record[0x81] = 1;
        }
    }
    return 1;
}
