/* BuildingValue_Save: serializes the building value block (0x4e43f0). */
struct OStream {
};

struct CRT {
    void Ostream_Write(void *data, unsigned int size);
};

struct BuildingValue {
    char pad0[8];
    int field8;
    int fieldc;
    double field10;
    int field18;
    unsigned char field1c;

    void Save(OStream *stream);
};

void BuildingValue::Save(OStream *stream)
{
    CRT *crt = (CRT *)stream;

    crt->Ostream_Write(&fieldc, 4);
    crt->Ostream_Write(&field8, 4);
    crt->Ostream_Write(&field10, 8);
    crt->Ostream_Write(&field18, 4);
    crt->Ostream_Write(&field1c, 1);
}
