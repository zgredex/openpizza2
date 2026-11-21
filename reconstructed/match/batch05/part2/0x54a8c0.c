/* UI_BriefingList_Delete: scalar deleting destructor (0x54a8c0). */
void __fastcall UI_BriefingList_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_BriefingList_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_BriefingList_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
