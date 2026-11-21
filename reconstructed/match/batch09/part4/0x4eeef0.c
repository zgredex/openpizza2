/* Buffer_FreeLockedGlobal: frees a locked global buffer while holding the
   game's critical section (0x4eeef0). */
extern "C" {
extern int DAT_0057c670;
extern void Mem_Free(void *block);
void __fastcall CS_Enter(void *section);
void __fastcall CS_Leave(void *section);
}

void __stdcall Buffer_FreeLockedGlobal(void *buffer)
{
    CS_Enter(*(void **)(DAT_0057c670 + 0x248));
    if (0 < *(int *)((char *)buffer + 4)) {
        Mem_Free(*(void **)((char *)buffer + 8));
        *(int *)((char *)buffer + 4) = 0;
    }
    CS_Leave(*(void **)(DAT_0057c670 + 0x248));
}
