/* Person_SetRandomResidentialTarget: sends a person to a random residential
   building (0x508780). */
struct IDMap {
    int field0;
    void *Lookup(int key, int *out);
};

struct Map {
    int GetRandomBuildingOfType(int type, int zero1, int zero2);
};

struct Object {
    void SetDestinationAndTarget(int order, int target);
    void SetRandomResidentialTarget();
};

extern char *DAT_0057c670;

void Object::SetRandomResidentialTarget()
{
    Map *city = (Map *)((IDMap *)(DAT_0057c670 + 4))
                    ->Lookup(*(int *)(DAT_0057c670 + 0x2f4), 0);

    SetDestinationAndTarget(0xd, city->GetRandomBuildingOfType(0x18, 0, 0));
}
