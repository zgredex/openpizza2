/* TimerClass_ScalarDeletingDestructor (0x403a40). */
void __fastcall Timer_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall TimerClass_ScalarDeletingDestructor(void *this_, int dummy,
                                                      unsigned char flags)
{
    Timer_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
