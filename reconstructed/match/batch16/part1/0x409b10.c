// AdCampaign_GoToNearestOwnBuilding @ 0x409b10 (151 bytes)
// Moves an advertising campaign person to the nearest owned building.

class Person;
class Array;

class Map {
public:
    Person *FindNearestCompanyBuilding(int person);
};

class Object {
public:
    void SetState(int state);
    void SetChildField2C(int value);
};

class UI {
public:
    void DetachChildRecord();
};

class Array {
public:
    int GetRecord28(int one, int index);
};

class Person {
public:
    char pad0[0xc4];
    Array *array;
    char pad1[0x10c - 0xc8];
    int field10c;

    void SetState(int state);
    void DetachChildRecord();
    void SetChildField2C(int value);
    int AdvanceRoute(int target);
};

struct Record28Entry {
    int field0;
    int field4;
    int *field8;
};

extern "C" int __stdcall AdCampaign_GoToNearestOwnBuilding(Map *map, Person *person)
{
    Array *array = *(Array **)((char *)person + 0xc4);
    Person *found = map->FindNearestCompanyBuilding((int)person);
    int index;
    Record28Entry *entry;
    int target;

    if (found == 0 || *(int *)((char *)found + 0xc4) != *(int *)((char *)person + 0xc4))
        return 0;
    ((Object *)found)->SetState(0xb);
    ((Object *)person)->SetState(0xc);
    ((UI *)person)->DetachChildRecord();
    *(int *)((char *)person + 0x10c) = *(int *)((char *)found + 0x164);
    ((Object *)person)->SetChildField2C(0x10);
    index = *(int *)((char *)found + 0x8c);
    entry = (Record28Entry *)(*(char **)((char *)array + 0x4c) + index * 0xc);
    target = ((Array *)array)->GetRecord28(1, *(short *)((char *)entry->field8 + 0x24));
    ((Person *)person)->AdvanceRoute(target);
    return 1;
}
