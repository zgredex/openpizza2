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

struct SoundBuffer2 : SoundBufferBase {
    char pad0[0x4];
    ComObject *field8;
    int state;
    virtual ~SoundBuffer2();
};

SoundBuffer2::~SoundBuffer2()
{
    switch (state) {
    case 0:
        field8->Release();
        break;
    case 1:
        field8->Release();
        break;
    case 2:
        field8->Release();
        break;
    }
}
