/* Sprite_InitFormat (0x53a220): initializes the pixel format fields of a
   sprite from its dimensions and bit depth. */
struct Sprite {
    char pad[4];
    char field4;
    char field5;
    short field6;
    short field8;
    short field_a;
    short field_c;
    char pad2[4];
    short field12;
    short field14;
    char pad3[2];
    int field18;
    int field1c;

    void InitFormat(short width, int a, int b, int bits, char c, short d,
                    short e);
};

void Sprite::InitFormat(short width, int a, int b, int bits, char c,
                        short d, short e)
{
    short rowBytes;

    field_a = d;
    field5 = (char)bits;
    field_c = e;
    field18 = 0;
    rowBytes = (short)((bits >> 3) * width);
    field4 = c;
    field1c = b;
    field8 = (short)a;
    field14 = (short)a;
    field6 = rowBytes;
    field12 = rowBytes;
}
