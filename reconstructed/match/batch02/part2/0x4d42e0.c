/* State_HasPositive - 0x4d42e0, 9 bytes */
char __fastcall State_HasPositive(void *this_)
{
    char positive = *(int *)((char *)this_ + 0x20) > 0;
    return positive;
}
