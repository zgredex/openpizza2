/* UI_Slider_Delete: scalar deleting destructor (0x529140). */
void __fastcall UI_Slider_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_Slider_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_Slider_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
