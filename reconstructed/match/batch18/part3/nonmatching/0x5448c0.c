/* Sound_QueryStatusLocked: reads the current buffer status under the sound
   lock (0x5448c0). */
struct BufferView {
    int QueryStatus(int *value);
};

struct SoundBuffer {
    char pad[0x98];
    int field98;
    char rest[0xa0 - 0x9c];
    int lock[6];
    int QueryStatusLocked(void *buffer, int *status);
};

extern "C" void __cdecl EnterCriticalSection(void *section);
extern "C" void __cdecl LeaveCriticalSection(void *section);

int SoundBuffer::QueryStatusLocked(void *buffer, int *status)
{
    int value;
    unsigned char result;

    EnterCriticalSection((char *)this + 0xa0);
    if (field98 < 0) {
        LeaveCriticalSection((char *)this + 0xa0);
        return field98;
    }
    if (buffer == 0) {
        LeaveCriticalSection((char *)this + 0xa0);
        return -0x7ff8fffa;
    }
    {
        int *view = *(int **)(*(int *)buffer + 0x48);

        if (view == 0) {
            result = 0;
        } else {
            value = 0;
            if (view[0] != 0) {
                if ((*(int (__stdcall **)(int *, int *))(*view + 0x24))(view, &value) < 0) {
                    result = 0;
                } else {
                    result = (unsigned char)value & 1;
                }
            } else {
                result = 0;
            }
        }
    }
    *status = result;
    LeaveCriticalSection((char *)this + 0xa0);
    return 0;
}
