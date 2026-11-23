// Game_FindPreviousFreeObjectOfType: previous free object of a matching type.

struct IDMap {
    void *Lookup(int key, int *index);
};

struct List_Node {
    void Destroy();
};

struct List {
    int fields[7];
    void Construct(int capacity);
    void Add(void *value);
    ~List() { ((List_Node *)this)->Destroy(); }
};

struct State {
    int Is2DOr2E();
};

struct Game {
    void *FindPreviousFreeObjectOfType(void *reference);
};

void *Game::FindPreviousFreeObjectOfType(void *reference)
{
    List list;
    int type;
    int count;
    int index;

    list.Construct(0);
    type = *(int *)((char *)reference + 0x30);
    index = 0;
    if (*(int *)((char *)this + 0x50) > 0) {
        do {
            void *object = ((IDMap *)((char *)this + 0x3c))->Lookup(index, 0);
            if (((State *)object)->Is2DOr2E() == 0 &&
                *(int *)((char *)object + 0x30) == type &&
                *(int *)((char *)object + 0x74) == 0 &&
                *(int *)((char *)object + 0x110) == -1)
                list.Add(object);
            index++;
        } while (index < *(int *)((char *)this + 0x50));
    }
    count = list.fields[5];
    if (count > 0) {
        for (index = 0; index < count; index++) {
            if (((IDMap *)&list)->Lookup(index, 0) == reference)
                break;
        }
    }
    if (index == 0)
        index = count - 1;
    else
        index--;
    return ((IDMap *)&list)->Lookup(index, 0);
}
