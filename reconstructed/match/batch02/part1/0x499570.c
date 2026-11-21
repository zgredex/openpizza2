/* IngredientPanel_Load: reads the ingredient panel state from a stream
   (0x499570). */
struct IStream {
    void Read(void *buffer, int size);
};

extern char DAT_00568910;

void __cdecl IngredientPanel_Load(IStream *stream)
{
    stream->Read(&DAT_00568910, 4);
}
