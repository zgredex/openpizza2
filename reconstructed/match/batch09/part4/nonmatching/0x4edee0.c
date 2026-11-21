/* Map_BlitAlignedObjectSprite: aligns and blits an object sprite onto the map
   surface (0x4edee0). */
extern "C" int DAT_0058072c;

struct MapBlit {
    void AlignSpriteToRect(int *rect, void *surface, int **outRect,
                           int **outSurface);
    void BlitAlignedObjectSprite(int *rect, void *surface);
};

struct SpriteSurface {
    void BlitRLEEnsureFormat(int source, int flags, unsigned int x, int y);
};

void MapBlit::BlitAlignedObjectSprite(int *rect, void *surface)
{
    void *saved = surface;

    if (surface != 0) {
        AlignSpriteToRect(rect, surface, &rect, (int **)&surface);
        ((SpriteSurface *)saved)
            ->BlitRLEEnsureFormat(*(int *)((char *)this + 8), DAT_0058072c,
                                  (unsigned int)rect, (int)surface);
    }
}
