extern "C" int __cdecl Random_RangeFast(int min, int max);
extern char *DAT_0057c670;

/* Branch_PickRandomActiveCounter: picks a random active counter from the branch
   map (0x480c40). */
struct IDMap {
    void *Lookup(int index, int *out);
    void Add(void *value);
    void Destroy();
};

struct List {
    char pad[0x14];
    int count;
};

extern "C" void __cdecl List_Construct(void *list, int zero);
extern "C" void __cdecl List_Node_Destroy(void *list);

extern "C" int __cdecl Branch_PickRandomActiveCounter(char *branch)
{
    char list[0x28];
    int i;
    int count;
    int value;

    List_Construct(list, 0);
    count = *(int *)(branch + 0x19ac);
    i = 0;
    if (0 < count) {
        do {
            int record = (int)((IDMap *)(branch + 0x1998))->Lookup(i, &value);

            if (*(int *)(record + 0x1c) != 0) {
                ((IDMap *)list)->Add((void *)value);
            }
            i = i + 1;
        } while (i < count);
    }
    if (*(int *)(list + 0x14) < 1) {
        List_Node_Destroy(list);
        return -1;
    }
    i = Random_RangeFast(0, *(int *)(list + 0x14) - 1);
    value = (int)((IDMap *)list)->Lookup(i, 0);
    List_Node_Destroy(list);
    return value;
}
