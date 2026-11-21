/* State_IsNegative: true when any state word is negative (0x4d4310). */
unsigned char __fastcall State_IsNegative(int *state)
{
    unsigned char flag;

    if (state[5] < 0)
        return 1;
    if (state[6] < 0)
        return 1;
    flag = state[7] < 0;
    return flag;
}
