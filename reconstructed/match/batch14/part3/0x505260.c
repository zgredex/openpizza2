/* UI_DestroyChildObject (0x505260): unlinks and frees the child record of a
   UI object.  Returns the result of the list removal (or 0). */
struct Record {
    int field0;
    int field4;
    char pad[0x50];
    Record *field58;

    void Clear48(int value);
    void ReleaseRecordList();
};

struct List {
    int RemoveObject(void *object);
};

struct UI_Global {
    char pad[0x2c3b4];
    Record *record;
};

extern "C" {
void Mem_Free(void *block);
}
extern UI_Global *DAT_0057c5cc;

struct UI {
    char pad[0xc4];
    List *list;
    Record *child;

    int DestroyChildObject();
};

int UI::DestroyChildObject()
{
    Record *record;
    int result;

    if (child == 0)
        return 0;
    result = list->RemoveObject(child);
    if (child->field58 != 0)
        child->field58->Clear48(child->field0);
    DAT_0057c5cc->record->Clear48(child->field4);
    record = child;
    if (record != 0) {
        record->ReleaseRecordList();
        Mem_Free(record);
    }
    child = 0;
    return result;
}
