void Mem_Free(void *);

void __fastcall Memory_FreeAndClear(void **slot)
{
    if (*slot != 0) {
        Mem_Free(*slot);
        *slot = 0;
    }
}
