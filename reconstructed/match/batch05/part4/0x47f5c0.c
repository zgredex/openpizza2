/* Branch_RemoveBuildingObject: unlinks a building object from a branch (0x47f5c0). */
struct List {
    void Remove(void *object, int flag);
};

struct Game {
    void HandleObjectDeath(void *object);
};

extern Game *DAT_0057c670;

struct Branch {
    char pad[0x16f0];
    List *objects;
    void RemoveBuildingObject(void *object);
};

void Branch::RemoveBuildingObject(void *object)
{
    objects->Remove(object, 0);
    DAT_0057c670->HandleObjectDeath(object);
}
