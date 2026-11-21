/* State_IsMenuState: true for the four menu states (0x50d750). */
int __fastcall State_IsMenuState(int state)
{
    switch (*(int *)(state + 0x30)) {
    case 0xd:
    case 0x17:
    case 0x1d:
    case 0x1e:
        return 1;
    }
    return 0;
}
