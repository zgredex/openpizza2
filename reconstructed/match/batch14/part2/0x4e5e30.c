/* ConstructionOrder_Save (0x4e5e30): writes a construction-order record to a
   save stream. */
struct CRT_Ostream {
    void Write(const void *data, unsigned int size);
};

struct ConstructionOrder {
    char pad[4];
    int field4;                /* 0x04 */
    int field8;                /* 0x08 */
    int fieldc;                /* 0x0c */
    int field10;               /* 0x10 */
    int field14;               /* 0x14 */
    int field18;               /* 0x18 */
    int field1c;               /* 0x1c */
    int field20;               /* 0x20 */
    void Save(CRT_Ostream *stream);
};

void ConstructionOrder::Save(CRT_Ostream *stream)
{
    stream->Write((char *)this + 4, 4);
    stream->Write((char *)this + 8, 4);
    stream->Write((char *)this + 0xc, 4);
    stream->Write((char *)this + 0x10, 4);
    stream->Write((char *)this + 0x14, 4);
    stream->Write((char *)this + 0x18, 4);
    stream->Write((char *)this + 0x1c, 4);
    stream->Write((char *)this + 0x20, 4);
}
