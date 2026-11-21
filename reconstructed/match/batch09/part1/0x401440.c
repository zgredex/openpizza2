/* List_Node_Reset: releases the list node buffers and reinitialises the
   node bookkeeping (0x401440). */
extern void __cdecl Mem_Free(void *block);

void __fastcall List_Node_Reset(int node)
{
    if (*(void **)(node + 4) != 0)
        Mem_Free(*(void **)(node + 4));
    *(int *)(node + 4) = 0;
    if (*(void **)(node + 8) != 0)
        Mem_Free(*(void **)(node + 8));
    *(int *)(node + 8) = 0;
    *(int *)(node + 0x10) = 0;
    *(int *)(node + 0xc) = 0;
    *(int *)(node + 0x14) = 0;
    *(int *)(node + 0x18) = 100000;
}
