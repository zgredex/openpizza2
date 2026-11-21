/* State_Is2DOr2E - 0x50dbd0, 22 bytes */
int __fastcall State_Is2DOr2E(void *this_)
{
    int state = *(int *)((char *)this_ + 0x38);

    if (state == 0x2d || state == 0x2e)
        return 1;
    return 0;
}
