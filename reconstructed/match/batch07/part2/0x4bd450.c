/* UI_SelectPreviousObjectOfType (0x4bd450, 49 bytes).  Build: /O2 /TP.
   Selects the previous free object of the current type and updates the
   selection globals. */
extern int DAT_0057c670;
extern int DAT_0057d6fc;

struct Game {
    int FindPreviousFreeObjectOfType(int current);
};

extern "C" void UI_SelectPreviousObjectOfType(void)
{
    int object = ((Game *)DAT_0057c670)->FindPreviousFreeObjectOfType(
        DAT_0057d6fc);

    if (object != 0) {
        Game *game = (Game *)DAT_0057c670;

        DAT_0057d6fc = object;
        *(int *)((char *)game + 0x21c) = object;
        *(int *)((char *)game + 0x2da8) = 1;
    }
}
