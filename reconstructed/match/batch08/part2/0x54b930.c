/* IDMap_DeleteContents: deletes every object in the map and resets its list
   (0x54b930). */
void __fastcall List_Node_Reset(void *node);

struct VObject {
    virtual void Destroy(int flag);
};

struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *out);
};

extern "C" void __stdcall IDMap_DeleteContents(struct IDMap *map)
{
    int count = *(int *)((char *)map + 0x14);
    int index = 0;

    while (index < count) {
        struct VObject *object = (struct VObject *)map->Lookup(index, 0);

        if (object != 0)
            object->Destroy(1);
        index++;
    }
    List_Node_Reset(map);
}
