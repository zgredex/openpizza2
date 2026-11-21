/* Car_Destroy: releases the car's sprite record list and clears its records
   (0x4d3280). */
struct Record {
    void Clear48(int value);
};

struct SpriteList {
    void ReleaseRecordList();
};

extern int DAT_0057c5cc;

struct Car {
    void *vtable;
    char pad[4];
    void *records;
    int slot;
    int recordId;

    void Destroy();
};

void Mem_Free(void *block);

void Car::Destroy()
{
    struct Record *record;
    void *list;

    vtable = (void *)0x55c4f8;
    record = (struct Record *)((int *)records)[0x16];
    if (record != 0) {
        record->Clear48(*(int *)records);
    }
    list = records;
    if (list != 0) {
        ((struct SpriteList *)list)->ReleaseRecordList();
        Mem_Free(list);
    }
    if (recordId != -1) {
        record = *(struct Record **)(DAT_0057c5cc + 0x2c180 + slot * 4);
        record->Clear48(recordId);
    }
}
