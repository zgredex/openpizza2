/* PC2 byte-match candidate: Sprite_SetColorKey (0x53d440, 18 bytes).
   Build: /O2 /TP.  Stores the color key and raises the color-key flag bit. */
struct Sprite {
    unsigned char pad_00[4];
    unsigned char flags;
    unsigned char pad_05[0x17];
    int color_key;
    void SetColorKey(int key);
};

void Sprite::SetColorKey(int key)
{
    color_key = key;
    flags = flags | 2;
}
