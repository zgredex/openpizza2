extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *section);

class LockGuard {
    void *section;
public:
    LockGuard(void *value) : section(value) { EnterCriticalSection(value); }
    ~LockGuard() { LeaveCriticalSection(section); }
};

struct SoundBuffer {
    char pad[0x98];
    int field98;
    char rest[0xa0 - 0x9c];
    void *lock;
};

struct PlayObject {
    char pad[0x24];
    unsigned short divisor;
    char rest[0x48 - 0x26];
    int *view;
};

struct View {
    virtual int __stdcall slot0();
    virtual int __stdcall slot1();
    virtual int __stdcall slot2();
    virtual int __stdcall slot3();
    virtual int __stdcall getStatus(int *value, int *other);
};

int __stdcall Sound_GetPlayPosition(SoundBuffer *self, int *buffer, unsigned int *status)
{
    LockGuard guard(&self->lock);
    *status = 0;
    int state = self->field98;
    if (state < 0) {
        return state;
    }
    if (buffer == 0) {
        return -0x7ff8fffa;
    }
    PlayObject *object = (PlayObject *)*buffer;
    View *view = (View *)object->view;
    unsigned int result;
    if (view == 0) {
        result = 0;
    } else {
        int value;
        int other;
        result = (view->getStatus(&value, &other) >= 0) ? (unsigned int)value : 0;
    }
    *status = result / object->divisor;
    return 0;
}
