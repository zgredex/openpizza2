/* UI_Child_Destroy (0x520b10, 48 bytes).  Build: /O2 /TP.
   Destructor: restores the vtable, detaches from the parent, and frees the
   two owned buffers. */
extern int DAT_0055c720;
extern "C" void Mem_Free(void *memory);

struct UI {
    void DetachChild(void);
};

extern "C" void __fastcall UI_Child_Destroy(int *object)
{
    *object = (int)&DAT_0055c720;
    ((UI *)object)->DetachChild();
    if (*(void **)((char *)object + 0xc) != 0)
        Mem_Free(*(void **)((char *)object + 0xc));
    if (*(void **)((char *)object + 0x10) != 0)
        Mem_Free(*(void **)((char *)object + 0x10));
}
