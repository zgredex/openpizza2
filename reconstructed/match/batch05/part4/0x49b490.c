/* CompanyMarketShare_Save: writes the share value and flag to a stream (0x49b490). */
struct Stream {
    int Write(void *buffer, int size);
};

extern int DAT_0057ca90;
extern char DAT_005689f0;

void __cdecl CompanyMarketShare_Save(Stream *stream)
{
    stream->Write(&DAT_0057ca90, 4);
    stream->Write(&DAT_005689f0, 1);
}
