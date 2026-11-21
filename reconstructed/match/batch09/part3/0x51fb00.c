/* Screen_BeginTileWipeTransition: starts a tiled screen-wipe transition
   (0x51fb00). */
extern unsigned long (*DAT_0055c294)(void);

struct Screen {
    void AnimateTileWipe(unsigned int param);
    void BeginTileWipeTransition(unsigned int param_1, unsigned int param_2);
};

void Screen::BeginTileWipeTransition(unsigned int param_1, unsigned int param_2)
{
    char *self = (char *)this;

    if (*(int *)(self + 0x34) != 0) {
        if (*(int *)(self + 8) != 0) {
            *(int *)(self + 0xc) = 0;
            AnimateTileWipe(param_1);
        }
        *(int *)(self + 8) = *(int *)(self + 0x34);
        *(unsigned long *)(self + 0xc) = DAT_0055c294();
        *(int *)(self + 0x10) = param_2;
        *(int *)(self + 0x14) = 1;
    }
}
