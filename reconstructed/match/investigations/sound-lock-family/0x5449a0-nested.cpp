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

struct MediaView {
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

struct MediaObject {
    char pad[0x38];
    void *lock;
    char rest[0x48 - 0x3c];
    MediaView *view;
    char rest2[0x53 - 0x4c];
    unsigned char field53;
};

int __stdcall Media_QueryFlagLocked(SoundBuffer *self, void *buffer,
                                    unsigned char *status)
{
    LockGuard outer(&self->lock);
    int state = self->field98;
    if (state < 0) {
        return state;
    }
    if (buffer == 0) {
        return -0x7ff8fffa;
    }
    MediaObject *object = *(MediaObject **)buffer;
    unsigned char result;
    {
        LockGuard inner(object->lock);
        if (object->field53 == 0) {
            result = 0;
        } else {
            MediaObject *child = *(MediaObject **)((char *)object + 0x28);
            MediaView *view = child->view;
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
    }
    *status = result;
    return 0;
}
