extern "C" void __cdecl Mem_Free(void *);
extern "C" void __fastcall List_DestroyObjects(void *self);

struct BufferInterface {
    virtual void s0();
    virtual void s1();
    virtual void __stdcall Release();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void __stdcall Release2(int value);
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual int __stdcall Query();
};

struct SoundBufferBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual ~SoundBufferBase() {}
};

struct ListNode {
    char pad[4];
    ListNode *next;
};

struct List {
    ListNode *head;
    char pad[4];
    int count;
    int capacity;

    ~List()
    {
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

struct SoundBufferDerived : SoundBufferBase {
    char pad0[0x30];
    unsigned char field34;
    char pad1[3];
    List list;
    BufferInterface *field48;
    virtual ~SoundBufferDerived();
};

SoundBufferDerived::~SoundBufferDerived()
{
    if (field34 != 0) {
        List_DestroyObjects(this);
    }
    if (field48 != 0) {
        if (field48->Query() >= 0) {
            if (field34 != 0) {
                List_DestroyObjects(this);
            }
            field48->Release2(0);
        }
        field48->Release();
    }
}
