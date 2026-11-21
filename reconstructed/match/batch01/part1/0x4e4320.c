/* BuildingValue_Delete: scalar deleting destructor (0x4e4320). */
void __fastcall BuildingValue_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall BuildingValue_Delete(void *this_, int dummy, unsigned char flags)
{
    BuildingValue_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
