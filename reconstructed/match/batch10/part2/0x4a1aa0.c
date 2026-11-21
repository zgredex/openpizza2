/* IDMap_DestroyAllObjects: destroy every object in an id map and release
   the map itself (0x4a1aa0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Base {
    virtual void Destroy(int free);
};

extern "C" void IDMap_DestroyAllObjects(struct IDMap **map)
{
    if (*map != 0) {
        int count = *(int *)((char *)*map + 0x14);
        int index;

        for (index = 0; index < count; index++) {
            struct Base *object = (struct Base *)(*map)->Lookup(index, 0);

            if (object != 0)
                object->Destroy(1);
        }
        if (*map != 0)
            ((struct Base *)*map)->Destroy(1);
        *map = 0;
    }
}
