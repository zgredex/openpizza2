/* Game_GetMaxIndex4: returns the index of the largest of four signed score
   bytes at 0xc8 (0x4e47e0).  Build: /O2. */
unsigned char __fastcall Game_GetMaxIndex4(char *self, int dummy)
{
    unsigned char best = 0;
    int bestValue = -1000;
    int index = 0;

    do {
        int value = (int)*(signed char *)((unsigned char)index + 0xc8 + self);

        if (value >= bestValue) {
            best = (unsigned char)index;
            bestValue = value;
        }
        index++;
    } while (index <= 3);
    return best;
}
