/* UI_Manager_ScalarDeletingDestructor: scalar deleting destructor (0x523590). */
void __fastcall UI_Manager_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_Manager_ScalarDeletingDestructor(void *this_, int dummy, unsigned char flags)
{
    UI_Manager_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
