/* BranchMenu_Category_Save: writes the category table to a stream (0x4900c0). */
struct OStream {
    void Write(void *buffer, int size);
};

extern char DAT_0057c6a8;

void __cdecl BranchMenu_Category_Save(OStream *stream)
{
    stream->Write(&DAT_0057c6a8, 4);
}
