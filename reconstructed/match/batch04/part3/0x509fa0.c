/* State_Is1A1B1C: reports whether state is 0x1a, 0x1b or 0x1c (0x509fa0). */
int __fastcall State_Is1A1B1C(char *object)
{
    int state = *(int *)(object + 0x30);

    if (state == 0x1a || state == 0x1b || state == 0x1c) {
        return 1;
    }
    return 0;
}
