/* CompanyMarketShare_Load: reads the share value and flag from a stream (0x49b460). */
struct Stream {
    int Read(void *buffer, int size);
};

extern int DAT_0057ca90;
extern char DAT_005689f0;

void __cdecl CompanyMarketShare_Load(Stream *stream)
{
    stream->Read(&DAT_0057ca90, 4);
    stream->Read(&DAT_005689f0, 1);
}
