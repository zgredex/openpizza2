/* BuildingValue_Load: deserializes the building value block (0x4e4440). */
struct IStream {
};

struct CRT {
    void Istream_Read(void *data, unsigned int size);
};

struct BuildingValue {
    char pad0[8];
    int field8;
    int fieldc;
    double field10;
    int field18;
    unsigned char field1c;

    void Load(IStream *stream);
};

void BuildingValue::Load(IStream *stream)
{
    CRT *crt = (CRT *)stream;

    crt->Istream_Read(&fieldc, 4);
    crt->Istream_Read(&field8, 4);
    crt->Istream_Read(&field10, 8);
    crt->Istream_Read(&field18, 4);
    crt->Istream_Read(&field1c, 1);
}
