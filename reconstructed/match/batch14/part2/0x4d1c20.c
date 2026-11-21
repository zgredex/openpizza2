/* RecipeTopping_Load (0x4d1c20): reads a recipe-topping record from a save
   stream. */
struct CRT_Istream {
    void Read(void *data, unsigned int size);
};

struct RecipeTopping {
    char pad[4];
    unsigned char field4;      /* 0x04 */
    unsigned char field5;      /* 0x05 */
    unsigned char field6;      /* 0x06 */
    char pad2[0x08 - 0x07];
    int field8;                /* 0x08 */
    int fieldc;                /* 0x0c */
    unsigned char field10;     /* 0x10 */
    unsigned char field11;     /* 0x11 */
    char pad3[0x14 - 0x12];
    double field14;            /* 0x14 */
    void Load(CRT_Istream *stream);
};

void RecipeTopping::Load(CRT_Istream *stream)
{
    stream->Read((char *)this + 4, 1);
    stream->Read((char *)this + 5, 1);
    stream->Read((char *)this + 6, 1);
    stream->Read((char *)this + 8, 4);
    stream->Read((char *)this + 0xc, 4);
    stream->Read((char *)this + 0x10, 1);
    stream->Read((char *)this + 0x11, 1);
    stream->Read((char *)this + 0x14, 8);
}
