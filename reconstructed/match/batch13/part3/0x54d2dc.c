/* Stream_GetReadPosition (0x54d2dc). */
struct StreamState {
    virtual int Slot0(int a, int b, int c);
    virtual int Slot1(int a, int b, int c);
    virtual int Slot2(int a, int b, int c);
    virtual int Transfer(int a, int b, int c);
    char pad04[0x30];
    int lock30;
    char pad34[0x4];
};
struct Thread {
    void SetField8Locked(unsigned value);
};

extern "C" void CS_EnterRaw(void *section);
extern "C" void CS_LeaveRaw(void *section);

extern "C" int __fastcall Stream_GetReadPosition(int *object)
{
    int base = *(int *)(*object + 4);
    struct StreamState *state =
        *(struct StreamState **)((char *)object + base + 4);
    int result;

    if (*(int *)((char *)state + 0x30) < 0) {
        CS_EnterRaw((char *)state + 0x34);
    }
    {
        struct StreamState *target =
            *(struct StreamState **)((char *)object + *(int *)(*object + 4) + 4);
        result = target->Transfer(0, 1, 1);
    }
    if (result == -1) {
        int *owner = (int *)((char *)object + *(int *)(*object + 4));
        ((struct Thread *)owner)->SetField8Locked(
            *(unsigned *)((char *)object + *(int *)(*object + 4) + 8) | 2);
    }
    state = *(struct StreamState **)((char *)object + *(int *)(*object + 4) + 4);
    if (*(int *)((char *)state + 0x30) < 0) {
        CS_LeaveRaw((char *)state + 0x34);
    }
    return result;
}
