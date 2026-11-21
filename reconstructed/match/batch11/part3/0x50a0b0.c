/* Object_SetBuildingRecordForAllCompanies: assigns a building record to the
   object and all eight company slots (0x50a0b0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Map {
    char pad[0x2f4-4-0x14];
    int count;

    int GetRandomBuildingOfType(int type, int unused, char flag);
};

struct World {
    char pad[4];
    char map[0x14];
    char pad2[0x2f4-0x18];
    int count;
};

extern int DAT_0057c670;

struct Object {
    char pad[0xcc];
    int buildingRecord;
    char pad2[4];
    int companies[8];

    void SetBuildingRecordForAllCompanies(int type, int record);
};

void Object::SetBuildingRecordForAllCompanies(int type, int record)
{
    int i;

    if (record == 0) {
        struct World *world = (struct World *)DAT_0057c670;
        struct Map *map = (struct Map *)
            ((struct IDMap *)((char *)world + 4))->Lookup(world->count, 0);

        record = map->GetRandomBuildingOfType(type, 0, 0);
    }
    buildingRecord = record;
    for (i = 0; i < 8; i++) {
        companies[i] = buildingRecord;
    }
}
