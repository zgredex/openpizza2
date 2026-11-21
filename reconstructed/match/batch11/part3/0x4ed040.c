/* Surface_AliasPixelPlanes: points the pixel-plane descriptors at the
   interleaved planes for 32/24-bit and 16/8-bit surfaces (0x4ed040). */
struct PixelPlanes {
    char pad[4];
    int red;
    int green;
    int blue;
    int red2;
    int green2;
    int blue2;
};

struct Surface {
    char pad[4];
    struct PixelPlanes *planes;
    char pad2[4];
    int depth;
    int bits;

    void AliasPixelPlanes();
};

extern char DAT_00571b18[];

void NoOp_Stub(void *message);

void Surface::AliasPixelPlanes()
{
    if (depth == 0x40 && bits == 0x20) {
        planes->red = planes->blue;
        planes->green = planes->green2;
        planes->green = planes->green2;
        return;
    }
    if (depth == 0x10 && bits == 0x8) {
        planes->red = planes->red2;
        planes->green = planes->blue2;
        return;
    }
    NoOp_Stub(DAT_00571b18);
}
