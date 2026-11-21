/* UI_ListEntry_ConstructWithValue: initialises a dialog list entry with a
   label, an id, and an extra value (0x403300). */
extern char DAT_0055c2f8;
extern "C" char *strcpy(char *dest, const char *source);

struct UI_ListEntry {
    void *vtable;
    char label[0x40];
    int field44;
    int field48;
    int id;
    int field50;
    int value;

    UI_ListEntry *ConstructWithValue(char *text, int id, int value);
};

UI_ListEntry *UI_ListEntry::ConstructWithValue(char *text, int id, int value)
{
    this->id = id;
    this->value = value;
    *(void **)this = &DAT_0055c2f8;
    field44 = 0;
    field48 = 0;
    strcpy(label, text);
    return this;
}
