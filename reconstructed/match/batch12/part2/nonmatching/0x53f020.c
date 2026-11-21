/* SoundBuffer_DestructBase (0x53f020): best genuine C++ attempt.  The
   original registers an exception frame and uses the handler thunk at
   0x55ae08; the natural destructor below emits no SEH prologue. */
extern char DAT_0055c830;
extern char DAT_0055c840;
extern "C" __declspec(dllimport) void __stdcall CoUninitialize(void);

struct RefObject {
    virtual void Destroy();
};

struct SoundBuffer {
    void *vtable;
    int field4;
    struct RefObject *child;
    char initialized;

    void DestructBase();
};

void SoundBuffer::DestructBase()
{
    *(void **)this = &DAT_0055c830;
    if (child != 0) {
        child->Destroy();
    }
    if (initialized != 0) {
        CoUninitialize();
    }
    *(void **)this = &DAT_0055c840;
}
