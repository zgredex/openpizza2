/* City_PlaceObjectOnMap: re-inserts an object into the city map as a
   building (0x4dc9a0). */
extern int DAT_00568188[];

struct City;

struct Building {
    char pad[0x20];
    int value20;
    char pad2[0x24];
    int kind;
};

struct City {
    struct Building *GetRandomBuildingOfType(void *object, void *other, int flag);
    void SpawnByKind(void *object, int kind, int flag, void *other, int value);

    void PlaceObjectOnMap(void *object, void *other);
};

void City::PlaceObjectOnMap(void *object, void *other)
{
    struct Building *building = GetRandomBuildingOfType(other, object, 1);

    if (building != 0) {
        int base = building->value20;
        int adjustment = building->kind;
        int kind;

        if (adjustment >= 0 && adjustment < 4) {
            adjustment = DAT_00568188[adjustment];
        }
        base -= adjustment;
        kind = *(int *)((char *)object + 0x48);
        if (kind >= 0 && kind < 4) {
            kind = DAT_00568188[kind];
        }
        SpawnByKind(object, 5, -1, other, kind + base);
    }
}
