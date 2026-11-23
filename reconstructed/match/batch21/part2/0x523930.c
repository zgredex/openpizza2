extern "C" int DebugConsole_Errorf(void *self, int code, char *format, ...);
extern char DAT_005740b0[];
class CS { public: void Enter(); void Leave(); };
class UI { public: int AllocWindowSlot(int *out); };

int UI::AllocWindowSlot(int *out)
{
    *(int *)((char *)this + 0x83b8) = 1;
    ((CS *)*(void **)((char *)this + 0x1c8))->Enter();
    *out = *(int *)((char *)this + 0x83e0);
    (*(int *)((char *)this + 0x83e0))++;
    int count = *(int *)((char *)this + 0x23c);
    int slot = 0;
    while (slot < count) {
        if (((int *)((char *)this + 0x14))[slot] == 0) {
            ((CS *)*(void **)((char *)this + 0x1c8))->Leave();
            return slot;
        }
        slot++;
    }
    ((CS *)*(void **)((char *)this + 0x1c8))->Leave();
    if (slot == 100) {
        DebugConsole_Errorf(this, 3, DAT_005740b0);
        return -1;
    }
    (*(int *)((char *)this + 0x23c))++;
    return slot;
}
