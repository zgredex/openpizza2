/* Object_AttachToParent (0x50e730). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Game {
    unsigned RemoveObjectFromList(void *object, int flag);
    void AddObjectToList(void *object);
};
struct Object {
    void SetFieldFC(void *parent);
};
struct Array {
    int GetRecord28(int flag, int index);
};
struct UI {
    void SetChildTracking(int child, int value);
};
struct AttachedObject {
    char pad00[0x54];
    int field54;
    char pad58[0xa4];
    void *fieldFC;
    char pad100[0x34];
    int field134;

    void AttachToParent(void *parent, int addToList);
};
extern "C" char *DAT_0057c670;

void AttachedObject::AttachToParent(void *parent, int addToList)
{
    void *record;
    void *mapRecord;
    int index;

    if (fieldFC != 0) {
        ((struct Game *)fieldFC)->RemoveObjectFromList(this, 0);
    }
    record = ((struct IDMap *)(DAT_0057c670 + 4))->Lookup(
        *(int *)(DAT_0057c670 + 0x2f4), 0);
    mapRecord = *(void **)((char *)record + 0xfa8);
    ((struct Object *)this)->SetFieldFC(parent);
    if (addToList != 0) {
        ((struct Game *)parent)->AddObjectToList(this);
    }
    index = ((struct Array *)mapRecord)->GetRecord28(
        1, *(int *)((char *)parent + 0x54));
    ((struct UI *)this)->SetChildTracking(0, index);
}
