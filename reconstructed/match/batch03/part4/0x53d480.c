/* PC2 byte-match candidate: Sprite_GetPixelBuffer (0x53d480, 20 bytes).
   Build: /O2 /TP.  Realizes the lazy sprite first, then returns its buffer. */
struct Sprite {
    unsigned char pad_00[0x2c];
    void *pixel_buffer;
    unsigned char pad_30[9];
    unsigned char realized;
    void RealizeLazy();
    void *GetPixelBuffer();
};

void *Sprite::GetPixelBuffer()
{
    if (realized == 0)
        RealizeLazy();
    return pixel_buffer;
}
