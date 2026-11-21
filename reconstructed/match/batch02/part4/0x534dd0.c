/* PC2 byte-match candidate: Gfx_RectList_Destroy (0x534dd0, 17 bytes).
   Build: /O2 /TP; entry _Gfx_RectList_Destroy. */
extern "C" void __cdecl Mem_Free(void *block);
extern void *g_GfxRectListVtable;

struct Gfx_RectList {
    void *vtable;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *buffer;
};

extern "C" void __fastcall Gfx_RectList_Destroy(Gfx_RectList *list)
{
    void *buffer = list->buffer;

    list->vtable = &g_GfxRectListVtable;
    Mem_Free(buffer);
}
