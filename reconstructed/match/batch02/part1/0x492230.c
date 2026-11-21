/* BranchDesign_ColorIndex_Load: reads the branch color index from a stream
   (0x492230). */
struct IStream {
    void Read(void *buffer, int size);
};

extern char DAT_0057c6bc;

void __cdecl BranchDesign_ColorIndex_Load(IStream *stream)
{
    stream->Read(&DAT_0057c6bc, 4);
}
