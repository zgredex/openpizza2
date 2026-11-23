extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *section);

class LockGuard {
    void *section;
public:
    LockGuard(void *value) : section(value) { EnterCriticalSection(value); }
    ~LockGuard() { LeaveCriticalSection(section); }
};

struct ListObject {
    char pad[0x34];
    unsigned char field34;
    char rest[0x48 - 0x35];
    int *view;
    void DestroyObjects();
    int QueryStatus(int *value);
    int Release(int value);
};

struct SoundBuffer {
    char pad[0x28];
    ListObject *field28;
    char rest[0x38 - 0x2c];
    void *lock;
    char rest2[0x53 - 0x3c];
    unsigned char field53;
    unsigned char field54;
    char rest3[0x58 - 0x55];
    unsigned char field58;
    unsigned char field57;
    char rest4[0x84 - 0x59];
    int field84;
    unsigned char field88;
    int StopPlaybackLocked();
};

int SoundBuffer::StopPlaybackLocked()
{
    LockGuard guard(lock);
    field54 = 0;
    if (field53 == 0) {
        return 1;
    }
    field53 = 0;
    field84 = 0;
    field88 = 1;
    if (field58 != 0) {
        field57 = 1;
    }
    {
        ListObject *object = field28;
        int *view = *(int **)((char *)object + 0x48);
        unsigned int result;

        if (view == 0) {
            result = 0x80070006;
        } else {
            if ((*(int (__stdcall **)(int *))(*view + 0x48))(view) < 0) {
                result = 0x80004005;
            } else {
                if (object->field34 != 0) {
                    object->DestroyObjects();
                }
                int *view2 = *(int **)((char *)object + 0x48);
                if ((*(int (__stdcall **)(int *, int))(*view2 + 0x34))(view2, 0) < 0) {
                    result = 0x80004005;
                } else {
                    result = 0;
                }
            }
        }
        return result;
    }
}
