/* Game_ResetStats: clears the game's statistics fields and history grid
   (0x50fdf0). */
struct Game;

void __fastcall Game_ResetStats(Game *game)
{
    int *first;
    int i;

    *(int *)((char *)game + 0x240) = 1;
    *(int *)((char *)game + 0x244) = 0;
    *(int *)((char *)game + 0x248) = 0;
    *(int *)((char *)game + 0x24c) = 0;
    *(int *)((char *)game + 0x250) = 0;
    *(int *)((char *)game + 0x254) = 0;
    *(int *)((char *)game + 600) = 0;
    *(int *)((char *)game + 0x25c) = 0;
    *(int *)((char *)game + 0x260) = 0;
    first = (int *)((char *)game + 0x284);
    i = 8;
    do {
        first[-8] = 0;
        *first = 0;
        first[8] = 0;
        first[0x10] = 0;
        first++;
        i--;
    } while (i != 0);
}
