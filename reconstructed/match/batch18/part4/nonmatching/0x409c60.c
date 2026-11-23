/* AdCampaign_GoToNextQueuedBuilding: sends an ad campaign to its next queued
   building (0x409c60). */
struct IDMap {
    void *Lookup(int index, int *unused);
    void RemoveRecursive(int index);
};

struct Object {
    void SetState(int state);
    void SetChildField2C(int value);
};

struct UI {
    void DetachChildRecord();
};

struct Array {
    int GetRecord28(int index, int offset);
};

struct Person {
    void AdvanceRoute(int route);
};

struct AdCampaign {
    int GoToNextQueuedBuilding(void *game, char *object);
};

int AdCampaign::GoToNextQueuedBuilding(void *game, char *object)
{
    void *records;
    int result;

    if (*(int *)(object + 0x128) <= 0) {
        return 0;
    }
    records = *(void **)(object + 0xc4);
    do {
        int record;

        record = (int)((IDMap *)(object + 0x114))->Lookup(0, 0);
        record = (int)((IDMap *)((char *)this + 0x3c))->Lookup(record, 0);
        if (*(int *)(record + 0x38) == 0xb &&
            *(int *)(record + 0xf4) == *(int *)((char *)game + 0x16f0)) {
            ((Object *)object)->SetState(0xf);
            ((UI *)object)->DetachChildRecord();
            *(int *)(object + 0x10c) = *(int *)(record + 0x164);
            ((Object *)object)->SetChildField2C(0);
            {
                struct TableEntry { int f0; int f4; int f8; };
                TableEntry *entries = (TableEntry *)*(int *)((char *)records + 0x4c);
                int value = *(int *)((char *)&entries[*(int *)(record + 0x8c)] + 8);

                ((Person *)object)->AdvanceRoute(((Array *)records)->GetRecord28(1,
                    *(short *)((char *)value + 0x24)));
            }
            result = 1;
        } else {
            result = 0;
        }
        ((IDMap *)(object + 0x114))->RemoveRecursive(0);
    } while (result == 0 && 0 < *(int *)(object + 0x128));
    return result;
}
