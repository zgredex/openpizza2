/* State_HasFlags: true when either state word is positive (0x4d42c0). */
unsigned char __fastcall State_HasFlags(char *this_)
{
    unsigned char flag;

    if (*(int *)(this_ + 0x14) > 0)
        return 1;
    flag = *(int *)(this_ + 0x18) > 0;
    return flag;
}
