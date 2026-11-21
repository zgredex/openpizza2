/* List_FreeContainerValues (0x54c830): frees every value in the container's
   map and resets its node list. */
extern "C" {
void Mem_Free(void *block);
}

struct Entry;

struct IDMap {
    char pad[0x14];
    int count;

    Entry *Lookup(int index, int *value);
};

struct List {
    void Node_Reset();
};

struct Container {
    IDMap *map;
    void *field4;
    void *field8;

    void FreeValues();
};

void Container::FreeValues()
{
    int i;

    if (map != 0) {
        for (i = 0; i < map->count; i++)
            Mem_Free(map->Lookup(i, 0));
        ((List *)map)->Node_Reset();
    }
    if (field4 != 0) {
        field4 = 0;
        field8 = 0;
    }
}
