/* Player_SetSlotFlag18 - 0x4d8d30, 18 bytes */
void __fastcall Player_SetSlotFlag18(void *this_, int unused, int index)
{
    *(char *)((char *)this_ + index * 0x18 + 0x10e5) = 1;
}
