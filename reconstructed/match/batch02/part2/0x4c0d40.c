/* WarehouseProduct_Load - 0x4c0d40, 17 bytes */
struct CRT_IStream
{
    void Read(void *dest, int size);
};

extern char DAT_0057d714;

void WarehouseProduct_Load(CRT_IStream *stream)
{
    stream->Read(&DAT_0057d714, 4);
}
