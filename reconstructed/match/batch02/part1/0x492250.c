/* BranchDesign_ColorIndex_Save: writes the branch color index to a stream
   (0x492250). */
struct OStream {
    void Write(void *buffer, int size);
};

extern char DAT_0057c6bc;

void __cdecl BranchDesign_ColorIndex_Save(OStream *stream)
{
    stream->Write(&DAT_0057c6bc, 4);
}
