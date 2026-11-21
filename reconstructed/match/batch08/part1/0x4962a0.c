/* CompareScreen_UpdateMenuRatingBars: fills the eight comparison menu-rating
   bars (0x4962a0). */
struct Branch {
    int GetMenuRating(int index);
};

void __cdecl Rating_UpdateBarByKey(void *screen, int key, int index, int value,
                                   int maximum);

extern int DAT_0058271c;

void __cdecl CompareScreen_UpdateMenuRatingBars(void *screen, struct Branch *branch)
{
    int i;

    for (i = 0; i < 8; i++) {
        Rating_UpdateBarByKey(screen, 0x4e8, i, branch->GetMenuRating(i),
                              DAT_0058271c);
    }
}
