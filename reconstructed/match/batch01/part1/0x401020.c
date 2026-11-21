/* StatsPeriodReport_Delete: scalar deleting destructor (0x401020). */
void __fastcall StatsPeriodReport_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall StatsPeriodReport_Delete(void *this_, int dummy, unsigned char flags)
{
    StatsPeriodReport_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
