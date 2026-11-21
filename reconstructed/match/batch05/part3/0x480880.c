/* City_IsIdle: true when a city has no pending activity (0x480880). */
int __fastcall City_IsIdle(int city)
{
    if (*(int *)(city + 0x16f0) == 0)
        return 1;
    return *(int *)(*(int *)(city + 0x16f0) + 0x94) != 0;
}
