/* AdvertisingPanel_Save: writes the two panel fields to a stream (0x49ad00). */
struct Stream {
    int Write(void *buffer, int size);
};

extern int DAT_0057ca30;
extern int DAT_0057ca34;

void __cdecl AdvertisingPanel_Save(Stream *stream)
{
    stream->Write(&DAT_0057ca30, 4);
    stream->Write(&DAT_0057ca34, 4);
}
