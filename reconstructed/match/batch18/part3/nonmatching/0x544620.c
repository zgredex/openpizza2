extern "C" void __cdecl List_DestroyObjects(int object);

/* SoundBuffer_StopPlaybackLocked: stops playback under the buffer lock
   (0x544620). */
struct SoundBuffer {
    char pad[0x28];
    int field28;
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

extern "C" void __cdecl EnterCriticalSection(void *section);
extern "C" void __cdecl LeaveCriticalSection(void *section);

int SoundBuffer::StopPlaybackLocked()
{
    EnterCriticalSection(lock);
    field54 = 0;
    if (field53 == 0) {
        LeaveCriticalSection(lock);
        return 1;
    }
    field53 = 0;
    field84 = 0;
    field88 = 1;
    if (field58 != 0) {
        field57 = 1;
    }
    {
        int object = field28;
        int *view = *(int **)(object + 0x48);
        unsigned int result;

        if (view == 0) {
            result = 0x80070006;
        } else {
            if ((*(int (__stdcall **)(int *))(*view + 0x48))(view) < 0) {
                result = 0x80004005;
            } else {
                if (*(char *)(object + 0x34) != 0) {
                    List_DestroyObjects(object);
                }
                if ((*(int (__stdcall **)(int *, int))(*view + 0x34))(view, 0) < 0) {
                    result = 0x80004005;
                } else {
                    result = 0;
                }
            }
        }
        LeaveCriticalSection(lock);
        return result;
    }
}
