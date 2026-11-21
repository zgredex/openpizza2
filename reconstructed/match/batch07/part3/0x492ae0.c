/* TakeoverScreen_UpdateRatingBars: fills the eight company rating bars
   (0x492ae0). */
struct Stats {
    int GetAverage8(int index);
};

void __cdecl Rating_UpdateBarByKey(void *screen, int key, int index,
                                   int value, int average);

extern Stats *DAT_0057c6cc;
extern int DAT_005826d8;

void __cdecl TakeoverScreen_UpdateRatingBars(void *screen)
{
    int index;

    for (index = 0; index < 8; index++) {
        Rating_UpdateBarByKey(screen, 0x4ef, index,
                              DAT_0057c6cc->GetAverage8(index),
                              DAT_005826d8);
    }
}
