/* BranchStats_SeriesFlags_Load: reads the series flags from a stream
   (0x4919b0). */
struct IStream {
    void Read(void *buffer, int size);
};

extern char DAT_00568628;

void __cdecl BranchStats_SeriesFlags_Load(IStream *stream)
{
    stream->Read(&DAT_00568628, 0x10);
}
