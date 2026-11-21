/* Game_BlitScaledObjectSprite: blits the object sprite with scaling
   (0x4ea400). */
extern int DAT_00580a50;
extern int DAT_0058072c;

struct Sprite {
    void *GetPixelBuffer();
};

struct Gfx {
    void BlitRLEScaled(int a, int b, void *pixels, int c, int d, int e);
};

struct Game {
    void BlitScaledObjectSprite();
};

void Game::BlitScaledObjectSprite()
{
    ((Gfx *)*(void **)((char *)this + 0x2f884))
        ->BlitRLEScaled(*(int *)((char *)this + 0x2f880), DAT_0058072c,
                        ((Sprite *)*(void **)((char *)this + 0x2f884))
                            ->GetPixelBuffer(),
                        *(int *)((char *)this + 0x2f888),
                        *(int *)((char *)this + 0x2f88c), DAT_00580a50);
}
