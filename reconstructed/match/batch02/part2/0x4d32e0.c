/* MapSprite_ReleaseRecordList - 0x4d32e0, 8 bytes */
extern void __fastcall Palette_Free(void *palette);

void __fastcall MapSprite_ReleaseRecordList(void *this_)
{
    Palette_Free((char *)this_ + 0x14);
}
