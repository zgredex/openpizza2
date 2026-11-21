/* PC2 byte-match candidate: Sprite_SetHotspot (0x53d140, 27 bytes).
   Build: /O2 /TP.  Stores the hotspot only when the sprite is interactive. */
struct Sprite {
    unsigned char pad_000[4];
    unsigned char flags;
    unsigned char pad_005[5];
    unsigned short hotspot_x;
    unsigned short hotspot_y;
    void SetHotspot(unsigned short x, unsigned short y);
};

void Sprite::SetHotspot(unsigned short x, unsigned short y)
{
    if (flags & 4) {
        hotspot_x = x;
        hotspot_y = y;
    }
}
