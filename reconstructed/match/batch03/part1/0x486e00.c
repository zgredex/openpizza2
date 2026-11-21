/* Window_UnlockState: clears the lock flag and releases the critical section (0x486e00). */
void __fastcall CS_Leave(void *criticalSection);

void __fastcall Window_UnlockState(char *this_)
{
    *(int *)(this_ + 0x258) = 0;
    CS_Leave(*(void **)(this_ + 0x23c));
}
