/* BranchStats_SeriesFlags_Save: writes the series flags to a stream
   (0x4919d0). */
struct OStream {
    void Write(void *buffer, int size);
};

extern char DAT_00568628;

void __cdecl BranchStats_SeriesFlags_Save(OStream *stream)
{
    stream->Write(&DAT_00568628, 0x10);
}
