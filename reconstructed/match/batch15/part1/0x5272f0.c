/* UI_ShowTooltip: starts the tooltip movie at the requested or default
   position (0x5272f0). */
struct Movie {
    char pad[0x14];
    int field14;

    void PlayFile(int x, int y, int w, int h, void *text);
};

struct UI {
    void ShowTooltip(void *text, int x, int y);
};

void UI::ShowTooltip(void *text, int x, int y)
{
    Movie *movie = *(Movie **)((char *)this + 0x244);

    if (movie->field14 == 0) {
        if (x == -999) {
            x = *(int *)((char *)this + 0x82e4) + *(int *)((char *)this + 0x248);
        }
        if (y == -999) {
            y = *(int *)((char *)this + 0x82e8) + *(int *)((char *)this + 0x24c);
        }
        movie->PlayFile(x, y, *(int *)((char *)this + 0x270),
                        *(int *)((char *)this + 0x274), text);
        *(int *)((char *)this + 0x234) = 1;
        *(int *)((char *)this + 0x82f0) = 1;
    } else {
        *(int *)((char *)this + 0x82f0) = 1;
    }
}
