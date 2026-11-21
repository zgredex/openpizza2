/* AdvertisingPanel_Load: reads the two panel fields from a stream (0x49acd0). */
struct Stream {
    int Read(void *buffer, int size);
};

extern int DAT_0057ca30;
extern int DAT_0057ca34;

void __cdecl AdvertisingPanel_Load(Stream *stream)
{
    stream->Read(&DAT_0057ca30, 4);
    stream->Read(&DAT_0057ca34, 4);
}
