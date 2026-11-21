/* PC2 byte-match candidate: Surface_ConfigureFromOwner (0x5377d0, 28 bytes).
   Build: /O2 /TP.  Configures a surface from the owner's stored geometry. */
struct Surface {
    void Configure(int flags, int width, int height, int size);
};

struct SurfaceOwner {
    unsigned char pad_000[4];
    int width;
    int height;
    unsigned char pad_00c[0xc];
    int flags;
    void ConfigureFromOwner(Surface *surface);
};

void SurfaceOwner::ConfigureFromOwner(Surface *surface)
{
    surface->Configure(flags, width, height, width * 2);
}
