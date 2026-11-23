extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *section);

class LockGuard {
    void *section;
public:
    LockGuard(void *value) : section(value) { EnterCriticalSection(value); }
    ~LockGuard() { LeaveCriticalSection(section); }
};

struct BufferView {
    virtual int __stdcall slot0();
    virtual int __stdcall slot1();
    virtual int __stdcall slot2();
    virtual int __stdcall slot3();
    virtual int __stdcall slot4();
    virtual int __stdcall slot5();
    virtual int __stdcall slot6();
    virtual int __stdcall slot7();
    virtual int __stdcall slot8();
    virtual int __stdcall queryStatus(int *value);
};

struct SoundBuffer {
    char pad[0x98];
    int field98;
    char rest[0xa0 - 0x9c];
    void *lock;
};

int __stdcall QueryStatusLocked(SoundBuffer *self, void *buffer, int *status)
{
    LockGuard guard(&self->lock);
    char result;

    if (self->field98 < 0) {
        return self->field98;
    }
    if (buffer == 0) {
        return -0x7ff8fffa;
    }
    {
        BufferView *view = *(BufferView **)(*(int *)buffer + 0x48);
        if (view == 0) {
            result = 0;
        } else {
            int value = 0;
            if (view->queryStatus(&value) < 0) {
                result = 0;
            } else {
                result = (unsigned char)value & 1;
            }
        }
    }
    *status = result;
    return 0;
}
