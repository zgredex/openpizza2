/* UI_ListEntry_Destroy: list-entry destructor; installs its vtable and frees
   the two owned blocks (0x403480).  Build: /O2. */
void __cdecl Mem_Free(void *block);

void __fastcall UI_ListEntry_Destroy(void *self, int dummy)
{
    *(void **)self = (void *)0x55c2f8;
    if (*(void **)((char *)self + 0x44) != 0)
        Mem_Free(*(void **)((char *)self + 0x44));
    if (*(void **)((char *)self + 0x48) != 0)
        Mem_Free(*(void **)((char *)self + 0x48));
}
