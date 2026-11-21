/* Screen_AddRecordToList: appends a record's object to the list at 0x1744
   (0x47d230). */
struct List {
    void Add(void *item);
};

struct Screen {
    char pad[0x1744];
    List records;
    void AddRecordToList(void *record);
};

void Screen::AddRecordToList(void *record)
{
    records.Add(*(void **)((char *)record + 0x164));
}
