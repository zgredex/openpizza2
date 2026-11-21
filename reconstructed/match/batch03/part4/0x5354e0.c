/* PC2 byte-match candidate: Image_FreePixelData (0x5354e0, 18 bytes).
   Build: /O2 /TP.  Frees the pixel buffer when present. */
extern "C" void __cdecl Mem_Free(void *block);

struct Image {
    unsigned char pad[0x460];
    void *pixels;
    void FreePixelData();
};

void Image::FreePixelData()
{
    if (pixels != 0)
        Mem_Free(pixels);
}
