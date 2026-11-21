/* WarehouseProduct_Save - 0x4c0d60, 17 bytes */
struct CRT_OStream
{
    void Write(void *src, int size);
};

extern char DAT_0057d714;

void WarehouseProduct_Save(CRT_OStream *stream)
{
    stream->Write(&DAT_0057d714, 4);
}
