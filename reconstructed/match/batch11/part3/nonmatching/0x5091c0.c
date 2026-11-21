struct ListItem {
    char pad[0x28];
    double height;
    char pad2[0x18];
};
struct ListEntry {
    char pad[0x48];
    int count;
    struct ListItem *items;
    void SetPosition(int index, double value);
};
struct Ref {
    int index;
    char pad[0x54];
    struct ListEntry *list;
};
struct UI {
    char pad[0xc8];
    struct Ref *ref;
};
static const double ZERO = 0.0;
void __fastcall UI_SetListEntryHalfScale(int param_1)
{
    struct UI *ui = (struct UI *)param_1;
    struct Ref *ref = ui->ref;
    struct ListEntry *list;
    int index;

    if (ref == 0)
        return;
    list = ref->list;
    if (list == 0)
        return;
    index = ref->index;
    if (index >= 0 && index < list->count) {
        list->SetPosition(index, list->items[index].height * 0.5);
        return;
    }
    list->SetPosition(index, ZERO * 0.5);
}
