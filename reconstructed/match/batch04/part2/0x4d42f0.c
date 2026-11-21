/* State_GetFlags: true when all three state words are zero (0x4d42f0). */
unsigned char __fastcall State_GetFlags(int *state)
{
    unsigned char flag;

    if (state[5] != 0)
        return 0;
    if (state[6] != 0)
        return 0;
    flag = state[7] == 0;
    return flag;
}
