/* Personnel_Load - 0x4b0d40, 17 bytes */
struct CRT_IStream
{
    void Read(void *dest, int size);
};

extern char DAT_0056a6d8;

void Personnel_Load(CRT_IStream *stream)
{
    stream->Read(&DAT_0056a6d8, 4);
}
