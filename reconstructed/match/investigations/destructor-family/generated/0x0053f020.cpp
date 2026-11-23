extern "C" void __cdecl Mem_Free(void *);
extern "C" __declspec(dllimport) void __stdcall CoUninitialize(void);
struct Child {
    virtual void slot0();
    virtual void slot1();
    virtual void __stdcall Destroy();
};

struct SoundStream {
    virtual void slot0();
    virtual void __stdcall Release();
    void Close(int length);
};

struct ComObject {
    virtual void slot0();
    virtual void __stdcall Release();
    virtual void __stdcall Release2();
};
struct SoundBufferBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual ~SoundBufferBase() {}
};

struct SoundBuffer : SoundBufferBase {
    int field4;
    Child *child;
    unsigned char initialized;
    virtual ~SoundBuffer();
};

SoundBuffer::~SoundBuffer()
{
    if (child != 0) { child->Destroy(); }
    if (initialized != 0) { CoUninitialize(); }
}
