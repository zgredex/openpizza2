/* UI_SyncSelectedChild: copies the selected child's record pointer (0x483120). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct UI {
    char pad[0x27c];
    IDMap *map;
    int key;
    char pad2[4];
    int selected;
    void SyncSelectedChild();
};

void UI::SyncSelectedChild()
{
    int *record = map->Lookup(key, 0);

    selected = record[0x13];
}
