void Mem_Free(void *);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void *);
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

struct Entry {
    void *stream;
    void *buffer;
    char pad8[0x10];
    int flag;
};

struct Node {
    char pad0[0x50];
    Node *next;
};

struct ListNode {
    char pad0[4];
    ListNode *next;
};

struct ComInterface19 {
    virtual void __stdcall s0();
    virtual void __stdcall s1();
    virtual void __stdcall s2();
    virtual void __stdcall s3();
    virtual void __stdcall s4();
    virtual void __stdcall s5();
    virtual void __stdcall s6();
    virtual void __stdcall s7();
    virtual void __stdcall s8();
    virtual void __stdcall s9();
    virtual void __stdcall s10();
    virtual void __stdcall s11();
    virtual void __stdcall s12();
    virtual void __stdcall s13(int);
    virtual void __stdcall s14();
    virtual void __stdcall s15();
    virtual void __stdcall s16();
    virtual void __stdcall s17();
    virtual int __stdcall s18();
};
struct CriticalSection {
    char raw[0x18];
    ~CriticalSection() {
    DeleteCriticalSection(raw);
    }
};

struct StreamList {
    ListNode *head;
    char pad4[4];
    int count;
    int capacity;
    ~StreamList() {
    ListNode *node = head;
    while (node != 0) {
        ListNode *next = node->next;
        Mem_Free(node);
        node = next;
    }
    head = 0;
    count = 0;
    capacity = 0;
    }
};

struct TrackBuffer {
    char pad0[8];
    void *field8;
    ~TrackBuffer() {
    if (field8 != 0) { Mem_Free(field8); }
    }
};
struct SoundBufferBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual ~SoundBufferBase() {}
};

struct SoundTrack : SoundBufferBase {
    char pad0[0x24];
    ComObject *field28;
    ComObject *field2c;
    ComObject *field30;
    ComObject *field34;
    char pad4[0x4];
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
