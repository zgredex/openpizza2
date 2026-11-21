/* Game_GetCityData: bounds-checked city data table lookup (0x4e4140). */
extern int DAT_0057dfdc[];

int __cdecl Game_GetCityData(int city)
{
    if (city < 0 || city >= 0x9c4)
        return 0;
    return DAT_0057dfdc[city];
}
