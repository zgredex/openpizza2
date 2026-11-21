/* UI_SetObjectTextByKey: finds an array entry by key and sets the record's
   text string (0x531f50).  Build: /O2 /TP. */
struct UI {
    void SetTextString(char *text);
};

struct ArrayEntry {
    UI *record;
    int key;
};

struct Array {
    char pad[0xe8];
    ArrayEntry *entries;
    int FindIndex(int key, int mode);
    void SetObjectTextByKey(int key, char *text);
};

void Array::SetObjectTextByKey(int key, char *text)
{
    int index = FindIndex(key, 0);

    if (index != -1)
        entries[index].record->SetTextString(text);
}
