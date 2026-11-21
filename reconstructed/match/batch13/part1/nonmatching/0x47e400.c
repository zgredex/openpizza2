/* Game_CountOperatingObjectsByType (0x47e400). */
struct IDMap {
    char pad[0x14];
    void **Lookup(int key, int *out);
};
struct Object {
    char pad0[0x74];
    int field74;            /* 0x74 */

    void *GetRecordByField814();
};
struct Game {
    char pad0[0x1500];
    IDMap map;              /* 0x1500 */
    int count;              /* 0x1514 */

    int CountOperatingObjectsByType(unsigned int type);
};

int Game::CountOperatingObjectsByType(unsigned int type)
{
    int entries = count;
    int total = 0;
    int index;

    if (entries > 0) {
        for (index = 0; index < entries; index++) {
            void **entry = map.Lookup(index, 0);

            if (entry != 0) {
                Object *object = (Object *)*entry;

                if (type == 0xffffffff ||
                    *(unsigned char *)((char *)object + 0x824) == type) {
                    Object *record = (Object *)object->GetRecordByField814();

                    if (record->field74 != 0)
                        total++;
                }
            }
        }
    }
    return total;
}
