/* UI_ListEntry_Construct: initialises a dialog list entry with a label and an
   id (0x403370). */
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

    UI_ListEntry *Construct(char *text, int id);
};

UI_ListEntry *UI_ListEntry::Construct(char *text, int id)
{
    this->id = id;
    *(void **)this = &DAT_0055c2f8;
    strcpy(label, text);
    value = 0;
    field44 = 0;
    field48 = 0;
    return this;
}
