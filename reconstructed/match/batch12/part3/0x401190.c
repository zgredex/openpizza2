/* StatsPeriodReport_Load (0x401190). */

struct IStream {
    void CRT_Istream_Read(void *buffer, int size);
};

struct StatsPeriodReport {
    void Load(void *stream);
};

void StatsPeriodReport::Load(void *stream)
{
    ((struct IStream *)stream)->CRT_Istream_Read((char *)this + 0x10, 0x68);
    ((struct IStream *)stream)->CRT_Istream_Read((char *)this + 0x78, 100);
    ((struct IStream *)stream)->CRT_Istream_Read((char *)this + 0xdc, 0x280);
    ((struct IStream *)stream)->CRT_Istream_Read((char *)this + 4, 4);
    ((struct IStream *)stream)->CRT_Istream_Read((char *)this + 0xc, 4);
    ((struct IStream *)stream)->CRT_Istream_Read((char *)this + 8, 4);
}
