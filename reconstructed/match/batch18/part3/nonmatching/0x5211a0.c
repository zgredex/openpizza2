extern "C" void __cdecl SetObjectRangeByKey(void *ui, int id, int a, int b);
extern "C" void __cdecl SetChildVisibleByID(void *ui, int id, int visible);
extern "C" void __cdecl Array_Destroy(void *array);

/* UI_CustomControl_Destructor: destroys the sprite-backed custom control
   (0x5211a0). */
struct CS {
    void Enter();
    void Leave();
};

struct UI_Child {
    void DetachObject();
    void Destroy();
};

struct UI_CustomControl : UI_Child {
    char pad[0x80];
    void *field80;
    char pad2[0x60];
    void *field60;
    void *field64;
    void *field68;
    void *field6c;
    void *field7c;
    char rest[0x84 - 0x80];
    void DestroyControl();
};

void UI_CustomControl::DestroyControl()
{
    *(void **)this = (void *)0x55c73c;
    DetachObject();
    if (field80 != 0) {
        (*(void (__stdcall **)(int))**(void ***)field80)(1);
    }
    if (field60 != 0) {
        (*(void (__stdcall **)(int))**(void ***)field60)(1);
    }
    if (field64 != 0) {
        (*(void (__stdcall **)(int))**(void ***)field64)(1);
    }
    if (field68 != 0) {
        (*(void (__stdcall **)(int))**(void ***)field68)(1);
    }
    if (field6c != 0) {
        (*(void (__stdcall **)(int))**(void ***)field6c)(1);
    }
    if (field7c != 0) {
        SetObjectRangeByKey(*(void **)((char *)this + 8), *(int *)((char *)field7c + 4),
                            *(int *)((char *)this + 0x38), *(int *)((char *)this + 0x3c));
        SetChildVisibleByID(*(void **)((char *)this + 8), *(int *)((char *)field7c + 4), 1);
    }
    Array_Destroy((char *)this + 0x84);
    UI_Child::Destroy();
}
