/* IngredientPanel_Save: writes the ingredient panel state to a stream
   (0x499590). */
struct OStream {
    void Write(void *buffer, int size);
};

extern char DAT_00568910;

void __cdecl IngredientPanel_Save(OStream *stream)
{
    stream->Write(&DAT_00568910, 4);
}
