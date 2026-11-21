/* UI_NotifyObjectsByKey (0x532af0). */
struct Array {
    char pad00[0x10];
    void *GetPtr(int index);
    void *GetRecordByKey(int key);
};
struct NotifyTarget {
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Notify(int message, int key, int value);
};
struct UI {
    char pad00[0x2a8];
    struct Array array2a8;
    int count2b8;

    int NotifyObjectsByKey(int key);
};

int UI::NotifyObjectsByKey(int key)
{
    int result = 0;
    int index = 0;
    int count = count2b8;

    if (count < 1) {
        return 0;
    }
    do {
        int *entry = (int *)array2a8.GetPtr(index);
        if (entry != 0 && entry[1] == key) {
            struct NotifyTarget *target =
                (struct NotifyTarget *) ((struct Array *)this)->GetRecordByKey(*entry);
            if (target != 0) {
                target->Notify(0x3b, key, 0);
                result = 1;
            }
        }
        index = index + 1;
    } while (index < count);
    return result;
}
