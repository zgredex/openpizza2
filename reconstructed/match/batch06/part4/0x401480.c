/* List_Node_Destroy: list-node destructor; installs its vtable and frees the
   two owned blocks (0x401480).  Build: /O2. */
void __cdecl Mem_Free(void *block);

void __fastcall List_Node_Destroy(void *self, int dummy)
{
    *(void **)self = (void *)0x55c2ec;
    if (*(void **)((char *)self + 4) != 0)
        Mem_Free(*(void **)((char *)self + 4));
    if (*(void **)((char *)self + 8) != 0)
        Mem_Free(*(void **)((char *)self + 8));
}
