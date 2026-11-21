/* Media_SetValue94 (0x5433e0): stores a value into a media object while
   holding its critical section and reports the object's current state. */
extern "C" {
__declspec(dllimport) void __stdcall EnterCriticalSection(int *section);
__declspec(dllimport) void __stdcall LeaveCriticalSection(int *section);
}

struct Media {
    char pad[0x94];
    int value;
    int state;
    char pad2[4];
    int criticalSection[6];
};

int __stdcall Media_SetValue94(Media *media, int value)
{
    int state;

    EnterCriticalSection(media->criticalSection);
    state = media->state;
    if (state < 0) {
        LeaveCriticalSection(media->criticalSection);
        return state;
    }
    media->value = value;
    LeaveCriticalSection(media->criticalSection);
    return 0;
}
