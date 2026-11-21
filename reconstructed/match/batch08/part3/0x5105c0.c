/* Object_DeleteAllInMap: deletes every object in the map and resets it
   (0x5105c0). */
struct IDMap;

struct List_Node {
    void Reset();
};

struct Base {
    virtual void Destroy(int flags);
};

struct IDMap {
    Base *Lookup(int key, int *out);
};

struct Object {
    void DeleteAllInMap();
};

void Object::DeleteAllInMap()
{
    int i = 0;
    int count = *(int *)((char *)this + 0x5c);

    if (count > 0) {
        do {
            Base *object =
                ((IDMap *)((char *)this + 0x48))->Lookup(i, 0);
            if (object != 0)
                object->Destroy(1);
            i++;
        } while (i < count);
    }
    ((List_Node *)((char *)this + 0x48))->Reset();
}
