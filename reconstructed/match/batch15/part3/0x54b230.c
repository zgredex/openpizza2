struct CRT_Istream {
    void Read(void *dst, int size);
};

struct IDMap {
    void InsertGrow(void *value, int key);
};

void *__cdecl operator_new(unsigned int size);

struct UI {
    void BriefingList_Load(void *stream);
};

void __fastcall UI_DestroyBriefingList(UI *ui);

void UI::BriefingList_Load(void *stream)
{
    UI_DestroyBriefingList(this);
    int count;
    int key;
    int size;
    ((CRT_Istream *)stream)->Read(&count, 4);
    int index = 0;
    if (count > 0) {
        do {
            ((CRT_Istream *)stream)->Read(&key, 4);
            ((CRT_Istream *)stream)->Read(&size, 4);
            char *object = (char *)operator_new(size);
            *(int *)(object + 8) = -1;
            *(void **)(object + 0x18) = this;
            ((CRT_Istream *)stream)->Read(object, size);
            ((IDMap *)((char *)this + 4))->InsertGrow(object, key);
            index++;
        } while (index < count);
    }
}
