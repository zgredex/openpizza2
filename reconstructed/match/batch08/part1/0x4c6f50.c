/* CharacterSelect_DrawPortrait: composes the character portrait overlay
   (0x4c6f50). */
struct UI {
    int ComposeOverlayWindow(void *window, int id, int first, int second,
                             int third, int fourth, int fifth);
};

extern int DAT_0057c5ec;
extern int DAT_0057ddac;
extern int DAT_0057dda4;
extern int DAT_0057ddfc;
extern int DAT_0057dda0;
extern int DAT_0057ddb8;

void __cdecl CharacterSelect_DrawPortrait(void *window)
{
    ((struct UI *)DAT_0057c5ec)
        ->ComposeOverlayWindow(window, 0x433, DAT_0057ddac, DAT_0057dda4,
                               DAT_0057ddfc, DAT_0057dda0, DAT_0057ddb8);
}
