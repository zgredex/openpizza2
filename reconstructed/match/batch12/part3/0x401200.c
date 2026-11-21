/* StatsPeriodReport_Save (0x401200). */

struct OStream {
    void CRT_Ostream_Write(void *buffer, int size);
};

struct StatsPeriodReport {
    void Save(void *stream);
};

void StatsPeriodReport::Save(void *stream)
{
    ((struct OStream *)stream)->CRT_Ostream_Write((char *)this + 0x10, 0x68);
    ((struct OStream *)stream)->CRT_Ostream_Write((char *)this + 0x78, 100);
    ((struct OStream *)stream)->CRT_Ostream_Write((char *)this + 0xdc, 0x280);
    ((struct OStream *)stream)->CRT_Ostream_Write((char *)this + 4, 4);
    ((struct OStream *)stream)->CRT_Ostream_Write((char *)this + 0xc, 4);
    ((struct OStream *)stream)->CRT_Ostream_Write((char *)this + 8, 4);
}
