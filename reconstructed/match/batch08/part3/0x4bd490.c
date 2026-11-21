/* UI_SelectNextObjectOfType: advances the selected object of a type
   (0x4bd490). */
extern void *DAT_0057c670;
extern int DAT_0057d6fc;

struct Game {
    char pad[0x21c];
    int selected;              /* 0x21c */
    char pad2[0x2da8 - 0x220];
    int hasSelection;          /* 0x2da8 */
    int FindNextFreeObjectOfType(int after);
};

void __cdecl UI_SelectNextObjectOfType(char select)
{
    int found = ((Game *)DAT_0057c670)->FindNextFreeObjectOfType(DAT_0057d6fc);

    if (found != 0) {
        DAT_0057d6fc = found;
        if (select != 0) {
            Game *game = (Game *)DAT_0057c670;
            game->selected = found;
            game->hasSelection = 1;
        }
    }
}
