/* City_IndexOfListValue: resolves a group record and returns the slot of a
   value in it (0x489b20). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    int FindGroupSlot(int value, int unused);
};

struct City {
    char pad[0x74];
    IDMap groups;
    int IndexOfListValue(int value, int groupKey, int unused);
};

int City::IndexOfListValue(int value, int groupKey, int unused)
{
    int result = -1;
    Game *group = (Game *)groups.Lookup(groupKey, 0);

    if (group != 0)
        result = group->FindGroupSlot(value, unused);
    return result;
}
