/* Game_GetStartingCapital: returns the starting capital for the selected
   difficulty level (0x48d3a0). */
extern "C" unsigned int DAT_0057bb24;

extern "C" unsigned int __cdecl Game_GetStartingCapital(void)
{
    switch (DAT_0057bb24) {
    case 0: return 1000000;
    case 1: return 500000;
    case 2: return 200000;
    case 3: return 100000;
    case 4: return 75000;
    case 5: return 50000;
    case 6: return 40000;
    case 7: return 30000;
    case 8: return 25000;
    case 9: return 22000;
    default: return 20000;
    }
}
