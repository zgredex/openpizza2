/* Sprite_GetPixelData: realizes a lazy sprite and reads its pixel block (0x53d460). */
struct Sprite {
    char pad[0x18];
    int field18;
    char pad2[0x10];
    int field2c;
    char pad3[9];
    char field39;
    void RealizeLazy();
    int GetPixelData(int *pixels);
};

int Sprite::GetPixelData(int *pixels)
{
    if (field39 == 0)
        RealizeLazy();
    *pixels = field18;
    return field2c;
}
