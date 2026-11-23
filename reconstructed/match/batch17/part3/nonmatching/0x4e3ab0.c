struct IDMap {
    int unused;
    void *Lookup(int index, int *out);
    void RemoveByKey(int key);
};

struct Plan {
    virtual ~Plan();
    int field4;
    int field8;
    char pad0[0x2c - 0xc];
    int field2C;
};

struct Game {
    void *FindRecordByField24(int value);
    void PlaceObjectInPlayerCity(void *record, int flag);
};

struct Object {
    void SetFacadeAndLogoVariant(int variant, void *record, void *owner);
};

struct GamePlan {
    void SetActiveEffect(int effect, int value);
};

struct Branch {
    void ExpelCustomers(int value);
};

struct GameData {
    char pad0[4];
    IDMap map;
    char pad1[0x9c - 0x8];
    int field9C;
    char pad2[0x2f4 - 0xa0];
    int field2F4;
};

struct Company {
    char pad0[0x48];
    int field48;
    char pad1[0x12c - 0x4c];
    IDMap planMap;
    void DeactivatePlanEntry(Plan *plan, int remove);
};

extern GameData *DAT_0057c670;

void Company::DeactivatePlanEntry(Plan *plan, int remove)
{
    if (plan->field4 != 0) {
        Game *game = (Game *)((IDMap *)((char *)DAT_0057c670 + 4))
                         ->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
        if (plan->field8 == 3) {
            void *record = game->FindRecordByField24(plan->field2C);
            int *object = *(int **)((char *)record + 0x74);
            object[4] = 0;
            object[6] = 0;
            object[2] = 0;
            object[5] = 0;
            game->PlaceObjectInPlayerCity(record, -1);
            ((Object *)game)->SetFacadeAndLogoVariant(0, record, this);
        }
        if (plan->field8 == 2)
            ((Branch *)game)->ExpelCustomers(*(int *)((char *)DAT_0057c670 + 0x9c));
        ((GamePlan *)plan)->SetActiveEffect(0, *(int *)((char *)this + 0x48));
    }
    if (remove != 0 || plan->field8 == 3) {
        ((IDMap *)((char *)this + 0x12c))->RemoveByKey((int)plan);
        if (plan != 0)
            delete plan;
    }
}
