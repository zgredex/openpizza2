/* EmployeeAvatar_Delete: scalar deleting destructor (0x54b620). */
void __fastcall EmployeeAvatar_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall EmployeeAvatar_Delete(void *this_, int dummy, unsigned char flags)
{
    EmployeeAvatar_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
