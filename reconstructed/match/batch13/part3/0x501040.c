/* UI_RemoveListEntryByType (0x501040). */
struct UI {
    void RemoveListEntryAt(int list, int index);
    void RemoveListEntryByType(int list, int type, int key);
};

void UI::RemoveListEntryByType(int list, int type, int key)
{
    if (type == 2) {
        int i = 0;
        int *entry = (int *)((char *)this + list * 0x168 + 0x74);
        while (i < 10) {
            if (*entry == key) {
                RemoveListEntryAt(list, i);
                return;
            }
            i = i + 1;
            entry = entry + 4;
        }
    }
    {
        int i;
        int *entry = (int *)((char *)this + list * 0x168 + 0x74);
        for (i = 0; i < 10; ) {
            if (entry[3] == type && *entry == key) {
                goto found;
            }
            i = i + 1;
            entry = entry + 4;
        }
        return;
    found:
        RemoveListEntryAt(list, i);
    }
}
