/* Recipe_SetOnMenu: marks a recipe as on/off the menu and refreshes ratings
   (0x4e3460). */
struct UI {
    void QueueControlCommand(int command, int first, int second);
};

struct Company {
    void InvalidateAllBranchRatings();
};

extern int DAT_0057c670;

struct Recipe {
    char pad[0x1dc];
    unsigned char onMenu;
    void SetOnMenu(int record, unsigned char value);
};

void Recipe::SetOnMenu(int record, unsigned char value)
{
    if (record != 0) {
        *(unsigned char *)(record + 0x1dc) = value;
        ((struct Company *)this)->InvalidateAllBranchRatings();
        if (*(void **)(DAT_0057c670 + 0x264) != 0) {
            ((struct UI *)*(void **)(DAT_0057c670 + 0x264))
                ->QueueControlCommand(-0x18658, 0x23, 0);
        }
    }
}
