extern "C" void __cdecl Mem_Free(void *);
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
struct TrackBuffer {
    char pad[8];
    void *field8;
    ~TrackBuffer() { if (field8 != 0) { Mem_Free(field8); } }
};
struct SoundTrack : SoundBufferBase {
    char pad0[0x24];
    ComObject *field28;
    ComObject *field2c;
    ComObject *field30;
    ComObject *field34;
    char pad4[4];
    TrackBuffer buffer;
    virtual ~SoundTrack();
};
SoundTrack::~SoundTrack()
{
    if (field28 != 0) { field28->Release(); }
    if (field2c != 0) { field2c->Release(); }
    if (field34 != 0) { field34->Release2(); }
    if (field30 != 0) { field30->Release(); }
}
