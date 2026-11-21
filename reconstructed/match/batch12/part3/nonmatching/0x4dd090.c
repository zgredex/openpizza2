/* Game_RebuildLocalRecordOwners (0x4dd090). */

struct Record {
    void Set_Field168(void *owner);
};

struct IDMap {
    void *Lookup(int index, int *out);
    Record *MapRecordToGlobal(int index);
    void RemoveLocalEntryRecursive(int index);
};

struct Game {
    void RebuildLocalRecordOwners();
};

void Game::RebuildLocalRecordOwners()
{
    int count = *(int *)((char *)this + 0xfc0);
    int index = 0;

    while (index < count) {
        Record *local = (Record *)((struct IDMap *)((char *)this + 0xfac))
                                    ->Lookup(index, 0);
        int j;

        for (j = *(int *)((char *)local + 0x8c) - 1; j >= 0; j--) {
            Record *record = ((struct IDMap *)((char *)this + 0xfac))
                                 ->MapRecordToGlobal(j);
            if (record == 0) {
                ((struct IDMap *)((char *)this + 0xfac))
                    ->RemoveLocalEntryRecursive(j);
            } else {
                record->Set_Field168(local);
            }
        }
        index++;
    }
}
