/* UI_ShiftChildRect (0x5086e0). */
extern "C" char *g_Game;
extern "C" struct Gfx *DAT_0058072c;

class CS {
public:
    void Enter();
    void Leave();
};

struct Gfx {
    void BlitRectList(int *rect);
};

struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

void __fastcall UI_ShiftChildRect(char *ui)
{
    (*(CS **)(g_Game + 0x240))->Enter();
    if (*(char **)(ui + 0xc8) != 0) {
        ((Rect *)(*(char **)(ui + 0xc8) + 0x5c))->left -=
            *(int *)(*(char **)(ui + 0xc4) + 0x24);
        ((Rect *)(*(char **)(ui + 0xc8) + 0x5c))->right -=
            *(int *)(*(char **)(ui + 0xc4) + 0x24);
        ((Rect *)(*(char **)(ui + 0xc8) + 0x5c))->top -=
            *(int *)(*(char **)(ui + 0xc4) + 0x28);
        ((Rect *)(*(char **)(ui + 0xc8) + 0x5c))->bottom -=
            *(int *)(*(char **)(ui + 0xc4) + 0x28);
        DAT_0058072c->BlitRectList((int *)(*(char **)(ui + 0xc8) + 0x5c));
    }
    (*(CS **)(g_Game + 0x240))->Leave();
}
