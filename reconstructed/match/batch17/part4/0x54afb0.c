struct IDMap {
    int unused;
    int *Lookup(int index, int *out);
};

struct Array {
    void *GetRecordByKeyPtr(int key);
};

struct UI {
    IDMap map;
    char pad0[0x18 - 0x8];
    int count;
    char pad1[0x30 - 0x1c];
    int field30;
    Array *array;
    void RemoveObject(int id);
    void RemoveAllById(int id);
};

struct Object {
    char pad0[8];
    int field8;
    char pad1[0x1c - 0xc];
    float field1C;
};

void UI::RemoveAllById(int id)
{
    if (id != 0 && *(int *)((char *)this + 0x34) != 0) {
        int count = *(int *)((char *)this + 0x18);
        int i = 0;
        if (0 < count) {
            do {
                int *record = ((IDMap *)((char *)this + 4))->Lookup(i, 0);
                if (*(int *)((char *)record + 8) != -1) {
                    if (((Array *)*(void **)((char *)this + 0x34))
                            ->GetRecordByKeyPtr(*(int *)((char *)record + 8)) != 0) {
                        ((UI *)*(void **)((char *)this + 0x34))
                            ->RemoveObject(*(int *)((char *)record + 8));
                        *(int *)((char *)record + 8) = -1;
                        *(float *)((char *)record + 0x1c) = -1.0f;
                    }
                }
                i++;
            } while (i < count);
        }
    } else {
        int count = *(int *)((char *)this + 0x18);
        int i = 0;
        if (0 < count) {
            do {
                int *record = ((IDMap *)((char *)this + 4))->Lookup(i, 0);
                if (record != 0)
                    *(int *)((char *)record + 8) = -1;
                i++;
            } while (i < count);
        }
    }
    *(int *)((char *)this + 0x30) = 0;
    *(int *)((char *)this + 0x34) = 0;
}
