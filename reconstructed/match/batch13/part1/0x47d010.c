/* Game_CountAgedAdjacentBuildings (0x47d010). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct Record {
    char pad0[0xc];
    int age;                /* 0x0c */

    char GetPlayerByte8();
};
struct Game {
    char pad0[0x16f8];
    IDMap map;              /* 0x16f8 */
    int count;              /* 0x170c */

    int CountAgedAdjacentBuildings();
    int HasAdjacentOccupiedCell(Record *record);
};

int Game::CountAgedAdjacentBuildings()
{
    int total = 0;
    int index = 0;

    if (count > 0) {
        do {
            Record *record = (Record *)map.Lookup(index, 0);

            if (record != 0) {
                if (record->GetPlayerByte8() == 1 && record->age > 0x14) {
                    if (HasAdjacentOccupiedCell(record))
                        total++;
                }
            }
            index++;
        } while (index < count);
    }
    return total;
}
