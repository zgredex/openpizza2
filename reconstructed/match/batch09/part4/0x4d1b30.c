/* RecipeTopping_StreamConstruct: constructs a recipe topping either from a
   stream or with default field values (0x4d1b30). */
extern "C" int DAT_0055c4e8;

struct RecipeTopping {
    void *vtable;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    int field8;
    int fieldC;
    unsigned char field10;
    unsigned char field11;
    int field14;
    int field18;

    void Load(void *stream);
    RecipeTopping *StreamConstruct(void *stream);
};

RecipeTopping *RecipeTopping::StreamConstruct(void *stream)
{
    vtable = &DAT_0055c4e8;
    if (stream != 0) {
        Load(stream);
    } else {
        field4 = 0xff;
        field8 = -1;
        field5 = 0xff;
        fieldC = -1;
        field6 = 0xff;
        field14 = -1;
        field10 = 0xff;
        field18 = -1;
        field11 = 0;
    }
    return this;
}
