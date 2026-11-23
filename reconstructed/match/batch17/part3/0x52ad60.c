struct ListItem {
    char pad0[8];
    int icon;
    char pad1[8];
    int field14;
    char pad2[8];
    int field20;
    char text[1];
};

struct UI {
    char pad0[8];
    void *owner;
    char pad1[0x54 - 0xc];
    int field54;
    char pad2[0xb4 - 0x58];
    int fieldB4;
    char pad3[0xc0 - 0xb8];
    int fieldC0;
    char pad4[0xd4 - 0xc4];
    int fieldD4;
    int fieldD8;
    int fieldDC;
    char pad5[0x1ac - 0xe0];
    char name[1];
    char *FindStringRecord(char *name);
    void BuildListItem(ListItem *item);
};

extern "C" char *strcpy(char *dest, const char *src);

void UI::BuildListItem(ListItem *item)
{
    void *manager = *(void **)(*(int *)((char *)this + 8) + 0x134);
    if (*(int *)((char *)this + 0x54) == 0) {
        if (*(int *)((char *)this + 0xc0) != 0)
            item->icon = 0x70;
        else
            item->icon = 0x6e;
    } else if (*(int *)((char *)this + 0xc0) != 0) {
        item->icon = 0x6f;
    } else {
        item->icon = 0x6d;
    }
    item->field14 = *(int *)((char *)this + 0xb4);
    item->field20 = 3;
    strcpy((char *)item + 0x24,
           ((UI *)manager)->FindStringRecord((char *)this + 0x1ac));
    *(int *)((char *)item + 0x430) = *(int *)((char *)this + 0xd4);
    *(int *)((char *)item + 0x434) = *(int *)((char *)this + 0xd8);
    *(int *)((char *)item + 0x438) = *(int *)((char *)this + 0xdc);
}
