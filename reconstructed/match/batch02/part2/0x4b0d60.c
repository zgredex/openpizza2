/* Personnel_Save - 0x4b0d60, 17 bytes */
struct CRT_OStream
{
    void Write(void *src, int size);
};

extern char DAT_0056a6d8;

void Personnel_Save(CRT_OStream *stream)
{
    stream->Write(&DAT_0056a6d8, 4);
}
