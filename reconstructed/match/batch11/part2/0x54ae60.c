/* UI_AdvanceBriefing: marks one briefing entry as advanced and rebuilds its
   button (0x54ae60). */
struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct BriefingEntry {
    int field0;
    int field4;
    int id;
    char pad[4];
    int advanced;
    int field14;
    int field18;
    int field1c;
};

struct ObjectHelper {
    void RemoveObject(int id);
};

struct UI {
    char pad[0x4];
    char map[0x14];
    char pad2[0x1c];
    void *objects;

    void AddBriefingButton(BriefingEntry *entry, int id, int value);
    void AdvanceBriefing(int index);
};

void UI::AdvanceBriefing(int index)
{
    BriefingEntry *entry =
        (BriefingEntry *)((IDMapHelper *)map)->Lookup(index, 0);

    if (entry != 0 && entry->advanced == 0) {
        entry->advanced = 1;
        if (entry->id != -1) {
            ((ObjectHelper *)objects)->RemoveObject(entry->id);
            AddBriefingButton(entry, entry->id,
                              (int)*(float *)&entry->field1c);
        }
    }
}
