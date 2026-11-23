void Mem_Free(void *);
int CRT_Fclose(void *);
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
struct CriticalSection {
    char raw[0x18];
    ~CriticalSection() {
    DeleteCriticalSection(raw);
    }
};
struct SoundBufferBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual ~SoundBufferBase() {}
};

struct SoundPakManager : SoundBufferBase {
    char pad0[0x4];
    Entry entries[20];
    int count;
    CriticalSection criticalSection;
    char pad3[0x3d4];
    Node *head;
    virtual ~SoundPakManager();
};

SoundPakManager::~SoundPakManager()
{
    while (count > 0) {
        count = count - 1;
        if (entries[count].flag != 0) {
            CRT_Fclose(entries[count].stream);
        }
        Mem_Free(entries[count].buffer);
    }
    while (head != 0) {
        Node *next = head->next;
        Mem_Free(head);
        head = next;
    }
}
