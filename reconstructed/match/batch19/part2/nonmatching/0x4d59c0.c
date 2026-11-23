// City_CollectBuildingsByType: collects buildings of a type into a new list.

struct Game {
    int CanShowObject();
};

struct IDMap {
    char *Lookup(int key, int *index);
};

void *operator new(unsigned int size);

struct List {
    int fields[7];
    List(int capacity) { Construct(capacity); }
    void Construct(int capacity);
    void Add(void *value);
};

struct City {
    List *CollectBuildingsByType(int type, void *exclude, char visibleOnly);
};

List *City::CollectBuildingsByType(int type, void *exclude, char visibleOnly)
{
    List *list = new List(0);
    int index = 0;

    if (*(int *)((char *)this + 0xfc0) < 1)
        return list;
    do {
        char *object = ((IDMap *)((char *)this + 0xfac))->Lookup(index, 0);
        if ((*(int *)(object + 4) == type || type == -1) &&
            (visibleOnly == 0 || ((Game *)object)->CanShowObject() != 0) &&
            object != (char *)exclude &&
            *(int *)(object + 0x48) != -1)
            list->Add(object);
        index++;
    } while (index < *(int *)((char *)this + 0xfc0));
    return list;
}
