/* Sprite_GetHotspot: returns the four-bit hotspot flag's coordinates (0x53d100). */
struct Sprite {
    char pad0[4];
    unsigned char flags;
    char pad1[5];
    short hotspotX;
    short hotspotY;
    void GetHotspot(int *x, int *y);
};

void Sprite::GetHotspot(int *x, int *y)
{
    if ((flags & 4) != 0) {
        *x = hotspotX;
        *y = hotspotY;
        return;
    }
    *x = 0;
    *y = 0;
}
