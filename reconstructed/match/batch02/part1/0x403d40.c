/* Input_LeaveLock: leaves the critical section at offset 0x10 (0x403d40). */
void __fastcall CS_Leave(void *section);

void __fastcall Input_LeaveLock(char *this_)
{
    CS_Leave(this_ + 0x10);
}
