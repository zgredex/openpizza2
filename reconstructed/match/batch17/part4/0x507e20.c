struct Array {
    int GetRecord28(int value, int key);
};

struct Object {
    void Deactivate(void *record);
    void SetFieldFC(void *record);
    void SetState(int state);
};

struct State {
    int IsMenuState();
};

struct Person {
    void DecideWaitOrLeaveHouse();
    void AdvanceRoute(int index);
};

struct GameData {
    char pad[0x240];
    int lock;
};

extern GameData *DAT_0057c670;
void __fastcall CS_Enter(int section);
void __fastcall CS_Leave(int section);

struct MapObject {
    char pad0[0x30];
    int type;
    char pad1[0x74 - 0x34];
    int field74;
    char pad2[0x90 - 0x78];
    int state;
    char pad3[0xa0 - 0x94];
    int fieldA0;
    char pad4[0xc4 - 0xa4];
    void *array;
    char pad5[0xf4 - 0xc8];
    void *target;
    int fieldF8;
    void *fieldFC;
    void SetDestinationAndTarget(int destination, void *target);
};

void MapObject::SetDestinationAndTarget(int destination, void *target)
{
    if (*(int *)((char *)this + 0x30) != 0x2e) {
        CS_Enter(*(int *)((char *)DAT_0057c670 + 0x240));
        Array *array = (Array *)*(void **)((char *)this + 0xc4);
        int index = array->GetRecord28(1, *(int *)((char *)target + 0x54));
        *(int *)((char *)this + 0x90) = destination;
        *(int *)((char *)this + 0xf8) = index;
        if (*(void **)((char *)this + 0xfc) != 0)
            ((Object *)this)->Deactivate(*(void **)((char *)this + 0xfc));
        ((Object *)this)->SetFieldFC(target);
        if (*(int *)((char *)target + 4) == 0xf)
            *(void **)((char *)this + 0xf4) = target;
        else if (*(int *)((char *)this + 0xa0) != 0)
            ((Object *)this)->SetState(2);
        else
            ((Person *)this)->DecideWaitOrLeaveHouse();
        if (((State *)this)->IsMenuState() != 0)
            ((Person *)this)->DecideWaitOrLeaveHouse();
        ((Person *)this)->AdvanceRoute(index);
        CS_Leave(*(int *)((char *)DAT_0057c670 + 0x240));
    }
}
