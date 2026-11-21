/* Screen_AddRecordToPanel: appends a record from the screen's panel list (0x509290). */
struct List {
    void Add(void *item);
};

struct Screen {
    char pad[0x114];
    List list;
    void AddRecordToPanel(char *record);
};

void Screen::AddRecordToPanel(char *record)
{
    list.Add(*(void **)(record + 0x164));
}
