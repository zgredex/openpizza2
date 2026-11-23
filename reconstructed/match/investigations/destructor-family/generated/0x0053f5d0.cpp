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

struct SoundSample : SoundBufferBase {
    int field4;
    SoundStream *stream;
    int streamLength;
    void *field10;
    char pad4[0x28];
    void *field3c;
    virtual ~SoundSample();
};

SoundSample::~SoundSample()
{
    if (field3c != 0) { Mem_Free(field3c); }
    if (streamLength != 0) { stream->Close(streamLength); }
    if (field10 != 0) { Mem_Free(field10); }
    if (stream != 0) { stream->Release(); }
}
