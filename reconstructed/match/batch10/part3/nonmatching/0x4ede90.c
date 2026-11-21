/* Non-matching candidate for 0x4ede90 (UI_DrawObjectSprite).
   The compiler loads the sprite parameter into eax and moves it to edi,
   while the original loads edi directly after pushing esi/edi. */
extern int DAT_0058072c;
struct Sprite {
    void BlitWithDefaultAlpha(void *surface, int def_alpha, unsigned *pos,
                              int y, int alpha);
};
struct UI {
    void DrawObjectSprite(int *pos, void *sprite);
    void AlignSpriteToRect(int *pos, void *sprite, int *out_pos, int *out_y);
};
void UI::DrawObjectSprite(int *pos, void *sprite)
{
    void *s = sprite;
    if (s != 0) {
        AlignSpriteToRect(pos, s, (int *)&pos, (int *)&sprite);
        ((Sprite *)s)->BlitWithDefaultAlpha(*(void **)((char *)this + 8),
                                           DAT_0058072c, (unsigned *)pos,
                                           (int)sprite, -1);
    }
}
