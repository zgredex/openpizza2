/* Game_AddObjectToStateList: appends an object's state record to a list (0x47d210). */
struct List {
    void Add(void *item);
};

struct GameObject {
    char pad[0x1728];
    List states;
    void AddObjectToStateList(void *obj);
};

void GameObject::AddObjectToStateList(void *obj)
{
    states.Add(*(void **)((char *)obj + 0x164));
}
