/* Sprite_GetRenderSize: returns the on-screen size of a sprite, honouring
   rotated sprites (0x53d040). */
struct Sprite {
    void GetRenderSize(unsigned int *width, unsigned int *height);
};

void Sprite::GetRenderSize(unsigned int *width, unsigned int *height)
{
    char *self = (char *)this;

    if (*(int *)(self + 0x30) == 0 || *(char *)(self + 0x37) == 0) {
        *width = *(unsigned short *)(self + 0x12);
        *height = *(unsigned short *)(self + 0x14);
        return;
    }
    *width = *(unsigned short *)(self + 0x14);
    *height = *(unsigned short *)(self + 0x12);
}
