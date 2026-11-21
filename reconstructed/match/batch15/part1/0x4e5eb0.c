/* ConstructionOrder_Load: reads a construction order from a stream (0x4e5eb0). */
struct Stream {
    void Read(void *data, int size);
};

struct ConstructionOrder {
    void Load(Stream *stream);
};

void ConstructionOrder::Load(Stream *stream)
{
    int *kind;

    stream->Read((char *)this + 4, 4);
    stream->Read((char *)this + 8, 4);
    stream->Read((char *)this + 0xc, 4);
    kind = (int *)((char *)this + 0x10);
    stream->Read((char *)this + 0x10, 4);
    stream->Read((char *)this + 0x14, 4);
    stream->Read((char *)this + 0x18, 4);
    stream->Read((char *)this + 0x1c, 4);
    stream->Read((char *)this + 0x20, 4);
    if (*kind <= 2) {
        *kind = 0;
    }
}
