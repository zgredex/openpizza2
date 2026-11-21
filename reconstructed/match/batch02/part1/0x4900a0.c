/* BranchMenu_Category_Load: reads the category table from a stream (0x4900a0). */
struct IStream {
    void Read(void *buffer, int size);
};

extern char DAT_0057c6a8;

void __cdecl BranchMenu_Category_Load(IStream *stream)
{
    stream->Read(&DAT_0057c6a8, 4);
}
