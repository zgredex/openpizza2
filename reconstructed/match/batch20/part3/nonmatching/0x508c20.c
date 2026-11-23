extern int DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Array {
    void *GetRecord28(int a, int b);
};

struct UI {
    void DestroyChildObject();
    void SetChildTracking(int a, int b);
};

struct MapObject {
    void InitRenderRecord(int a, int b, int c);
};

struct Object {
    char pad[0x30];
    int type;
    char pad2[0x50 - 0x34];
    int key50;
    char pad3[0x78 - 0x54];
    int pendingType;
    char pad4[0xc4 - 0x7c];
    int render;
    char pad5[0xf4 - 0xc8];
    int *grid;
    void RebindRenderList(int mode, int value);
    void ApplyPendingType(int type);
    void ApplyDeferredType(int type);
};

extern "C" int __fastcall CS_Enter(int lock);
extern "C" int __fastcall CS_Leave(int lock);
extern "C" int __fastcall Grid_GetRandomRecord28(int grid);

void Object::RebindRenderList(int mode, int value)
{
    unsigned char recordIndex;
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    CS_Enter(*(int *)(DAT_0057c670 + 0x244));
    ((UI *)this)->DestroyChildObject();
    if (pendingType != 0)
        ApplyPendingType(pendingType);
    switch (mode) {
    case 0: {
        render = value;
        if (type == 0x10) {
            void *record = ((IDMap *)(DAT_0057c670 + 0x20))->Lookup(key50, 0);
            recordIndex = *(unsigned char *)((char *)record + 0x824);
            ((MapObject *)this)->InitRenderRecord(0, -1, recordIndex);
        } else {
            ((MapObject *)this)->InitRenderRecord(0, -1, -1);
        }
        void *result = ((Array *)render)->GetRecord28(1, *(int *)((char *)grid + 0x54));
        ((UI *)this)->SetChildTracking(0, (int)result);
        break;
    }
    case 1: {
        render = value;
        ((MapObject *)this)->InitRenderRecord(1, -1, -1);
        int result = Grid_GetRandomRecord28(render);
        ((UI *)this)->SetChildTracking(1, result);
        break;
    }
    }
    if (pendingType != 0) {
        ApplyDeferredType(pendingType);
        pendingType = 0;
    }
    CS_Leave(*(int *)(DAT_0057c670 + 0x244));
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
}
