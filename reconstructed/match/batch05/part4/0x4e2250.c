/* Game_FindCityIndex: finds a city record in the seven-entry global table (0x4e2250). */
int __fastcall Game_FindCityIndex(int game)
{
    int city = *(int *)(game + 0x1dc);
    int index = 0;
    int *entry = (int *)0x563874;

    while ((int)entry < 0x563890) {
        if (*entry == city)
            return index;
        entry++;
        index++;
    }
    return 7;
}
