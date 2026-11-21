/* UI_AddUniquePair (0x532a30). */
extern void *operator_new(unsigned int size);
struct Array {
    char pad[0x10];
    void *GetPtr(int index);
    void InsertGrow(void *item);
};
struct Pair {
    int first;
    int second;
};
struct UI {
    char pad0[0x2a8];
    Array array;            /* 0x2a8 */
    int count;              /* 0x2b8 */

    void AddUniquePair(int first, int second);
};

void UI::AddUniquePair(int first, int second)
{
    int index = 0;
    int total = count;

    if (total > 0) {
        do {
            Pair *pair = (Pair *)array.GetPtr(index);

            if (pair != 0 && pair->first == first && pair->second == second)
                return;
            index++;
        } while (index < total);
    }
    {
        Pair *pair = (Pair *)operator_new(8);

        pair->first = first;
        pair->second = second;
        array.InsertGrow(pair);
    }
}
